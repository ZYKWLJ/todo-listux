import os
import subprocess
import sys
import time
import re

# 配置部分
COMPILER = "gcc"
CFLAGS = ["-Wall", "-Wextra", "-O2", "-MMD", "-Iinclude"]  # 添加-MMD和-Iinclude
SOURCE_DIR = "src"
INCLUDE_DIR = "include"  # 头文件目录
BUILD_DIR = "build"
BIN_DIR = "bin"
EXECUTABLE = "tl"

def ensure_dirs():
    """确保所有需要的目录存在"""
    os.makedirs(BUILD_DIR, exist_ok=True)
    os.makedirs(BIN_DIR, exist_ok=True)
    os.makedirs(INCLUDE_DIR, exist_ok=True)

def get_source_files():
    """获取所有源文件（返回绝对路径）"""
    source_files = []
    for root, _, files in os.walk(SOURCE_DIR):
        for file in files:
            if file.endswith(".c"):
                source_files.append(os.path.abspath(os.path.join(root, file)))
    return source_files

def get_header_files():
    """获取所有头文件（返回绝对路径）"""
    header_files = []
    if os.path.exists(INCLUDE_DIR):
        for root, _, files in os.walk(INCLUDE_DIR):
            for file in files:
                if file.endswith(('.h', '.hpp')):
                    header_files.append(os.path.abspath(os.path.join(root, file)))
    return header_files

def parse_dep_file(dep_file):
    """解析GCC生成的依赖文件(.d)获取头文件依赖"""
    if not os.path.exists(dep_file):
        return []
    
    try:
        with open(dep_file, 'r', encoding='utf-8') as f:
            content = f.read()
            # 解析依赖关系
            deps = []
            for line in content.split('\n'):
                if ':' in line:
                    line_deps = line.split(':')[1].strip().split()
                    deps.extend([d for d in line_deps if d.endswith(('.h', '.hpp'))])
            return list(set(deps))  # 去重
    except Exception as e:
        print(f"Warning: Failed to parse {dep_file}: {str(e)}")
        return []

def get_source_dependencies(source_file, object_file):
    """获取源文件的所有依赖头文件"""
    dep_file = object_file[:-2] + '.d'  # .o -> .d
    deps = parse_dep_file(dep_file)
    
    # 转换为绝对路径
    abs_deps = []
    source_dir = os.path.dirname(source_file)
    for dep in deps:
        # 尝试在源文件目录和include目录查找
        for base_dir in [source_dir, INCLUDE_DIR]:
            abs_path = os.path.normpath(os.path.join(base_dir, dep))
            if os.path.exists(abs_path):
                abs_deps.append(abs_path)
                break
    
    return abs_deps

def needs_recompile(source_file, object_file):
    """
    检查是否需要重新编译
    返回True如果:
    1. 目标文件不存在
    2. 源文件比目标文件新
    3. 任何依赖的头文件比目标文件新
    """
    if not os.path.exists(object_file):
        return True
    
    src_time = os.path.getmtime(source_file)
    obj_time = os.path.getmtime(object_file)
    
    # 检查源文件是否更新
    if src_time > obj_time:
        return True
    
    # 检查头文件依赖是否更新
    for dep in get_source_dependencies(source_file, object_file):
        if os.path.exists(dep) and os.path.getmtime(dep) > obj_time:
            return True
    
    return False

def compile_file(source_file, object_file):
    """编译单个源文件"""
    # 确保目标目录存在
    os.makedirs(os.path.dirname(object_file), exist_ok=True)
    
    # 删除旧的.o和.d文件（如果存在）
    for ext in ['.o', '.d']:
        old_file = object_file[:-2] + ext
        if os.path.exists(old_file):
            os.remove(old_file)
    
    # 构造编译命令
    cmd = [COMPILER] + CFLAGS + ["-c", source_file, "-o", object_file]
    
    # 设置环境变量确保英文输出
    env = os.environ.copy()
    env["LC_ALL"] = "C"
    
    try:
        rel_path = os.path.relpath(source_file, SOURCE_DIR)
        print(f"[CC] {rel_path}")
        
        # 运行编译命令
        result = subprocess.run(
            cmd,
            check=True,
            stderr=subprocess.PIPE,
            stdout=subprocess.PIPE,
            universal_newlines=True,
            encoding='utf-8',
            errors='replace',
            env=env
        )
        
        # 输出警告信息
        if result.stderr:
            print(result.stderr)
        
        return True
    except subprocess.CalledProcessError as e:
        print(f"\nError compiling {os.path.relpath(source_file, SOURCE_DIR)}:")
        print(e.stderr)
        return False
    except Exception as e:
        print(f"\nUnexpected error compiling {source_file}:")
        print(str(e))
        return False

def link_executable(object_files):
    """链接生成可执行文件"""
    executable_path = os.path.join(BIN_DIR, EXECUTABLE)
    
    # 删除旧的可执行文件（如果存在）
    if os.path.exists(executable_path):
        os.remove(executable_path)
    
    print("\n[LD] Linking executable...")
    
    try:
        result = subprocess.run(
            [COMPILER] + object_files + ["-o", executable_path],
            check=True,
            stderr=subprocess.PIPE,
            universal_newlines=True,
            encoding='utf-8',
            errors='replace'
        )
        
        if result.stderr:
            print(result.stderr)
        
        # 显示生成的可执行文件路径
        exec_rel_path = os.path.relpath(executable_path, os.getcwd())
        print(f"\nCreated executable: {exec_rel_path}")
        return True
    except subprocess.CalledProcessError as e:
        print("\nLinking failed:")
        print(e.stderr)
        return False

def compile_project():
    """主编译流程"""
    start_time = time.time()
    ensure_dirs()
    
    # 获取源文件和初始化变量
    source_files = get_source_files()
    object_files = []
    compiled_count = 0
    success = True
    
    # 编译每个源文件
    for src_file in source_files:
        # 生成目标文件路径（保持src目录结构）
        rel_path = os.path.relpath(src_file, SOURCE_DIR)
        obj_file = os.path.join(BUILD_DIR, os.path.splitext(rel_path)[0] + ".o")
        
        # 检查是否需要重新编译
        if needs_recompile(src_file, obj_file):
            if compile_file(src_file, obj_file):
                compiled_count += 1
            else:
                success = False
                break
        else:
            print(f"[SKIP] {os.path.relpath(src_file, SOURCE_DIR)} (up to date)")
        
        object_files.append(obj_file)
    
    # 如果编译成功则进行链接
    if success and object_files:
        success = link_executable(object_files)
    
    # 输出统计信息
    total_time = time.time() - start_time
    print("\nCompilation summary:")
    print(f"  Total files:    {len(source_files)}")
    print(f"  Recompiled:     {compiled_count}")
    print(f"  Time elapsed:   {total_time:.2f} seconds")
    print(f"  Build status:   {'SUCCESS' if success else 'FAILED'}")
    
    return success

if __name__ == "__main__":
    # 添加彩色输出支持
    if sys.platform == "win32":
        os.system("color")
    
    # 运行编译流程
    if not compile_project():
        sys.exit(1)