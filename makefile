CC = gcc
EXE = bfc
DEV_C_FLAGS = -g -Wall
BUILD_DIR = ./build
C_FLAGS = $(DEV_C_FLAGS) -std=gnu18 -c
SOURCES=$(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,build/%.o,$(SOURCES))

all: $(EXE)

$(EXE): $(notdir $(OBJECTS))
	$(CC) $(DEV_C_FLAGS) $(OBJECTS) -o $@

%.o: src/%.c
	@mkdir -p $(BUILD_DIR)

	$(CC) $(C_FLAGS) $< -o $(BUILD_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXE)
