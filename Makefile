# Variables and Macro setup
CC=gcc
FLAGS= -Wall -Werror -std=c2x -g
T_TARGET=test
TARGET=hashmap


SRC := $(wildcard src/*.c)
TEST := $(wildcard tests/*.c)
HEADERS := $(wildcard include/*.h)
BUILD=build/

VECHO=@echo

# build rules
all: $(TARGET) $(T_TARGET)
	$(VECHO) "both executables (hashmap application and test) are built."

$(TARGET): $(SRC)
	$(VECHO) "building hashmap executable..."
	$(CC) $(SRC) main.c $(FLAGS) -o $(TARGET)
	$(VECHO) "Done"

$(T_TARGET): $(SRC) $(TEST)
	$(VECHO) "building test runner..."
	$(CC) $(SRC) $(TEST) $(FLAGS) -o $(T_TARGET)
	$(VECHO) "Done"

# automation rules
.PHONY: format clean commit run test v_run v_test
format:
	$(VECHO) "formatting all source files..."
	find . -regex '.*\.\(c\|h\)' \
	-not -path "./build/*" \
	-exec clang-format -i {} +
	$(VECHO) "Done"

clean:
	rm -f $(TARGET) $(T_TARGET)

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
	valgrind -s --leak-check=full --track-origins=yes ./$(T_TARGET)
