# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -std=c++17 -g
LDFLAGS = 

# Define build and source directories
BUILD_DIR = build
SRC_DIR = src

# Find all main.cpp files in sections or subsections across all chapters
ALL_MAIN_FILES := $(wildcard $(SRC_DIR)/*/*/main.cpp $(SRC_DIR)/*/*/*/main.cpp)

# Convert source files to corresponding build targets with nested paths
BUILD_TARGETS := $(patsubst $(SRC_DIR)/%/main.cpp, $(BUILD_DIR)/%/main, $(ALL_MAIN_FILES))

# Default target to build all chapters, sections, and optional subsections
all: $(BUILD_TARGETS)

# Generalized build rule for nested directories with optional subsection
$(BUILD_DIR)/%/main: $(SRC_DIR)/%/main.cpp
	@mkdir -p $(@D) # Create the build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -target arm64-apple-macos -o $@ $< $(LDFLAGS)

# Run target with chapter, section, and optional subsection variables, input, and output
run: 
ifndef chapter
	$(error Chapter not specified. Usage: make run chapter=<chapter> section=<section> [subsection=<subsection>] [input=<input_file>] [output=<output_file>])
endif
ifndef section
	$(error Section not specified. Usage: make run chapter=<chapter> section=<section> [subsection=<subsection>] [input=<input_file>] [output=<output_file>])
endif
ifeq ($(subsection),)
	@echo "Running $(BUILD_DIR)/$(chapter)/$(section)/main"
	$(BUILD_DIR)/$(chapter)/$(section)/main $(if $(input), < $(input)) $(if $(output), > $(output))
else
	@echo "Running $(BUILD_DIR)/$(chapter)/$(section)/$(subsection)/main"
	$(BUILD_DIR)/$(chapter)/$(section)/$(subsection)/main $(if $(input), < $(input)) $(if $(output), > $(output))
endif

# Clean compiled objects
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
