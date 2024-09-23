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
void inc_reference(int& value) { value++; }

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
void inc_pointer(int* value) { (*value)++; }

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

## Static Member Functions vs. Non-static Member Functions

| Feature                       | Static Member Function                    | Non-static Member Function             |
|-------------------------------|-------------------------------------------|----------------------------------------|
| Belongs to                    | Class itself                              | Individual instances of the class      |
| Accessed by                   | `ClassName::functionName()`               | `instance.functionName()`              |
| Has `this` pointer            | No                                        | Yes                                    |
| Can modify instance members   | No (can only access static members)       | Yes (can modify non-static members)    |
| Example usage                 | `Example::getVersion()`                   | `exampleInstance.getName()`            |

### Example

```cpp
class Example {
public:
    // Static member function
    static string getVersion() {
        return "1.0";
    }

    // Const member function
    string getName() const {
        return name;
    }

    // Non-const member function
    void setName(const string& newName) {
        name = newName;
    }
};
```

call with
```cpp
int main() {
    const Example example; // `example` is a constant instance
    example.getName();     // Allowed because `getName` is a const function
    example.setName("New"); // Not allowed on a const instance
    string version = Example::getVersion(); // does not require an instance
    }
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

## Conditions

Since C++17 if-statements can also include a short initialization statement
that can be used to initialize one or more variables for the if statement.

For example:

```cpp
int num{7};

if (int v{2 * num}; v > 10) {
    return v;
} else {
    return num;
}
// => 14
```

Note: Any variables created in the initialization cannot be accessed after the end of the if statement.

## Casting

```cpp
static_cast<int>(3.14); // 3
```

## Collections

```cpp
#include <string>
#include <array>
#include <vector>

// arrays have fix size
std::array<std::string, 3> fruits {"apple", "pear", "tomato"};

// vectors have dynamic size
std::vector<int> lucky_numbers {22, 32, 17};

// vectors and array have the same access functions

lucky_number[0]; // 22
lucky_number.at(0); // 22
lucky_number.empty(); // false
lucky_number.size(); // 3
lucky_number.front(); // 22
lucky_number.back(); // 17

// modifiers
fruits[0] = "cherry"; // {"cherry", "pear", "tomato"}

lucky_number.pop_back(); // removes 17
lucky_number.emplace_back(18); // adds 18
```

## References

### Arrays and Pointers

https://www.xitalogy.com/programming/2019/08/15/a-tour-of-cpp-arrays-pointers-and-references-under-the-hood.html
