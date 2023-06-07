# Day 1 Assignments

## Compile

```
mkdir build
cd build/
cmake ..
make
```

## Run


### Quadratic

```
./solveQuadratic a b c
```
where `a`, `b`, and `c` correspond to
```
y = a * x * x + b * x + c
```

### Stress Transformation
```
./transformStress sigmaX sigmaY sigmaXY [theta] 
```
where `sigmaX`, `sigmaY`, and `sigmaXY` are the initial stress and `theta` is the rotation (in degrees). Inpute `theta` is option; if not included, stress rotation for every 10 degrees printed. 


### Pi

```
./pi N
```
where `n` is the number of steps
