# Day 4 Assignments

## Example 1

### Compile
```
mkdir build
cd build/
cmake ..
make 
```

### Run
```
mpirun -n N ./pi
```
where `N` is the number of processes and `M` is the size of the vector. Use
```
time mpirun -n N ./pi
```
to compare the run time for different values of `N`.

> If on `Frontera`, then start an `idev` session prior to running. 


## Example 2

### Compile
```
mkdir build
cd build/
cmake ..
make 
```

### Run
```
mpirun -n N ./dotproduct M
```
where `N` is the number of processes and `M` is the size of the vector.

> If on `Frontera`, then start an `idev` session prior to running. 
