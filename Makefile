COMPILER = g++
CFLAGS = -std=c++17 -Wall -Wextra -I./include
LDFLAGS = -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

SRC_DIR = src
BUILD_DIR = build

MAIN = $(SRC_DIR)/main.cpp
MODULES = $(SRC_DIR)/Renderer.cpp $(SRC_DIR)/Mesh.cpp $(SRC_DIR)/Shader.cpp
LIBMODULES = $(SRC_DIR)/glad.c

OUTPUT = $(BUILD_DIR)/opengl-tutorial

$(OUTPUT): $(MAIN) $(LIBMODULES) $(MODULES)
	@mkdir -p build
	@echo -n "Compiling program .. "
	@$(COMPILER) $(CFLAGS) -o $(OUTPUT) $^ $(LDFLAGS)
	@echo "done"

.PHONY: test clean

test: $(OUTPUT)
	@./$(OUTPUT)

clean:
	@echo -n "Cleaning directory .. "
	-@rm -rf $(OUTPUT_DIR)
	@echo "done"
