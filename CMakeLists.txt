# cmake_minimum_required(VERSION 3.15)

# # 项目设置
# project(main
#     VERSION 1.0
#     LANGUAGES C CXX
# )

# # 硬编码指定编译器路径
# set(CMAKE_C_COMPILER "D:/4environment/gcc/i686-14.2.0-release-mcf-dwarf-ucrt-rt_v12-rev2/mingw32/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "D:/4environment/gcc/i686-14.2.0-release-mcf-dwarf-ucrt-rt_v12-rev2/mingw32/bin/g++.exe")

# # 设置工具链路径
# set(MINGW_ROOT "D:/4environment/msys/mingw64")
# set(CMAKE_PREFIX_PATH "${MINGW_ROOT}")

# # ===== 可配置变量 =====
# set(TARGET_NAME tl)  # 只需改这里，所有地方自动生效
# # ======================

# # 设置可执行文件输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# # 递归查找所有源文件（如果不想用 GLOB_RECURSE，可以手动列出）
# file(GLOB_RECURSE SRC_LIST
#     "src/*.c"
#     "src/*/*.c"
# )

# # 添加可执行文件（使用变量 ${TARGET_NAME}）
# add_executable(${TARGET_NAME} ${SRC_LIST})

# # 添加头文件搜索路径（直接指定，避免递归查找）
# target_include_directories(${TARGET_NAME} PUBLIC
#     include/
#     # 可以添加更多路径，如 include/subdir/
# )

# # 直接链接 readline 和 rt（不检查是否存在）
# target_link_libraries(${TARGET_NAME} PRIVATE readline rt)

cmake_minimum_required(VERSION 3.15)

# 项目设置
project(main
    VERSION 1.0
    LANGUAGES C CXX
)

# 硬编码指定编译器路径
set(CMAKE_C_COMPILER "D:/4environment/gcc/i686-14.2.0-release-mcf-dwarf-ucrt-rt_v12-rev2/mingw32/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/4environment/gcc/i686-14.2.0-release-mcf-dwarf-ucrt-rt_v12-rev2/mingw32/bin/g++.exe")

include_directories(
    ${PROJECT_SOURCE_DIR}/include  # 替换为你的实际头文件目录
    ${PROJECT_SOURCE_DIR}/src/database
)

# 检查编译器是否存在
if(NOT EXISTS ${CMAKE_C_COMPILER})
    message(FATAL_ERROR "C compiler not found at ${CMAKE_C_COMPILER}")
endif()

if(NOT EXISTS ${CMAKE_CXX_COMPILER})
    message(FATAL_ERROR "C++ compiler not found at ${CMAKE_CXX_COMPILER}")
endif()

# 设置工具链路径
set(MINGW_ROOT "D:/4environment/msys/mingw64")
set(CMAKE_PREFIX_PATH "${MINGW_ROOT}")

# ===== 可配置变量 =====
set(TARGET_NAME tl)  # 只需改这里，所有地方自动生效
# ======================

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 递归查找所有源文件（如果不想用 GLOB_RECURSE，可以手动列出）
file(GLOB_RECURSE SRC_LIST
    "src/*.c"
    "src/*/*.c"
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