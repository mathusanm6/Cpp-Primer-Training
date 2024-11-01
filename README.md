# C++ Primer Training Project

This repository contains C++ code samples that I wrote while working through the _C++ Primer_ book. Each example represents a concept or experiment as I test and learn different features in C++. The code is structured in chapters and sections, and I’ve implemented a Makefile to simplify building and running each example.

### Prerequisites

- **Compiler**: This project uses `clang++` as the C++ compiler, compatible with C++17 standard.
- **Environment**: macOS with an ARM chip.
- **Tools**: `Make` for build automation.

### Project Structure

- **Source Code**: All source files are organized under the `src/` directory. Code is organized by chapter, section, and optional subsections, mirroring the structure of the book.
- **Build Directory**: Compiled binaries are saved in the `build/` directory, preserving the chapter and section structure.

```
src/
├── chapter1/
│   ├── section1/
│   │   └── main.cpp
│   ├── section2/
│   └── ...
└── chapter2/
    └── section1/
build/
├── chapter1/
│   ├── section1/
│   │   └── main
│   ├── section2/
│   └── ...
└── chapter2/
    └── section1/
```

### Building the Project

To compile all examples in the project, simply run:

```bash
make
```

This will find all `main.cpp` files in the `src/` directory and compile them into corresponding binaries in the `build/` directory.

### Running a Specific Example

To run a specific example, use the `make run` command with `chapter` and `section` parameters. Optionally, you can add a `subsection` parameter if the code is nested further. You can also specify optional input and output files to feed input or redirect output as needed.

```bash
make run chapter=<chapter> section=<section> [subsection=<subsection>] < input_file > output_file
```

For example, to run the code in `src/chapter1/section1/main.cpp`:

```bash
make run chapter=chapter1 section=section1
```

If there’s a subsection, specify it as well:

```bash
make run chapter=chapter1 section=section1 subsection=subsection1
```

You can also provide an input file and/or an output file to redirect the program’s input and output:

```bash
make run chapter=chapter1 section=section1 < data.txt > result.txt
```

### Cleaning Up

To remove all compiled binaries, run:

```bash
make clean
```

This will delete the `build/` directory and all its contents.

### Notes

- This project is purely for my learning and understanding as I work through the _C++ Primer_ book. It is not intended for collaborative development.
- The code here serves as a reference for testing different approaches and outcomes.
