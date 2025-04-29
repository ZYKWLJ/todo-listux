# import os
# import subprocess
# import time

# # 源文件目录
# src_dir = r"D:\3software\todo-listux-1\todo-listux\src"
# bin_dir = r"D:\3software\todo-listux-1\todo-listux\bin"

# # 确保输出目录存在
# os.makedirs(bin_dir, exist_ok=True)

# # 收集所有 .c 文件
# c_files = []
# for root, dirs, files in os.walk(src_dir):
#     for file in files:
#         if file.endswith('.c'):
#             c_files.append(os.path.join(root, file).replace("\\", "/"))

# # 生成 gcc 命令
# output_path = os.path.join(bin_dir, "tl").replace("\\", "/")
# gcc_command = f"gcc {' '.join(c_files)} -o {output_path}"

# # 打印 gcc 命令
# print(gcc_command)

# # 记录开始时间
# start_time = time.time()

# # 执行 gcc 命令
# try:
#     result = subprocess.run(gcc_command, shell=True, check=True, text=True, capture_output=True)
#     print("编译成功！")
#     print("标准输出:", result.stdout)
# except subprocess.CalledProcessError as e:
#     print("编译失败！")
#     print("标准错误:", e.stderr)

# # 记录结束时间并计算编译时间
# end_time = time.time()
# compile_time = end_time - start_time
# print(f"编译耗时: {compile_time:.2f} 秒")


import os
import subprocess
import time
import sys

# 源文件目录
src_dir = r"D:\3software\todo-listux-1\todo-listux\src"
bin_dir = r"D:\3software\todo-listux-1\todo-listux\bin"

def compile_project():
    # 确保输出目录存在
    os.makedirs(bin_dir, exist_ok=True)

    # 收集所有 .c 文件
    c_files = []
    for root, dirs, files in os.walk(src_dir):
        for file in files:
            if file.endswith('.c'):
                c_files.append(os.path.join(root, file).replace("\\", "/"))

    if not c_files:
        print("错误: 没有找到任何 .c 源文件！")
        return False

    # 生成 gcc 命令
    output_path = os.path.join(bin_dir, "tl").replace("\\", "/")
    gcc_command = ["gcc"] + c_files + ["-o", output_path]

    # 打印 gcc 命令
    print("执行编译命令:")
    print(" ".join(gcc_command))

    # 记录开始时间
    start_time = time.time()

    # 执行 gcc 命令
    try:
        # 使用 UTF-8 编码并忽略无法解码的字符
        result = subprocess.run(
            gcc_command,
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            encoding='utf-8',
            errors='ignore'
        )
        
        print("\n编译成功！")
        if result.stdout:
            print("标准输出:", result.stdout)
        return True
        
    except subprocess.CalledProcessError as e:
        print("\n编译失败！")
        if e.stderr:
            print("错误信息:")
            print(e.stderr)
        return False
        
    finally:
        # 记录结束时间并计算编译时间
        end_time = time.time()
        compile_time = end_time - start_time
        print(f"编译耗时: {compile_time:.2f} 秒")

if __name__ == "__main__":
    # 在 Windows 上设置控制台编码为 UTF-8
    if sys.platform == "win32":
        os.system("chcp 65001 > nul")
    
    success = compile_project()
    sys.exit(0 if success else 1)