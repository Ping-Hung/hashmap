# Variables and Macro setup
CC=gcc
FLAGS= -Wall -Werror -std=c2x -g
T_TARGET=hashmap_test
TARGET=hashmap

SRC := $(wildcard src/*.c)
TEST := $(wildcard tests/*.c)
HEADERS := $(wildcard include/*.h)
BUILD=build

VECHO=@echo

# build rules
all: $(TARGET) $(T_TARGET)
	$(VECHO) "both executables (hashmap application and test) are built."

$(TARGET): $(SRC)
	$(VECHO) "building hashmap executable..."
	$(CC) $(SRC) main.c $(FLAGS) -o $(BUILD)/$(TARGET)
	$(VECHO) "Done"

$(T_TARGET): $(SRC) $(TEST)
	$(VECHO) "building test runner..."
	$(CC) $(SRC) $(TEST) $(FLAGS) -o $(BUILD)/$(T_TARGET)
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
	rm -f $(BUILD)/$(TARGET) $(BUILD)/$(T_TARGET)

commit: format	# Depends on format (shall see format being executed before git commit -a
	$(VECHO) "committing all changes..."
	git add .
	git commit -a
	$(VECHO) "Done"

run: $(TARGET)
	./$(BUILD)/$(TARGET)

v_run: $(TARGET)
	valgrind -s --leak-check=full --track-origins=yes ./$(BUILD)/$(TARGET)

test: $(T_TARGET)
	./$(BUILD)/$(T_TARGET)

v_test: $(T_TARGET)
	valgrind -s --leak-check=full --track-origins=yes ./$(BUILD)/$(T_TARGET)
