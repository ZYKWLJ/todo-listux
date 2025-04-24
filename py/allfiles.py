import os


def combine_files(source_dirs, output_file):
    try:
        with open(output_file, 'w') as outfile:
            for source_dir in source_dirs:
                for root, dirs, files in os.walk(source_dir):
                    for file in files:
                        file_path = os.path.join(root, file)
                        try:
                            with open(file_path, 'r') as infile:
                                content = infile.read()
                                outfile.write(f"--- File: {file_path} ---\n")
                                outfile.write(content)
                                outfile.write("\n\n")
                        except Exception as e:
                            print(f"Error reading {file_path}: {e}")
    except Exception as e:
        print(f"Error writing to {output_file}: {e}")


source_dirs = ['/home/eyk/1code/todo-listux/include/', '/home/eyk/1code/todo-listux/src/']
output_file = '/home/eyk/1code/todo-listux/py/allfiles.txt'
combine_files(source_dirs, output_file)
    