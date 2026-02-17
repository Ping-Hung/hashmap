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


.PHONY: format clean commit run test v_run v_test
format:
	$(VECHO) "formatting all source files..."
	find . -regex '.*\.\(c\|h\)' \
	-not -path "./build/*" \
	-exec clang-format -i {} +
	$(VECHO) "Done"

clean:
	rm $(BUILD)/*

commit: format	# Depends on format (shall see format being executed before git commit -a
	$(VECHO) "committing all changes..."
	git commit -a
	$(VECHO) "Done"

run: $(TARGET)
	./$(TARGET)

v_run: $(TARGET)
	valgrind -s --leak-check=full --track-origins=yes ./$(TARGET)  

test: $(T_TARGET)
	./$(T_TARGET)

v_test: $(T_TARGET)
	valgrind -s --leak-check=full --track-origins=yes ./$(TARGET)
