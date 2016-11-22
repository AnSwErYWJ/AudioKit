# 当前目录找不到依赖/目标文件时,去指定路径查找
VPATH ?= ~/Desktop/DogFood/C/audio_tools:.

SRC := channel_separate.c
ALL_SRC := $(SRC) buffer.c
OBJS := $(ALL_SRC:.c=.o) # 加了:前面的变量不能使用后面的变量
TARGET := $(SRC:.c= )

CC := gcc
PLUS := g++
RM := -rm -rf # -表示命令出错.继续执行,忽略错误.
CPPFLAGS := -I ./# C预处理参数,一般设置I
CFLAGS := -Wall -O2 -m64 -D_GNU_SOURCE # 编译器参数,C使用
CXXFLAGS := # C++使用
LDFLAGS :=  # 链接器参数,如ld ,最好放在源文件之后.

.PHONY: all

all: 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ALL_SRC) $(LDFLAGS) -o $(TARGET)

.PHONY: clean 
clean:
	$(RM) $(TARGET) $(OBJS)
