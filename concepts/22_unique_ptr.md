# Unique and Shared pointers

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
