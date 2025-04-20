# Concepts

## Priorities

### Essential Modern C++ Features (Focus on These First)

- Core Language Features
  - auto keyword
  - Range-based for loops
  - Lambda expressions
  - Smart pointers (unique_ptr, shared_ptr)
  - Move semantics (basic understanding)
  - nullptr instead of NULL
  - override and final keywords

### STL Basics

- std::vector, std::array
- std::string, std::string_view
- Basic algorithms (std::find, std::sort)
- std::optional

### Memory Management

- RAII principles
- Smart pointer usage
- Basic memory safety practices

### Good to Know (Second Priority)

- Concurrency
  - std::thread basics
  - Mutexes and locks
  - Basic async operations
- Modern Container Usage
  - std::unordered_map/set
  - std::array vs C arrays

### Usually Not Required (Unless Specifically Needed)

- Advanced Features
  - Template metaprogramming
  - Perfect forwarding
  - SFINAE
  - Concepts (C++20)
  - Coroutines
  - Complex compile-time programming

### Real-World Focus Areas for Embedded/Robotics

- Performance Critical
  - Understanding memory layout
  - Cache-friendly code
  - Real-time constraints
  - Zero-cost abstractions

### Hardware Interaction

- Bit manipulation
- Register access
- Interrupt handling
- DMA operations

### Job Market Reality

- Most embedded roles use a subset of C++
- Focus is on reliability and maintainability
- Many projects use C++11/14 features, fewer use C++17/20
- Style guides often restrict language feature usage (like Google's or MISRA)

### Practical Approach

- Start With
  - Learn the "Essential" features listed above
  - Focus on writing clean, maintainable code
  - Understand embedded-specific constraints

- Then Add
  - Features as needed for specific projects
  - Performance optimization techniques
  - Platform-specific requirements
- Project-Based Learning
  - Build small embedded projects
  - Focus on real hardware interaction
  - Practice with common microcontrollers

- Red Flags in Learning
  - Don't get caught in feature completeness
  - Avoid premature optimization
  - Don't use complex features just because they exist
  - Stay away from "clever" code that's hard to maintain

## General Concepts

### 1. **Core C++ Concepts**

- **Object-Oriented Programming (OOP)**
  - Explain **polymorphism**, **inheritance**, **encapsulation**, and **abstraction**.
  - What is a **virtual function**, and how does it work?
  - What is the difference between **abstract classes** and **interfaces** in
  C++?
  - How does **multiple inheritance** work in C++? What problems can arise
  (e.g., the **diamond problem**), and how can you avoid them?
  
- **Memory Management**
  - What is the difference between **stack** and **heap** memory?
  - Explain **smart pointers** (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`).
  - How does C++ handle **destructors**? What is the **rule of three**, and
  what is the **rule of five**?
  - What are the implications of **manual memory management** in C++ compared
  to other languages?

- **Const and Static**
  - What does `const` mean when used in various contexts (e.g., **const
  variables**, **const methods**)?
  - Explain the use of `static` in C++ (e.g., **static variables**,
  **static methods**, and **static objects**).
  
- **References vs Pointers**
  - What’s the difference between a **pointer** and a **reference**?
  - Explain **pointer arithmetic** and how it works.

- **Templates and Generic Programming**
  - What are **templates** in C++? How are they different from **macros**?
  - Explain **template specialization** and **template metaprogramming**.
  - What is **SFINAE** (Substitution Failure Is Not An Error) in C++?

- **Function call**
  - How is the function call and return process.

### 2. **Advanced C++ Concepts**

- **Concurrency and Multithreading**
  - How do you create **threads** in C++? Explain **std::thread**.
  - What are **mutexes**, and how do they help in thread synchronization?
  - Explain **condition variables** and how they are used for thread communication.
  - How do **atomic operations** work in C++?

- **Move Semantics**
  - Explain **move semantics** and how they differ from copy semantics.
  - What is an **rvalue reference** and how does it enable **move semantics**?
  - Explain the importance of `std::move()` and `std::forward()`.

- **Lambda Expressions**
  - What are **lambda functions** in C++? How do you capture variables?
  - How do you use **lambdas** with **STL algorithms**?

### 3. **Standard Template Library (STL)**

- **Common Containers**
  - What is the difference between **vector**, **list**, **deque**, **map**,
  and **set**?
  - How do **iterators** work with STL containers?
  - What is the time complexity of operations like `insert`, `find`, and
  `erase` for **map** and **set**?

- **Algorithms**
  - How do you use STL algorithms like `std::sort`, `std::find`, `std::accumulate`?
  - Explain how **lambda expressions** work with algorithms in C++.

- **Exception Handling**
  - How does C++ handle **exceptions**?
  - What are **standard exceptions** in C++ (e.g., `std::bad_alloc`,
  `std::out_of_range`)?
  - What’s the difference between **try-catch blocks** and using
  **error codes** for error handling?

### 4. **Code Optimization**

- **Time Complexity**
  - How do you evaluate the **time complexity** of a program?
  - What are some ways to **optimize** C++ code for performance?

- **Memory Optimization**
  - How do you reduce memory overhead when working with large data structures?
  - What is the role of **cache locality**, and how can you write
  cache-friendly code?

### 5. **System Design & Problem Solving**

- **Design Patterns**
  - What are common **design patterns** in C++ (e.g., **Singleton**,
  **Factory**, **Observer**, **Strategy**)?
  - How would you implement a **singleton pattern** in C++?

- **Code Review & Best Practices**
  - What are some **best practices** for writing clean and maintainable C++ code?
  - How would you review code for **memory leaks**, **race conditions**, or
  **undefined behavior**?

### 6. **Common Coding Challenges**

- **String Manipulation**
  - Write a function to **reverse a string**.
  - Check if a string is a **palindrome**.
  
- **Linked Lists**
  - Implement a **singly linked list** and perform operations like insertion,
  deletion, and reversing a linked list.
  
- **Sorting Algorithms**
  - Implement **quick sort** or **merge sort** and explain their time complexity.
  
- **Binary Trees**
  - Write a function to **traverse a binary tree** (in-order, pre-order, post-order).
  - Find the **lowest common ancestor** (LCA) in a binary search tree.

- **Dynamic Programming**
  - Solve the **knapsack problem** or **longest common subsequence** using
  dynamic programming.

## Example code

- Examples:
<https://github.com/embeddedartistry/embedded-resources/tree/master/examples/cpp>
- Smartwatch Open source by PineTime. Pine64:
<https://github.com/InfiniTimeOrg/InfiniTime>

### Resources to Practice

1. **LeetCode** or **HackerRank**: For practicing algorithms and data
structures problems in C++.
2. **GeeksforGeeks**: A comprehensive resource for learning C++ concepts.
3. **Cppreference**: For official documentation and best practices regarding C++.
4. Using C++ in Embedded Superloop (Amazon drone). CppConf 2022
<https://www.youtube.com/watch?v=QwDUJYLCpxo>
5. ETL Embedded Template Library <https://www.etlcpp.com/home.html>
