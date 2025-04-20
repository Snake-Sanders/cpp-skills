# Pointers

## Nullptr

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

## unique_ptr

Use `unique_ptr` in combined with `make_unique` instead of using `new`

```cpp
#include <memory>
// Declaring and defining a unique pointer
auto serial_number = std::make_unique<std::string>("123ABC");

// Unique pointers cannot be copied or assigned
auto another_serial = serial_number; // Error: Cannot copy a unique_ptr
```

## shared_ptr

`shared_ptr` is a smart pointer that allows multiple `shared_ptr` objects to
share ownership of the same resource

```cpp
#include <memory>
// Declaring and defining a shared pointer to a dynamically allocated string
auto device_status = std::make_shared<std::string>("status");

// Unique pointers cannot be copied or assigned
auto controller = device_status; 
auto logger = device_status; 
```

## Use smart pointers by default

Use `unique_ptr` for exclusive ownership and `shared_ptr` for shared ownership.

Reserve raw pointers for non-owning references or when interfacing with legacy
code.

In most cases, `unique_ptr` is sufficient for exclusive ownership,
as it offers lightweight memory management without the overhead of reference counting.

`shared_ptr` should be used sparingly, as it introduces overhead and
complexity unless true shared ownership is needed.

## Example

// power_of_troy.h

```cpp
#pragma once

#include <memory>
#include <string>

namespace troy {

struct artifact {
  // constructors needed (until C++20)
  artifact(std::string name) : name(name) {}
  std::string name;
};

struct power {
  // constructors needed (until C++20)
  power(std::string effect) : effect(effect) {}
  std::string effect;
};

struct human {
  human() {}

  std::unique_ptr<artifact> possession;
  std::shared_ptr<power> own_power;
  std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human &human, std::string name);
void exchange_artifacts(std::unique_ptr<artifact> &x,
                        std::unique_ptr<artifact> &y);
void manifest_power(human &human, std::string name);
void use_power(human &caster, human &target);
long power_intensity(human &human);

} // namespace troy
```

// power_of_troy.cpp

```cpp
#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human &human, std::string name) {
  human.possession = std::make_unique<artifact>(name);
}

void exchange_artifacts(std::unique_ptr<artifact> &x,
                        std::unique_ptr<artifact> &y) {
  x.swap(y);
}

void manifest_power(human &human, std::string name) {
  human.own_power = std::make_unique<power>(power(name));
}

void use_power(human &caster, human &target) {
  target.influenced_by = caster.own_power;
}

long power_intensity(human &human) { return human.own_power.use_count(); }
} // namespace troy

```

## Smart pointers comparison with Rust

|C++ | Rust|
|-|-|
|std::unique_ptr | Box<T> or default ownership |
|std::shared_ptr | Rc<T> / Arc<T> |
|Dereferencing *ptr | Same, *ref |
|std::move() | let x = y; (moves in Rust) |
|const T*vs T* | &T vs &mut T |
