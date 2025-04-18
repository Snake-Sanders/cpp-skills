# Nullptr

> Since C++11

`nullptr` is a keyword that denotes a pointer literal and is of type
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

1. `nullptr` can be converted to char*(so foo(char*) is valid).
2. `nullptr` cannot be converted to int (so foo(int) is not a match).

So the compiler picks foo(char*).

however:

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

then `nullptr_t` will be printed
=======

Before C++11, NULL was just 0, which could cause issues. Now, we use nullptr

```cpp
int* ptr1 = NULL;   // Old way (NULL is just 0)
int* ptr2 = nullptr; // New way (nullptr has proper pointer type)
```

With NULL, the compiler might call the wrong function. nullptr avoids confusion.

```cpp
void foo(int x) { std::cout << "int\n"; }
void foo(int* x) { std::cout << "pointer\n"; }

int main() {
    foo(NULL);    // Calls foo(int), but this is confusing!
    foo(nullptr); // Calls foo(int*)
}
```

```cpp
void* buffer = nullptr;

if (buffer == nullptr) {
    // Allocate memory or handle error
}
```

```cpp
```

```cpp
```
