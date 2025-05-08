cmake_minimum_required(VERSION 3.5)
project(my_project)  # 项目名（不影响目标名）

# ===== 可配置变量 =====
set(TARGET_NAME tl)  # 只需改这里，所有地方自动生效
# ======================

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 递归查找所有源文件（如果不想用 GLOB_RECURSE，可以手动列出）
file(GLOB_RECURSE SRC_LIST
    "src/*.c"
    "src/*/*.c"
    "test/*.c"
)

# 添加可执行文件（使用变量 ${TARGET_NAME}）
add_executable(${TARGET_NAME} ${SRC_LIST})

# 添加头文件搜索路径（直接指定，避免递归查找）
target_include_directories(${TARGET_NAME} PUBLIC
    include/
    # 可以添加更多路径，如 include/subdir/
)

# 直接链接 readline 和 rt（不检查是否存在）
target_link_libraries(${TARGET_NAME} PRIVATE readline rt)