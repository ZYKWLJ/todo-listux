import subprocess

# 定义命令行指令列表
commands = [
    "tl $ k=v",
    "tl + ddddd",
    "tl - 1",
    "tl / 1",
    "tl ~ 1",
    "tl ^ -w 2025.04.04",
    "tl ^ -week 2025.04.04",
    "tl ^ -d 2025.04.04",
    "tl ^ -day 2025.04.04",
    "tl ^ -m 2025.04.04",
    "tl ^ -month 2025.04",
    "tl ^ -month 2025",
    "tl ^ -y 2025",
    "tl ^ -year 2025",
    "tl = 1 new_content",
    "tl %= 1 new_content",
    "tl =% 1 new_content",
    "tl + content -w 2025.04.04",
    "tl - 1 -w 2025.04.04",
    "tl / 1 -w 2025.04.04",
    "tl ~ 1 -w 2025.04.04",
    "tl = 1 new_content -w 2025.04.04",
    "tl %= 1 new_content -w 2025.04.04",
    "tl =% 1 new_content -w 2025.04.04" , 
    "tl = 1 new_content -day 2025.04.04",
    "tl %= 1 new_content -day 2025.04.04",
    "tl =% 1 new_content -day 2025.04.04"
]


# 初始化正常通过和不通过的计数器
pass_count = 0
fail_count = 0
# 存储通过和不通过的命令
passed_commands = []
failed_commands = []

for command in commands:
    try:
        # 执行命令并捕获标准输出
        result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        output = result.stdout.strip()
        if output.endswith("execute passed!!"):
            pass_count += 1
            passed_commands.append(command)
        else:
            fail_count += 1
            failed_commands.append(command)
    except Exception as e:
        fail_count += 1
        failed_commands.append(command)

print(f"正常通过的样例数量: {pass_count}")
print("通过的命令如下:")
for cmd in passed_commands:
    print(f"  - {cmd}")

print(f"\n不通过的样例数量: {fail_count}")
print("不通过的命令如下:")
for cmd in failed_commands:
    print(f"  - {cmd}")