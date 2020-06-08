# DepKit Compiler

[![language](https://img.shields.io/badge/C%2B%2B-17-blue)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![license](https://img.shields.io/badge/license-MIT-green)](https://opensource.org/licenses/MIT)

DepKit is a typed language for advanced package management. This project implements a DepKit compiler.

If you are not familiar with the grammar of DepKit, you can start [here](). Or you can read the [examples](https://github.com/vbcpascal/depkit/tree/master/examples) here, for the syntax of DepKit is very simple.

## Build

DepKit needs some dependencies: [RE-flex](https://www.genivia.com/doc/reflex/html/index.html), [bison](https://www.gnu.org/software/bison/), [z3](https://github.com/Z3Prover/z3) and [docopt](https://github.com/docopt/docopt.cpp). You can visit their pages for more details.

After installing these tools, you can try to compile our project.

To generate `lever.hpp`, `lever.cpp`, `parser.hpp`, `parser.cpp` and `location.hh` generated by RE-flex and bison, you should run

``` bash
make bison
make lex
```

Then use cmake to compile the project. I did not intergrate the above work into cmake (because i'm lazy). Remember to change the path in `CMakeLists.txt` (because i'm lazy).

``` bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

``` 
/* Definitions */

LLVM [
  version: {9.0, 10.0};
  feature: {gold, debug, z3};
  backend: {AArch-64, RISC-V};
] = ()

z3 [
  version: {4.8, 4.7, 3.5};
  feature: {debug};
  backend: {AArch-64, RISC-V};
] = ()

%%

/* Dependencies */

LLVM : {
  require (z3 in feature || version < 10.0);
  if z3 in feature {
    z3  
  }
  if z3 in feature && debug in feature {
    debug in z3.feature
  }
}

%%

/* Requirements */

LLVM [
  version: {10.0};
  feature: {z3};
  backend: {};
]
```

This is an example of DepKit. Save this as `example.dk`. Then compile this file by

```
./depkit example.dk
```

You will get

```
LLVM 10.0
  features: z3 [ gold ]
  backends: [ AArch-64 RISC-V ]
z3 4.8
  features: [ ]
  backends: [ AArch-64 RISC-V ]
```

This gives you the package you want to install and the corresponding version. The features and backends in `[]` means that it is an optional feature or backend. However, it should be noted that this does not mean that you can install them freely, you need to add them to the constraints and recompile to ensure that no conflicts will occur.

You can also output the result to a file with option `--output`. Use `./depkit --help` for details.

## Contributors

[Zhichao Guan](https://github.com/vbcpascal) and [Pengcheng Xu](https://github.com/KireinaHoro/) designed this for [Design Principles of Programming language](https://xiongyingfei.github.io/DPPL/2020/main.htm).