import os


def add_headers_to_file(source_dir, target_file):
    try:
        with open(target_file, 'w') as f:
            for root, _, files in os.walk(source_dir):
                for file in files:
                    if file.endswith('.h'):
                        relative_path = os.path.join(os.path.relpath(root, source_dir), file)
                        f.write(f'#include "{relative_path}"\n')
        print(f"头文件已成功添加到 {target_file}")
    except Exception as e:
        print(f"发生错误: {e}")


source_directory = '/home/eyk/桌面/todo-listux/todo-listux/include'
target_file = '/home/eyk/桌面/todo-listux/todo-listux/include/include1.h'
add_headers_to_file(source_directory, target_file)
    