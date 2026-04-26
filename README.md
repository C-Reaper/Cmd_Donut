# Project README

## Overview
This project is a simple implementation of a 3D donut visualization in the terminal using C and GCC. The visualization updates in real-time, creating an animated effect.

## Features
- Real-time 3D donut visualization
- ASCII art rendering in terminal
- Supports multiple build configurations (Linux, Windows, Wine, WebAssembly)

## Project Structure
```
Cmd_Donut/
├── build/              # .exe files produced by Main.c
├── src/                # source code directory
│   ├── Main.c          # Entry point file
└── Makefile.linux      # Linux Build configuration
└── Makefile.windows    # Windows Build configuration
└── Makefile.wine       # Wine Build configuration
└── Makefile.web        # Emscripten Build configuration
└── README.md           # This file
└── LICENSE
└── .gitignore
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run
- **Build Process:**
  - To build for Linux:
    ```sh
    make -f Makefile.linux all
    ```
  - To build for Windows:
    ```sh
    make -f Makefile.windows all
    ```
  - To build for Wine (for Windows on Linux):
    ```sh
    make -f Makefile.wine all
    ```
  - To build for WebAssembly (using Emscripten):
    ```sh
    make -f Makefile.web all
    ```

- **Execution:**
  - After building, you can run the executable using:
    ```sh
    make -f Makefile.(os) exe
    ```

These steps will ensure that the donut visualization is built and executed correctly based on your operating system.