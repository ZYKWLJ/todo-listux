import os
import subprocess

# 源文件目录
src_dir = r"D:\3software\todo-listux-1\todo-listux\src"
bin_dir = r"D:\3software\todo-listux-1\todo-listux\bin"

# 确保输出目录存在
os.makedirs(bin_dir, exist_ok=True)

# 收集所有 .c 文件
c_files = []
for root, dirs, files in os.walk(src_dir):
    for file in files:
        if file.endswith('.c'):
            c_files.append(os.path.join(root, file).replace("\\", "/"))

# 生成 gcc 命令
output_path = os.path.join(bin_dir, "tl").replace("\\", "/")
gcc_command = f"gcc {' '.join(c_files)} -o {output_path}"

# 打印 gcc 命令
print(gcc_command)

# 执行 gcc 命令
try:
    result = subprocess.run(gcc_command, shell=True, check=True, text=True, capture_output=True)
    print("编译成功！")
    print("标准输出:", result.stdout)
except subprocess.CalledProcessError as e:
    print("编译失败！")
    print("标准错误:", e.stderr)