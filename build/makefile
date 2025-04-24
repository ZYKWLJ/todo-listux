# 编译器设置（Windows MinGW）
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude -std=c11
LDFLAGS := 

# 目录设置（Windows格式）
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
EXECUTABLE := todo-listux.exe

# 使用find命令获取源文件（Windows兼容方式）
SOURCES := $(shell cmd /c "dir /b /s src\\*.c 2>nul")

# 转换为目标文件路径
OBJECTS := $(patsubst $(SRC_DIR)\\%.c,$(BUILD_DIR)\\%.o,$(SOURCES))

# 主目标
all: $(BIN_DIR)\\$(EXECUTABLE)

# 链接可执行文件
$(BIN_DIR)\\$(EXECUTABLE): $(OBJECTS)
	@if not exist "$(subst /,\,$(BIN_DIR))" mkdir "$(subst /,\,$(BIN_DIR))"
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# 编译规则
$(BUILD_DIR)\\%.o: $(SRC_DIR)\\%.c
	@if not exist "$(subst /,\,$(@D))" mkdir "$(subst /,\,$(@D))"
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	@if exist "$(subst /,\,$(BUILD_DIR))" rmdir /s /q "$(subst /,\,$(BUILD_DIR))"
	@if exist "$(subst /,\,$(BIN_DIR))\\$(EXECUTABLE)" del /q "$(subst /,\,$(BIN_DIR))\\$(EXECUTABLE)"

.PHONY: all clean