import os

# 源文件目录
src_dir = r"D:\3software\todo-listux\src"

# 收集所有 .c 文件
c_files = []
for root, dirs, files in os.walk(src_dir):
    for file in files:
        if file.endswith('.c'):
            c_files.append(os.path.join(root, file).replace("\\", "/"))

# 生成 gcc 命令
gcc_command = f"gcc {' '.join(c_files)} -o tl"

# 打印 gcc 命令
print(gcc_command)
    