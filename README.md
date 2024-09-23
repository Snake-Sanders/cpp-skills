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

## Functions

### Function parameters

* Default arguments

1. all params can be optional
2. optional params must be at the end of the list

```c
int create_user(uint age = 18);
int create_user(uint age = 18, uint score = 0);
int create_user(uint id, uint score = 0);
```

* Arrays arguments 

```c
void temperatures(int [] values, int length);
```

* References arguments 

```c
void inc_reference(int &value) { value++; }

int main(void){
    int day = 20;
    inc_reference(day);
}
```

* Pointer arguments 

```c
void inc_pointer(int *value) { (*value)++; }

int main(void){
    int day = 20;
    inc_pointer(&day);
}
```

## Pointers

```cpp
int day = 29;
int* pDay = &day;

cout "Value of day is: " *pDay << endl;
// 29
*pDay = 30;
cout "Value of day is: " *pDay << endl;
// 30
```
