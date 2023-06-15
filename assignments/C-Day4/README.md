# Day 4 Assignments

## Example 1: Compute Pi

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
where `N` is the number of processes. Use
```
time mpirun -n N ./pi
```
to compare the run time for different values of `N`.

> If on `Frontera`, start an `idev` session prior to running with `mpirun`. Or use `sbatch` with the provided `submit.sh`. 


## Example 2: Vector Norm

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

> If on `Frontera`, start an `idev` session prior to running with `mpirun`.
