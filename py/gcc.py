import os
import subprocess
import sys
import json
import time
from datetime import datetime

# 配置部分
COMPILER = "gcc"
CFLAGS = ["-Wall", "-Wextra", "-O2"]
SOURCE_DIR = "src"
BUILD_DIR = "build"
BIN_DIR = "bin"
CACHE_FILE = os.path.join(BUILD_DIR, "compile_cache.json")

def ensure_dirs():
    """确保所有需要的目录存在"""
    os.makedirs(BUILD_DIR, exist_ok=True)
    os.makedirs(BIN_DIR, exist_ok=True)

def load_cache():
    """加载编译缓存"""
    if not os.path.exists(CACHE_FILE):
        return {}
    
    try:
        with open(CACHE_FILE, "r") as f:
            return json.load(f)
    except (json.JSONDecodeError, IOError):
        return {}

def save_cache(cache):
    """保存编译缓存"""
    try:
        with open(CACHE_FILE, "w") as f:
            json.dump(cache, f, indent=2)
    except IOError:
        print("Warning: Failed to save cache file")

def get_source_files():
    """获取所有源文件"""
    source_files = []
    for root, _, files in os.walk(SOURCE_DIR):
        for file in files:
            if file.endswith(".c"):
                source_files.append(os.path.join(root, file))
    return source_files

def needs_compile(source_file, object_file):
    """
    基于修改时间的编译检查
    返回True如果:
    1. 目标文件不存在
    2. 源文件比目标文件新
    3. 依赖的头文件比目标文件新(需要实现头文件依赖分析)
    """
    if not os.path.exists(object_file):
        return True
    
    # 获取文件修改时间
    try:
        src_mtime = os.path.getmtime(source_file)
        obj_mtime = os.path.getmtime(object_file)
    except OSError:
        return True
    
    # 基本规则：源文件比目标文件新
    if src_mtime > obj_mtime:
        return True
    
    # TODO: 可以添加头文件依赖检查
    # 例如：if any_header_newer_than_object(source_file, object_file)
    
    return False

def compile_file(source_file, object_file, cache):
    """编译单个源文件"""
    cmd = [COMPILER] + CFLAGS + ["-c", source_file, "-o", object_file]
    
    try:
        print(f"Compiling {os.path.relpath(source_file, SOURCE_DIR)}")
        result = subprocess.run(cmd, check=True, 
                              stderr=subprocess.PIPE,
                              universal_newlines=True)
        
        # 更新缓存记录
        cache[source_file] = {
            "last_modified": os.path.getmtime(source_file),
            "last_compiled": time.time(),
            "object_file": object_file
        }
        
        if result.stderr:
            print(result.stderr)
        
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error compiling {source_file}:")
        print(e.stderr)
        return False

def link_executable(object_files):
    """链接生成可执行文件"""
    executable = os.path.join(BIN_DIR, "tl")
    cmd = [COMPILER] + object_files + ["-o", executable]
    
    print("\nLinking executable...")
    try:
        result = subprocess.run(cmd, check=True,
                              stderr=subprocess.PIPE,
                              universal_newlines=True)
        
        if result.stderr:
            print(result.stderr)
        
        print(f"Created {os.path.relpath(executable, os.getcwd())}")
        return True
    except subprocess.CalledProcessError as e:
        print("Linking failed:")
        print(e.stderr)
        return False

def compile_project():
    """主编译流程"""
    start_time = time.time()
    ensure_dirs()
    
    # 加载缓存和源文件
    cache = load_cache()
    source_files = get_source_files()
    object_files = []
    compiled_files = 0
    
    # 编译每个源文件
    for src in source_files:
        # 生成目标文件路径
        rel_path = os.path.relpath(src, SOURCE_DIR)
        obj = os.path.join(BUILD_DIR, os.path.splitext(rel_path)[0] + ".o")
        os.makedirs(os.path.dirname(obj), exist_ok=True)
        
        # 检查是否需要编译
        if needs_compile(src, obj):
            if not compile_file(src, obj, cache):
                return False
            compiled_files += 1
        else:
            print(f"Skipping {os.path.relpath(src, SOURCE_DIR)} (up to date)")
        
        object_files.append(obj)
    
    # 保存缓存并链接
    save_cache(cache)
    
    if not link_executable(object_files):
        return False
    
    # 输出统计信息
    total_time = time.time() - start_time
    print(f"\nCompilation complete. {compiled_files}/{len(source_files)} files compiled.")
    print(f"Total time: {total_time:.2f} seconds")
    
    return True

if __name__ == "__main__":
    if not compile_project():
        sys.exit(1)