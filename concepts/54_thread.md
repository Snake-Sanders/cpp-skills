# C++ Thread Support Library

## Overview
The C++ Thread Support Library (introduced in C++11) provides a standardized way to work with threads, synchronization primitives, and concurrent programming. It's part of the `<thread>` header and related headers.

## Basic Thread Syntax

### Thread Creation Formula
```cpp
#include <thread>

// Method 1: Function pointer
std::thread thread_name(function_name, arg1, arg2, ...);

// Method 2: Lambda expression
std::thread thread_name([](){ /* code */ });

// Method 3: Callable object
std::thread thread_name(callable_object, args...);

// Method 4: Member function
std::thread thread_name(&Class::method, &object, args...);
```

## Core Concepts

### 1. Basic Thread Operations
```cpp
#include <iostream>
#include <thread>
#include <chrono>

void worker_function(int id) {
    std::cout << "Thread " << id << " is working\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " finished\n";
}

int main() {
    // Create thread
    std::thread t1(worker_function, 1);
    
    // Wait for thread to complete
    t1.join();
    
    // Or detach thread (runs independently)
    std::thread t2(worker_function, 2);
    t2.detach();
    
    return 0;
}
```

### 2. Thread with Lambda
```cpp
#include <iostream>
#include <thread>
#include <vector>

int main() {
    std::vector<std::thread> threads;
    
    // Create multiple threads with lambda
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([i]() {
            std::cout << "Lambda thread " << i << " executing\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100 * i));
        });
    }
    
    // Join all threads
    for (auto& t : threads) {
        t.join();
    }
    
    return 0;
}
```

## Synchronization Primitives

### 3. Mutex (Mutual Exclusion)
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int shared_counter = 0;

void increment_counter(int thread_id) {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // RAII lock
        ++shared_counter;
        // lock automatically released when going out of scope
    }
    std::cout << "Thread " << thread_id << " finished\n";
}

int main() {
    std::vector<std::thread> threads;
    
    // Create 5 threads
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment_counter, i);
    }
    
    // Wait for all threads
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Final counter value: " << shared_counter << std::endl;
    return 0;
}
```

### 4. Condition Variable
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;
bool finished = false;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        data_queue.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one(); // Notify waiting consumer
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    std::lock_guard<std::mutex> lock(mtx);
    finished = true;
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait until data is available or finished
        cv.wait(lock, [] { return !data_queue.empty() || finished; });
        
        while (!data_queue.empty()) {
            int value = data_queue.front();
            data_queue.pop();
            std::cout << "Consumed: " << value << std::endl;
        }
        
        if (finished) break;
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);
    
    prod.join();
    cons.join();
    
    return 0;
}
```

### 5. Atomic Operations
```cpp
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> atomic_counter{0};
int regular_counter = 0;

void increment_atomic() {
    for (int i = 0; i < 1000; ++i) {
        ++atomic_counter; // Thread-safe without mutex
    }
}

void increment_regular() {
    for (int i = 0; i < 1000; ++i) {
        ++regular_counter; // NOT thread-safe
    }
}

int main() {
    std::vector<std::thread> threads;
    
    // Test atomic counter
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment_atomic);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Atomic counter: " << atomic_counter << std::endl; // Should be 5000
    
    // Test regular counter (race condition)
    threads.clear();
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(increment_regular);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Regular counter: " << regular_counter << std::endl; // Likely < 5000
    
    return 0;
}
```

### 6. Future and Promise
```cpp
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// Function that returns a value asynchronously
int calculate_something(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return x * x;
}

// Using promise/future for communication
void producer_with_promise(std::promise<int>&& promise) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promise.set_value(42); // Send result back
}

int main() {
    // Method 1: Using std::async
    std::cout << "Starting async calculation...\n";
    auto future_result = std::async(std::launch::async, calculate_something, 10);
    
    // Do other work while calculation runs
    std::cout << "Doing other work...\n";
    
    // Get the result (blocks if not ready)
    int result = future_result.get();
    std::cout << "Async result: " << result << std::endl;
    
    // Method 2: Using promise/future manually
    std::promise<int> promise;
    auto future = promise.get_future();
    
    std::thread t(producer_with_promise, std::move(promise));
    
    std::cout << "Waiting for promise result...\n";
    int promise_result = future.get();
    std::cout << "Promise result: " << promise_result << std::endl;
    
    t.join();
    
    return 0;
}
```

### 7. Thread Pool Example
```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop = false;

public:
    ThreadPool(size_t num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        
                        if (stop && tasks.empty()) return;
                        
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    
                    task();
                }
            });
        }
    }
    
    template<typename F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if (stop) return;
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one();
    }
    
    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        
        for (std::thread& worker : workers) {
            worker.join();
        }
    }
};

int main() {
    ThreadPool pool(4);
    
    // Add tasks to thread pool
    for (int i = 0; i < 10; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " executing on thread " 
                      << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }
    
    // ThreadPool destructor will wait for all tasks to complete
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    return 0;
}
```

## Key Thread Management Functions

### Thread Control
```cpp
// Get thread ID
std::thread::id thread_id = std::this_thread::get_id();

// Sleep current thread
std::this_thread::sleep_for(std::chrono::milliseconds(100));
std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));

// Yield execution to other threads
std::this_thread::yield();

// Get hardware concurrency
unsigned int num_cores = std::thread::hardware_concurrency();
```

## Memory Management and Crash Handling

### What Happens When a Detached Thread Crashes?

When a detached thread crashes (throws an unhandled exception), the behavior depends on the type of memory and resources:

```cpp
#include <iostream>
#include <thread>
#include <memory>
#include <stdexcept>

void dangerous_detached_function() {
    // Stack memory - automatically cleaned up when thread terminates
    int stack_variable = 42;
    
    // Heap memory - POTENTIAL LEAK if not properly managed
    int* heap_memory = new int(100);
    
    // RAII managed memory - automatically cleaned up
    std::unique_ptr<int> smart_ptr = std::make_unique<int>(200);
    
    // Simulate crash
    throw std::runtime_error("Thread crashed!");
    
    // This line never executes - heap_memory leaks!
    delete heap_memory; // Never reached
    
    // smart_ptr automatically cleaned up by destructor
}

void safe_detached_function() {
    try {
        // Use RAII for all resources
        std::unique_ptr<int> safe_memory = std::make_unique<int>(100);
        
        // Simulate potential crash
        throw std::runtime_error("Thread crashed!");
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception in detached thread: " << e.what() << std::endl;
        // Resources still cleaned up properly
    } catch (...) {
        std::cout << "Caught unknown exception in detached thread" << std::endl;
    }
}

int main() {
    std::cout << "=== Dangerous detached thread ===" << std::endl;
    std::thread dangerous_thread(dangerous_detached_function);
    dangerous_thread.detach(); // Memory leak when crashes!
    
    std::cout << "=== Safe detached thread ===" << std::endl;
    std::thread safe_thread(safe_detached_function);
    safe_thread.detach(); // Proper cleanup even when crashes
    
    // Give detached threads time to run
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    return 0;
}
```

### Memory Cleanup Rules for Detached Threads

| Memory Type | Cleanup Behavior | Notes |
|-------------|------------------|-------|
| **Stack memory** | ✅ Automatically cleaned | Thread stack is deallocated when thread terminates |
| **Heap memory (raw pointers)** | ❌ **POTENTIAL LEAK** | Must be manually freed or use RAII |
| **RAII objects** | ✅ Automatically cleaned | Destructors called during stack unwinding |
| **Thread-local storage** | ✅ Automatically cleaned | Cleaned up when thread terminates |
| **Shared resources** | ⚠️ **Depends on implementation** | May remain locked/corrupted |

### Exception Handling in Detached Threads

```cpp
#include <iostream>
#include <thread>
#include <exception>

// Global exception handler for threads
void thread_exception_handler() {
    try {
        std::rethrow_exception(std::current_exception());
    } catch (const std::exception& e) {
        std::cout << "Uncaught exception in thread: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown uncaught exception in thread" << std::endl;
    }
    
    // In a real application, you might want to:
    // - Log the error
    // - Signal the main thread
    // - Perform cleanup
    // - Restart the thread
}

void risky_thread_function() {
    // Set exception handler
    std::set_terminate(thread_exception_handler);
    
    try {
        // Your thread logic here
        throw std::runtime_error("Something went wrong!");
        
    } catch (const std::exception& e) {
        std::cout << "Handled exception: " << e.what() << std::endl;
        return; // Clean exit
    }
}

// Better approach: Exception-safe wrapper
template<typename F>
void safe_thread_wrapper(F&& func) {
    try {
        func();
    } catch (const std::exception& e) {
        std::cout << "Exception in thread: " << e.what() << std::endl;
        // Handle or log error appropriately
    } catch (...) {
        std::cout << "Unknown exception in thread" << std::endl;
    }
}

int main() {
    // Unsafe detached thread
    std::thread unsafe_thread(risky_thread_function);
    unsafe_thread.detach();
    
    // Safe detached thread with wrapper
    std::thread safe_thread(safe_thread_wrapper<void(*)()>, []() {
        throw std::runtime_error("Wrapped exception!");
    });
    safe_thread.detach();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return 0;
}
```

### Resource Management Best Practices

```cpp
#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
#include <atomic>

class ThreadSafeResource {
private:
    std::mutex mtx;
    std::atomic<bool> is_valid{true};
    std::unique_ptr<int> data;

public:
    ThreadSafeResource() : data(std::make_unique<int>(42)) {}
    
    bool use_resource() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_valid.load()) {
            return false; // Resource already cleaned up
        }
        
        // Use the resource safely
        std::cout << "Using resource: " << *data << std::endl;
        return true;
    }
    
    void cleanup() {
        std::lock_guard<std::mutex> lock(mtx);
        is_valid.store(false);
        data.reset(); // Safe cleanup
        std::cout << "Resource cleaned up safely" << std::endl;
    }
};

void worker_with_shared_resource(std::shared_ptr<ThreadSafeResource> resource) {
    try {
        for (int i = 0; i < 5; ++i) {
            if (!resource->use_resource()) {
                std::cout << "Resource no longer available" << std::endl;
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    } catch (const std::exception& e) {
        std::cout << "Exception in worker: " << e.what() << std::endl;
        // shared_ptr automatically handles cleanup
    }
    
    // shared_ptr reference count decreases when thread ends
    std::cout << "Worker thread finished" << std::endl;
}

int main() {
    auto resource = std::make_shared<ThreadSafeResource>();
    
    // Start detached thread with shared resource
    std::thread worker(worker_with_shared_resource, resource);
    worker.detach();
    
    // Main thread can safely cleanup
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    resource->cleanup();
    
    // Resource will be properly destroyed when last shared_ptr goes out of scope
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    return 0;
}
```

## Best Practices

1. **Always join or detach threads** - Avoid thread resource leaks
2. **Use RAII for locks** - `std::lock_guard` and `std::unique_lock`
3. **Prefer atomic operations** for simple shared data
4. **Use condition variables** for thread coordination
5. **Consider thread pools** for managing multiple short-lived tasks
6. **Be careful with exception safety** in threaded code
7. **🚨 NEW: Use RAII for all resources in detached threads** - Avoid manual memory management
8. **🚨 NEW: Implement exception handling in detached threads** - Prevent resource leaks on crashes
9. **🚨 NEW: Use smart pointers for shared resources** - Automatic cleanup when threads terminate

## Common Headers
```cpp
#include <thread>           // std::thread
#include <mutex>            // std::mutex, std::lock_guard
#include <condition_variable> // std::condition_variable
#include <atomic>           // std::atomic
#include <future>           // std::future, std::promise, std::async
#include <chrono>           // Time utilities
```

## Compilation
```bash
# Compile with thread support (usually automatic in modern compilers)
g++ -std=c++11 -pthread your_file.cpp -o your_program
```
