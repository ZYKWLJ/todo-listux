import os
import subprocess


def run_command(command, cwd=None):
    try:
        result = subprocess.run(command, shell=True, cwd=cwd, check=True, text=True, capture_output=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"执行命令出错: {e.stderr}")


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    build_dir = os.path.join(script_dir, "../build")
    bin_dir = os.path.join(script_dir, "../bin")
    # 执行rm -rf *
    cmake_command = "rm -rf *"
    run_command(cmake_command, cwd=build_dir)

    # 执行cmake
    cmake_command = "cmake .."
    run_command(cmake_command, cwd=build_dir)

    # 执行make
    make_command = "make"
    run_command(make_command, cwd=build_dir)

    # # 执行./main
    # main_command = "./main"
    # run_command(main_command, cwd=bin_dir)


if __name__ == "__main__":
    main()