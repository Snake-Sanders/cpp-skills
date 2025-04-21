# Sort

```cpp
#include <vector>
#include <algorithm>

std::vector<int> nums = {4, 1, 5, 2, 3};
std::sort(nums.begin(), nums.end());  // Default: ascending

// Result: 1 2 3 4 5
```

using custom comparator (lampda)

```cpp
std::sort(nums.begin(), nums.end(), [](int a, int b) {
    return a > b;  // reverse order
});
```

## Sorting Structs

```cpp
struct User {
    std::string name;
    int age;
};

std::vector<User> users = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

// sort by age
std::sort(users.begin(), users.end(), [](const User& a, const User& b) {
    return a.age < b.age;
});

// sort by name
std::sort(users.begin(), users.end(), [](const User& a, const User& b) {
    return a.name < b.name;
});

```
