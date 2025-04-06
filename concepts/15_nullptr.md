# Nullptr

> Since C++11

`nullptr ` is a keyword that denotes a pointer literal and is of type 
`std::nullptr_t`

```cpp
#include <iostream>

void foo(int) {
    std::cout << "int version\n";
}

void foo(char*) {
    std::cout << "char* version\n";
}

int main() {
    foo(nullptr);  // Calls the char* version
}
```

Unlike `0`, which could match both int and pointer overloads, nullptr is 
unambiguously a null pointer constant.

`std::nullptr_t` is implicitly convertible to any pointer type, but not to int.
That means:

1. `nullptr` can be converted to char* (so foo(char*) is valid).
2. `nullptr` cannot be converted to int (so foo(int) is not a match).

So the compiler picks foo(char*).

**however**

if there is clause with a close type match then the compiler will take the
closest to the type.

3. if we add

```cpp
void test(void*) {
    std::cout << "void*\n";
}
```
then `void*` will be printed.

4. and if we also add this:

```cpp
void test(std::nullptr_t) {
    std::cout << "nullptr_t\n";
}
```

then `nullptr_t` will be printed.
