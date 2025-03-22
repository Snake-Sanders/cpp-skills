# Auto

Instead of explicitly writing types, auto lets the compiler deduce them

```cpp
auto x = 42;     // x is an int
auto y = 3.14;   // y is a double
auto z = 'A';    // z is a char
```

Avoids type mismatches and makes iteration easier to read

```cpp
int data[] = {10, 20, 30, 40};  

for (auto value : data) {  
    // No need to specify int, `auto` deduces the type
    process(value);  // Imagine this function does something with sensor data
}
```

Ensures pointers have the correct type without manually specifying them

```cpp
int* ptr = nullptr;  
auto p = ptr;  // p is automatically an int*
```

Prevents hardcoded types and makes code more portable across different architectures.

```cpp
volatile uint32_t REG = 0xDEADBEEF;  

auto reg_value = REG;  // reg_value is automatically uint32_t

```

## Exercise

Find the Error: Auto and References

```cpp
#include <iostream>

int getValue() {
    static int value = 42;
    return value;
}

int main() {
    auto x = getValue();  // What is x’s type?
    x = 99;               // Does this modify getValue()'s value?

    std::cout << "getValue() returns: " << getValue() << '\n';
}

```

1. What type does auto x get?

2. Does changing x modify the original value inside getValue()?

**Results**

1. getValue() returns a static int, but it returns it by value (not by reference).
    auto x = getValue(); deduces x as an int (not static int).
    So, x is just a regular integer, independent of getValue()'s value.

2. x gets modified because it is of type `int`.

the compiler won’t throw an error! The issue is logical, not syntactical—
the program compiles fine but behaves unexpectedly


If we actually want x to refer to value, we need a reference:

```cpp
auto& x = getValue();  // Now x is an int& (reference to static int)
x = 99;                // Modifies value inside getValue()
// Now, getValue() will return 99 after the modification.
```

Another example:
```cpp
const auto& x = getValue();
x = 99;  // ERROR: x is a const reference!
```


