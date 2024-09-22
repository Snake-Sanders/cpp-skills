## Compile the examples

### Compile with c++

Compile the example as:

`c++ file_name.cpp -o file_name`

Run with:

`./file_name`

**Example:**

`c++ pointer1.cpp -o pointer1`
`./pointer`


### Comple with CMake

```
cd build
cmake ..
make
```

Run with:

`./app`

## Pointers

```cpp
int day = 29;
int* pDay = &day;
```
