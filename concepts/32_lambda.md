# Lampda

```cpp
auto sayHi = []() {
    std::cout << "Hello, world!\n";
};

sayHi();  // prints "Hello, world!"
```

* `[]` → capture clause (what variables it captures from the surrounding scope)
* `()` → parameter list
* `{}` → function body

* with parameters

```cpp
auto add = [](int a, int b) {
    return a + b;
};

int result = add(2, 3);  // 5
```

* capture variables

```cpp
int x = 10;
auto showX = [x]() {
    std::cout << "x = " << x << "\n";
};

showX();  // prints "x = 10"
```

* capture reference

```cpp
int y = 5;
auto increaseY = [&y]() {
    y += 1;
};

increaseY();
std::cout << y;  // prints 6
```

* inline with `sort`

```cpp
std::vector<int> nums = {5, 1, 4, 2, 3};

std::sort(nums.begin(), nums.end(), [](int a, int b) {
    return a > b;  // descending
});
```

* with specific return type

Return types are usually inferred, but you can specify one explicitly
(especially useful in more complex lambdas).

```cpp
auto multiply = [](double x, double y) -> double {
    return x * y;
};
```

* mutable lambda

mutable allows modifying captured-by-value variables inside the lambda
— but it doesn’t affect the original.

```cpp
int counter = 0;

auto count = [counter]() mutable {
    counter++;
    std::cout << "Inside lambda: " << counter << "\n";
};

count();  // prints 1
count();  // prints 2
std::cout << "Outside: " << counter << "\n";  // still 0!
```

* generic lambda

```cpp
auto print = [](auto value) {
    std::cout << value << "\n";
};

print(42);
print("hello");
print(3.14);
```

* lambda as function argument

```cpp
void runTwice(const std::function<void()>& f) {
    f();
    f();
}

runTwice([]() {
    std::cout << "Running!\n";
});
```

* with sdt::transform

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output(input.size());

    std::transform(input.begin(), input.end(), output.begin(), [](int x) {
        return x * x;
    });

    for (int n : output)
        std::cout << n << " ";  // Output: 1 4 9 16 25
}
```

Convert Strings to Uppercase

```cpp
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

int main() {
    std::string word = "hello";

    std::transform(word.begin(), word.end(), word.begin(), [](char c) {
        return std::toupper(c);
    });

    std::cout << word;  // Output: HELLO
}
```

* find_if with lambda

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 3, 5, 8, 11};

    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });

    if (it != numbers.end())
        std::cout << "First even: " << *it << "\n";  // Output: 8
    else
        std::cout << "No even number found.\n";
}
```
find user by name

```cpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

struct User {
    std::string name;
    int age;
};

int main() {
    std::vector<User> users = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    std::string searchName = "Bob";

    auto it = std::find_if(users.begin(), users.end(), [&searchName](const User& u) {
        return u.name == searchName;
    });

    if (it != users.end())
        std::cout << "Found user: " << it->name << ", " << it->age << "\n";
    else
        std::cout << "User not found.\n";
}
```
