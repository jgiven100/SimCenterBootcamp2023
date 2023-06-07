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
where `sigmaX`, `sigmaY`, and `sigmaXY` are the initial stress and `theta` is the rotation (in degrees). The `theta` input is optional; if not included, stress rotation printed for `0<=theta<360` with `delta_theta=10`. 


### Pi

```
./pi N
```
where `N` is the number of steps
