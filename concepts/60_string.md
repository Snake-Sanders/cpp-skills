# String

## Creation

```cpp
#include <string>

std::string s1 = "Hello";
std::string s2("World");
std::string s3(5, '!');  // "!!!!!"

// C++14
using namespace std::string_literals;

std::string s4 = "Hi"s;  // Makes a std::string directly
```

## Concatenation

```cpp
std::string name = "Alice";
std::string greeting = "Hello, " + name + "!";

std::string str = "C++";
str += "14";
str.append(" is nice");

// C++14
using namespace std::string_literals;

std::string result = "Pi is around "s + std::to_string(3.14);
```

## Interpolation

C++20 add [std::format](https://en.cppreference.com/w/cpp/utility/format/format)
like in Rust.

C++14 doesn't have native interpolation (like Python's f"Hello {name}"),
but you can fake it with a few patterns.

```cpp
#include <sstream>

int age = 30;
std::string name = "Bob";

std::ostringstream oss;
oss << "Name: " << name << ", Age: " << age;
std::string info = oss.str();
```

```cpp
int score = 95;
std::string result = "Score: " + std::to_string(score);
```
