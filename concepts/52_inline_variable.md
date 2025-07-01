# Inline variables

## Inline Variables Formula

```cpp
// C++17 Inline Variables Syntax:
inline type variable_name = value;

// In header files:
inline constexpr type variable_name = value;  // Common pattern
```

## Example

**Before C++17 (problematic):**

```cpp
// header.h
extern const int max_connections;  // Declaration

// source.cpp  
const int max_connections = 100;   // Definition - needed in .cpp file
```

**C++17 with inline variables:**

```cpp
// header.h
inline const int max_connections = 100;  // Definition directly in header

// Can be used across multiple translation units without linking errors
// Multiple includes of this header won't cause "multiple definition" errors
```

**Common Pattern - Static Class Members:**

```cpp
class Config {
public:
    inline static const std::string default_path = "/etc/config";
    inline static constexpr int timeout = 5000;
    
    // Before C++17, you needed separate definition in .cpp file
    // Now can be defined directly in class
};
```

**Key Benefits:**

- Eliminates need for separate `.cpp` definitions
- Variables can be defined in headers without ODR violations
- Particularly useful for `constexpr` variables and static class members
- Each translation unit gets the same instance (like inline functions)

The `inline` keyword tells the linker it's okay to see multiple definitions as
long as they're identical.
