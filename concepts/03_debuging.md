# Debugging

For now the easiest way to debug C++ when not
working on cross compiler is VSCODE.

## Getting started

- Reference

Most probably this configuration won't work at first but it is good starting
point.

<https://code.visualstudio.com/docs/cpp/config-clang-mac>

## configuration

Here's a summary of the steps I took to set up C++ debugging in VS Code/Cursor
for macOS:

### Initial Problem Identification

- Debugger wasn't stopping at breakpoints
- Step over/into commands weren't working
- Variables panel was stuck on "loading"
- Multiple lldb-mi processes were running

### Configuration Files Created/Modified

`.vscode/tasks.json:`

```json
   {
     "tasks": [
       {
         "type": "cppbuild",
         "label": "C/C++: clang++ build active file",
         "command": "/usr/bin/clang++",
         "args": [
           "-fcolor-diagnostics",
           "-fansi-escape-codes",
           "-g3",        // Enhanced debug information
           "-O0",        // No optimization
           "-std=c++17", // C++ standard
           "main.cpp",
           "nucleotide_count.cpp",
           "-o",
           "${workspaceFolder}/nucleotide_count"
         ],
         "options": {
           "cwd": "${workspaceFolder}"
         },
         "problemMatcher": ["$gcc"],
         "group": {
           "kind": "build",
           "isDefault": true
         }
       }
     ]
   }
```

`.vscode/launch.json`

```json
   {
     "configurations": [
       {
         "name": "Debug C++ Program",
         "type": "cppdbg",
         "request": "launch",
         "program": "${workspaceFolder}/nucleotide_count",
         "args": [],
         "stopAtEntry": false,
         "cwd": "${workspaceFolder}",
         "environment": [],
         "externalConsole": false,
         "MIMode": "lldb",
         "preLaunchTask": "C/C++: clang++ build active file",
         "setupCommands": [
           {
             "description": "Enable pretty-printing for gdb",
             "text": "-enable-pretty-printing",
             "ignoreFailures": true
           }
         ]
       }
     ]
   }
```

### Key Configuration Points

- Used -g3 for maximum debug information
- Set -O0 to disable optimizations that can interfere with debugging
- Explicitly specified C++17 standard
- Configured to build all necessary source files
- Set up proper working directory paths
- Enabled pretty-printing for better variable display

### Troubleshooting Steps

- If multiple lldb processes are running: pkill -9 lldb-mi
- If configuration gets corrupted: Close and reopen VS Code/Cursor
- If debugging doesn't start: Check that the build task completed successfully

### Common Issues and Solutions

- If asked to attach to a process: Check that request is set to "launch" not "attach"
- If variables aren't showing: Ensure -g3 is in compiler flags
- If stepping doesn't work: Make sure -O0 is set to disable optimizations
- If breakpoints aren't hit: Verify the executable was built with debug symbols
