import os


def count_lines_in_file(file_path):
    """
    统计单个文件的代码行数
    :param file_path: 文件路径
    :return: 代码行数
    """
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            return len([line for line in lines if line.strip() and not line.strip().startswith('//')])
    except Exception as e:
        print(f"读取文件 {file_path} 时出错: {e}")
        return 0


def count_lines_in_directory(directory):
    """
    递归统计目录下所有 .c 和 .h 文件的代码行数
    :param directory: 目录路径
    :return: .c 文件总行数, .h 文件总行数
    """
    c_total_lines = 0
    h_total_lines = 0
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                lines = count_lines_in_file(file_path)
                c_total_lines += lines
                # print(f"{file_path}: {lines} 行")
            elif file.endswith('.h'):
                file_path = os.path.join(root, file)
                lines = count_lines_in_file(file_path)
                h_total_lines += lines
                # print(f"{file_path}: {lines} 行")
    return c_total_lines, h_total_lines


if __name__ == "__main__":
    directory = r"/home/eyk/桌面/TL/"
    c_lines, h_lines = count_lines_in_directory(directory)
    print(f".c 文件: {c_lines}")
    print(f".h 文件: {h_lines}")
    