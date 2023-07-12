# Matrices
## Description: 
This root folder will contain all the files pertaining to the matrix section of the DSA course.

Note: This folder will be run a bit differently than the previous folders. I have now realized I need a central place where I can add matrix functionality, instead of copying matrixAdt.c and matrixAdt.h to each folder but then expanding it and making it different each time.

Therefore, the way the important functionality will be in:
```
├── include
│   ├── arrayAdt.h
│   └── matrixAdt.h
└── src
    ├── arrayAdt.c
    └── matrixAdt.c
```

And then the numbered folders such as 143_diagMatrix will follow along with the concepts taught in the course and implement the said functionality. 

All the programs can be built at once. The way you do this is you make the build folder in this folder. I.e., in linux bash:
```
git clone https://github.com/jbates35/algtraining
cd ./algtraining/9_matrices/
mkdir build
cd build
cmake ..
make
```

You will then get a tree that looks somewhat like:
```
├── 143_diagMatrix
│   ├── CMakeFiles
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── diagMatrix.dir
│   │   │   ├── DependInfo.cmake
│   │   │   ├── __
│   │   │   │   └── src
│   │   │   │       ├── arrayAdt.c.o
│   │   │   │       ├── arrayAdt.c.o.d
│   │   │   │       ├── matrixAdt.c.o
│   │   │   │       └── matrixAdt.c.o.d
│   │   │   ├── build.make
│   │   │   ├── cmake_clean.cmake
│   │   │   ├── compiler_depend.make
│   │   │   ├── compiler_depend.ts
│   │   │   ├── depend.make
│   │   │   ├── flags.make
│   │   │   ├── link.txt
│   │   │   ├── main.c.o
│   │   │   ├── main.c.o.d
│   │   │   └── progress.make
│   │   └── progress.marks
│   ├── Makefile
│   ├── cmake_install.cmake
│   └── diagMatrix
├── CMakeCache.txt
├── CMakeFiles
│   ├── 3.22.1
│   │   ├── CMakeCCompiler.cmake
│   │   ├── CMakeCXXCompiler.cmake
│   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   ├── CMakeSystem.cmake
│   │   ├── CompilerIdC
│   │   │   ├── CMakeCCompilerId.c
│   │   │   ├── a.out
│   │   │   └── tmp
│   │   └── CompilerIdCXX
│   │       ├── CMakeCXXCompilerId.cpp
│   │       ├── a.out
│   │       └── tmp
│   ├── CMakeDirectoryInformation.cmake
│   ├── CMakeOutput.log
│   ├── CMakeTmp
│   ├── Makefile.cmake
│   ├── Makefile2
│   ├── TargetDirectories.txt
│   ├── cmake.check_cache
│   ├── progress.marks
│   └── utils.dir
│       ├── DependInfo.cmake
│       ├── build.make
│       ├── cmake_clean.cmake
│       ├── cmake_clean_target.cmake
│       ├── compiler_depend.make
│       ├── compiler_depend.ts
│       ├── depend.make
│       ├── flags.make
│       ├── link.txt
│       ├── progress.make
│       └── src
│           ├── arrayAdt.c.o
│           ├── arrayAdt.c.o.d
│           ├── matrixAdt.c.o
│           └── matrixAdt.c.o.d
├── Makefile
├── cmake_install.cmake
├── compile_commands.json
└── libutils.a
```

Honestly, not much of this matters. But what does matter is the program executables associated with the lessons. I.e., from here you'd go:
```
cd 143_diagMatrix
./diagMatrix -x "1 3 6 2 8"
```

For particular instructions on how to run each program, I will have a README.md in each project folder that will explain which options/parameters to pass to run the function.