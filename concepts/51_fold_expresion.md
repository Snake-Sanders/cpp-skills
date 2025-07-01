# Fold Expresion

## Fold Expression Formula

```cpp
// C++17 Fold Expression Syntax:
( pack op ... )           // Unary right fold
( ... op pack )           // Unary left fold  
( pack op ... op init )   // Binary right fold
( init op ... op pack )   // Binary left fold
```

Where:

- `pack` = parameter pack
- `op` = binary operator (+, -, *, &&, ||, etc.)
- `init` = initial value
- `...` = fold operator

## Examples

**Basic Sum (Unary Right Fold):**

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Expands to: a1 + (a2 + (a3 + a4))
}

// Usage:
auto result = sum(1, 2, 3, 4, 5);  // Returns 15
```

**Logical AND (Unary Left Fold):**

```cpp
template<typename... Args>
bool all_true(Args... args) {
    return (... && args);  // Expands to: ((a1 && a2) && a3) && a4
}

// Usage:
bool result = all_true(true, true, false, true);  // Returns false
```

**Print with Separator (Binary Left Fold):**

```cpp
template<typename... Args>
void print(Args... args) {
    ((std::cout << args << " "), ...);  // Comma operator
}

// Usage:
print("Hello", 42, 3.14, "World");  // Prints: Hello 42 3.14 World
```

**Sum with Initial Value (Binary Right Fold):**

```cpp
template<typename... Args>
auto sum_with_init(Args... args) {
    return (args + ... + 0);  // Expands to: a1 + (a2 + (a3 + 0))
}
```

The fold expression eliminates the need for recursive template implementations
for variadic operations.
