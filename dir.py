import os

# dir='/home/eyk/桌面/TL/'

directories = ['bin', 'build', 'include', 'py', 'src', 'test']

for directory in directories:
    try:
        os.makedirs(directory, exist_ok=True)
        print(f"成功创建目录: {directory}")
    except FileExistsError:
        print(f"目录 {directory} 已存在。")
    except Exception as e:
        print(f"创建目录 {directory} 时出错: {e}")    