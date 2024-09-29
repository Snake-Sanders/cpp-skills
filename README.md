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
example with read only and return references
``` c
void inc_reference(const int &value, int& result) {
    result = value + 1;
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


int month = 11;
const int *pMonth_a = &month;
// Error: month value can't be changed, it is const int
//*pMonth_a = 12;

const int *const pMonth_b = &month;
const int holliday = 6;
// Error: the pointer cannot be reassigned
// pMonth_b = &holliday; 
```

## References

* a reference must be initialized to a variable at declaration
```cpp
int age = 30;
int& age_ref = age;
const int& read_only = age;

// cannot assign this reference, the reference type must match its variable  
// it should be const int& user_age
//int& user_age = read_only;
```

A reference, doesn’t act as a separate object or variable. 
It is more like a direct alias to the original variable. 
In most cases, the compiler manages this using pointers under the hood, 
but it is abstracted away so that the reference behaves just like the original 
variable. 
Conceptual representation:
`int* const my_ref = &age;` 

## Dynamic Allocation

* single allocation and deallocation
* when multiple pointers reference one memory allocation, only one should call 
`delete`. Dealocating more than once will cause an error.

```cpp
int* pDay = new int;
*pDay = 9;
delete pDay;
```

* allocation and deallocation of multiple elements

```cpp
int* lottery = new int[6];
delete[] lotery;
```

* differences between array on stack and on heap
```cpp
// allocation of 10 integers on stack
int years[10];

// allocation of 10 pointers to integers on stack
int *pYears[10];

// allocate 10 ints in heap and assing the address to the pointer
pYears = new int [10];

// deallocating 10 int memory
delete[] pYears;

```

