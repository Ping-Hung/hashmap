# Variables and Macro setup
CC=gcc
FLAGS= -Wall -Werror -std=c2x -g
T_TARGET=test
TARGET=hashmap

SRC=src/*.c
HEADERS=include/*.h
TEST=tests/*.c
BUILD=build/

VECHO=@echo

# build rules
all:
	$(VECHO) "building final target..."


format:
	$(VECHO) "fromatting all source files..."
	find . -regex '.*\.\(c\|h\)' \
	-not -path "./build/*" \
	-exec clang-format -i {} +

	

.PHONY: clean format
