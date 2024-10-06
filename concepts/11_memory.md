# Memory management

## 1. Manual Memory Allocation (new and delete)
In C++, `new` is used to allocate memory on the heap dynamically, and `delete` 
is used to release that memory when it’s no longer needed. 
Failure to release memory results in memory leaks.

## 2. Stack vs Heap Memory
**Stack memory** is automatically managed (allocated and freed when variables go 
out of scope), and is generally faster but limited in size. 

**Heap memory** is manually managed and can store larger amounts of data, but 
requires explicit allocation and deallocation.

## 3. Smart Pointers (std::unique_ptr, std::shared_ptr)
Smart pointers, like `std::unique_ptr` and `std::shared_ptr`, manage dynamically
allocated memory automatically, ensuring that memory is freed when no longer 
needed, thus preventing memory leaks and dangling pointers.

## 4. RAII (Resource Acquisition Is Initialization)
RAII is a C++ idiom where resources like memory, file handles, or locks are 
tied to the lifespan of objects. 
This ensures that resources are acquired when an object is created and 
automatically released when the object goes out of scope.

## 5. Memory Leaks
A memory leak occurs when dynamically allocated memory is no longer referenced 
but hasn’t been freed, leading to wasted memory. Tools like Valgrind help in 
detecting such leaks in C++ programs.

## 6. Dangling Pointers
A dangling pointer arises when a pointer references memory that has been freed 
or deallocated. Using smart pointers or careful memory management prevents 
these unsafe pointers from causing crashes or undefined behavior.

## 7. Garbage Collection (No Built-in in C++)
C++ does not have automatic garbage collection like Java or Python, so 
developers must manage memory manually. However, smart pointers and RAII can 
simulate aspects of garbage collection by automatically managing resource lifetimes.

## 8. Memory Fragmentation
Memory fragmentation occurs when free memory is divided into small, 
non-contiguous blocks due to continuous allocation and deallocation, reducing 
the efficiency of memory usage on the heap. Allocators like pool allocators 
help mitigate this issue.

## 9. Placement new
Placement new allows the construction of an object at a specific memory address. It’s useful for custom memory management scenarios, like allocating memory from a pre-allocated buffer.

## 10. Memory Alignment
Memory alignment ensures that data is stored at addresses in memory that are suitable for the architecture. Misaligned memory access can lead to performance penalties or crashes, so C++ provides features like alignas to control alignment.

# Examples


## 10. Memory Alignment 
```cpp
struct alignas(32) sse_t
{
    float sse_data[4];
};
```
