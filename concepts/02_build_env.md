# Build environment

## Build Tools & Compilers

* make

What it is: A classic build tool.

Purpose: Uses a Makefile to define build rules.

Good for: Small to medium projects; it's fast and widely available.

* CMake

What it is: A build system generator (not a build system itself).

Purpose: Generates native build files (e.g., Makefile, Visual Studio projects).

Good for: Cross-platform projects, modern C++, managing dependencies.

Workflow:

Write a CMakeLists.txt.

Run cmake to generate a build system.

Use the generated system (e.g., make, ninja) to build.

* clang / clang++

What it is: A modern C/C++ compiler from the LLVM project.

Purpose: Compiles your code into binaries.

Benefits: Fast, great diagnostics, used in tooling (e.g., formatters, linters).

* g++

What it is: The GNU C++ compiler.

Purpose: The traditional C++ compiler on Linux.

Alternative to: clang++.

## Related / Supporting Tools

* ninja

What it is: A fast build system.

Works with: CMake can generate ninja build files.

Good for: Speedy incremental builds.

* ccache

What it is: A compiler cache.

Purpose: Speeds up rebuilds by caching previous compilation results.

* cmake-gui / ccmake

What it is: GUIs for configuring CMake projects.

Helpful for: Tweaking CMake options without editing files directly.

* conan / vcpkg

What they are: C++ package managers.

Purpose: Fetch and manage dependencies (libraries).

Helps with: Versioning, building 3rd-party libs, portability.

* clang-format / clang-tidy

What they are: Code style formatter and linter.

Good for: Keeping code clean, consistent, and bug-free.


