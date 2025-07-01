# Digit Separators

## Digit Separators Formula

```cpp
// C++14 Digit Separators Syntax:
number'separator'number

// Rules:
// - Use single quote (') as separator
// - Cannot start or end with separator
// - Cannot have consecutive separators
// - Works with all numeric literals (decimal, binary, octal, hex)
```

## Example

**Before C++14:**

```cpp
long population = 7800000000;        // Hard to read
int binary_val = 0b11010010101010;   // Hard to parse
unsigned hex_val = 0xDEADBEEF;       // This one's actually readable
```

**C++14 with digit separators:**

```cpp
long population = 7'800'000'000;         // 7.8 billion - much clearer
int binary_val = 0b1101'0010'1010'1010;  // Grouped by nibbles
unsigned hex_val = 0xDEAD'BEEF;          // Even more readable
double pi = 3.141'592'653;               // Works with decimals too

// Different grouping styles:
int million = 1'000'000;      // Thousands
int million2 = 10'00'000;     // Indian numbering (lakh)
long big_num = 123'456'789'012'345LL;
```

**Key Points:**

- Purely cosmetic - doesn't affect the actual value
- Ignored by compiler during compilation
- Improves code readability for large numbers
- Particularly useful for bit patterns, large constants, and financial calculations
- Can be used anywhere in the number (except first/last position)

The separators make numeric literals much easier to read and verify at a glance.
