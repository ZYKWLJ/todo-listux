#!/bin/bash

# 切换到指定目录
cd /home/eyk/桌面/todo-listux/todo-listux/build

# 删除当前目录下的所有文件和文件夹
rm -rf * 

# 运行cmake进行项目配置
cmake..

# 清屏
clear

# 编译项目
make    