# Day 2 Assignments

## Binary File

### Compile 
```
gcc file3.c
```

### Run 
```
./a.out name.txt name.dat
```
where `name` is either `small` or `big`. The output binary file may be checked with

```
$ wc small.dat
    1   2 160 small.dat
$ wc big.dat
    32   657 32000 big.dat
```
where `160` and `32000` are expected.

## Matrix Multiply

### Compile
```
mkdir build
cd build/
cmake ..
make
```

### Run
```
./matMul N
```
where `N` indicates an `N` by `N` matrix. Return of `0` means success. 

```
./benchmark
```
to compare Blas and naive code. 

## Stress Transform File
Not completed.

## Stress Transform Struct

### Compile
```
mkdir build
cd build/
cmake ..
make
```

### Run
```
./stressTransform
```



