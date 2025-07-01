## Pipe operator

C++ doesn't have built-in pipe operators like Elixir (`|>`) or Rust
(method chaining), but there are several functional approaches:

## Function Composition Approaches

**Manual Composition:**

```cpp
// Instead of: data |> func1 |> func2 |> func3
auto result = func3(func2(func1(data)));
```

**Method Chaining (fluent interface):**

```cpp
// Custom classes can support chaining
result = container.filter(pred).map(transform).reduce(accumulator);
```

**Range-based Libraries:**

- **C++20 Ranges:** Built-in functional composition
- **Range-v3:** Third-party library (pre-C++20)
- **Eric Niebler's ranges**

**Custom Pipe Implementation:**
You can implement pipe operators using operator overloading or template
metaprogramming.

## C++20 Ranges (Most Modern Approach)

```cpp
#include <ranges>
// Supports pipe-like syntax
auto result = data 
    | std::views::filter(predicate)
    | std::views::transform(mapper)
    | std::views::take(10);
```

## Functional Programming Features Available

- Lambdas (C++11)
- std::function (C++11)
- Algorithm library (transform, filter via copy_if, etc.)
- Fold expressions (C++17)
- constexpr functions
- Higher-order functions support

## Key Limitation

C++ prioritizes performance and zero-cost abstractions over syntactic
convenience, so the pipe syntax isn't as naturally integrated as in
functional-first languages. Most C++ functional programming relies on template
libraries or manual composition patterns.

The closest you get to true piping is C++20 ranges or third-party libraries
like Range-v3.
