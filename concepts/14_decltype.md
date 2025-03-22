# Decltype

> Since C++11

Decltype lets you get the exact type of an expression without evaluating it.

```cpp
int a = 10;
decltype(a) b = 20;  // b is also an int
```

```cpp
int x = 5;
decltype(x + 3.0) y;  // y is deduced as double (because 3.0 is double)
```

```cpp
int value = 42;
int& ref = value;

decltype(ref) anotherRef = value;  // anotherRef is an int& (reference)
anotherRef = 99;  // Modifies value
```

```cpp
int getNumber() { return 123; }

decltype(getNumber()) result;  // result is an int
```

## Exercise

Find the Error: decltype and References

```cpp
#include <iostream>

int main() {
    int a = 10;
    int& ref = a;  

    decltype(ref) x = 20;  // What type is x?

    std::cout << "a = " << a << ", x = " << x << '\n';
}
```

1. What type does decltype(ref) x become?
2. Does x = 20; modify a?
3. Will this code compile? If not, why?


**Results**

1. x is int&
2. Since x is an int& (a reference), it must be initialized with a variable, 
    not a literal. But 20 is a literal, not a variable!

# How decltype Works With and Without Parentheses

## decltype(x) (Without Parentheses)

If x is a variable or expression, decltype(x) gives you the exact type of x


```cpp
int a = 10;
decltype(a) b = 20;  // b is an int
// a is an int, so decltype(a) is just int.
```

## decltype((x)) (With Parentheses)

Now, when you add parentheses, things change!

decltype((x)) doesn’t just look at x, it looks at the expression (x).

Parentheses force the expression to be an `lvalue`, which affects how decltype works.

What is an lvalue?
Lvalue ("left value") = Something that has a memory address (like a variable).
Rvalue ("right value") = Temporary values (like literals or expressions).

```cpp
int a = 10;
decltype((a)) x = 20; // compile error
```
decltype((a)) treats (a) as an lvalue, so it deduces decltype((a)) as int&.
That means x is actually int& x = 20;, which is illegal because a reference cannot bind to a literal!


> Key Rules:
> 
> - If x is an lvalue, decltype((x)) always deduces T& (reference to T).
> - If x is an rvalue, decltype((x)) just deduces T.

> decltype(x) gives the type of x.
> decltype((x)) gives:
> - T& if x is an lvalue.
> - T if x is an rvalue.

## Example

Would it compile? If not, why?

```cpp
#include <iostream>

int main() {
    int a = 10;
    int& ref = a;  

    decltype((a)) x = 20;
```

**Results**

Parentheses matter in decltype((a))!
- decltype(a) → would be just int.
- decltype((a)) → (a) is an lvalue, so decltype((a)) is int& (a reference).
- x is now an int&, meaning it must be initialized with a variable.
- 20 is a literal, not a variable. This does NOT compile, just like before!

## Example 

```cpp
int a = 10;
decltype(a) x1 = a;   // x1 is an int
decltype((a)) x2 = a; // x2 is an int& (reference)
```

- decltype(a) → int (normal type deduction).
- decltype((a)) → int& (because (a) is an lvalue).


```cpp
int getValue() { return 42; }
decltype(getValue()) x = 100;
decltype((getValue())) y = getValue();
```

What are the types of x and y?

**Results**

getValue() returns an int (by value).
decltype(getValue()) gives us int, so x is just an int.

```cpp
int&& foo() { static int x = 10; return std::move(x); }
decltype(foo()) a = foo();
```
What is the type of a?

**Results**

foo() returns an int&& (rvalue reference).
Since std::move(x) converts x to an rvalue, the return type remains int&&
