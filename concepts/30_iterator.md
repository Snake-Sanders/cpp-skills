# Iterator

Example of update in place.

## Iterating on vectors

```cpp
#include <vector>
#include <iostream>

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    for (auto& num : nums) {
        if (isEven(num)) {
            num *= 10;  // Update if condition is true
        }
    }

    for (int n : nums) std::cout << n << " ";
    // Output: 1 20 3 40 5 60
}

```

## Iterating on maps

Iterating using key-value

```cpp
#include <map>
#include <iostream>

bool belowThreshold(int val) {
    return val < 50;
}

int main() {
    std::map<std::string, int> scores = {
        {"Alice", 45},
        {"Bob", 72},
        {"Charlie", 30}
    };

    for (auto& [name, score] : scores) {
        if (belowThreshold(score)) {
            score += 10;
        }
    }

    for (const auto& [name, score] : scores)
        std::cout << name << ": " << score << "\n";
    // Alice: 55, Bob: 72, Charlie: 40
}

```

How update iterator works.
The key detail is the `&` in auto &[names, score]. 
Here's what's happening:
The `&` creates a reference to each element in `scores`.
When using structured binding [names, score] with a reference, both names
becomes a reference to the actual vector in the map. Therefore,
`score += 10` directly modifies the value in the map - there's no need for an
implicit return.

If we wrote it without the &:
Then `score` would be a copy of the value, and `+=` would only modify the copy,
not the original value in the map.

## Iterator first and second

```cpp
std::map<Key, Value> m;
for (auto it = m.begin(); it != m.end(); ++it) {
    it->first   // Key (read-only!)
    it->second  // Value (read/write)
}
```
