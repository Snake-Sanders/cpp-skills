# Concurrency and Multithreading

## 1. Creating Threads (std::thread)
C++ provides the `std::thread` class to create and manage threads.
A thread allows tasks to run concurrently, meaning they can be executed in 
parallel, improving performance for multi-core processors.

## 2. Mutexes
A mutex (short for mutual exclusion) is a synchronization primitive used to 
prevent multiple threads from accessing a shared resource at the same time,
which can lead to data races or inconsistent states.

## 3. Lock Guard (std::lock_guard)
`std::lock_guard` is a helper class that provides RAII-style 
(Resource Acquisition Is Initialization) locking, ensuring that a mutex is 
locked when the guard is created and automatically unlocked when it goes out of
scope.

## 4. Condition Variables
A condition variable allows one thread to wait for a specific condition to be 
met, while another thread can notify it once the condition is fulfilled.
This is useful for thread coordination, like waiting for data to become available.

## 5. Atomic Operations (std::atomic)
The `std::atomic` class template allows certain variables to be accessed and 
modified atomically, meaning without interference from other threads. 
This ensures that operations on the variable are thread-safe without needing a mutex.

## 6. Thread Communication
Thread communication often uses mechanisms like shared variables,
condition variables, and message queues to exchange data between threads.
It requires careful synchronization to avoid race conditions.

## 7. Thread Joining (std::thread::join)
A thread join operation ensures that the main thread (or any other thread) 
waits for a child thread to finish executing before continuing. 
This ensures proper synchronization and avoids terminating threads prematurely.

## 8. Detaching Threads (std::thread::detach)
Detaching a thread allows it to run independently from the main program. 
Once detached, it runs in the background, and the system will reclaim its 
resources automatically when it finishes.

## 9. Deadlock
A deadlock occurs when two or more threads are waiting for each other to release
resources, causing the program to freeze. Deadlocks are avoided through techniques like lock ordering, timeouts, or using std::try_lock.

## 10. Race Conditions
A race condition occurs when multiple threads access shared resources without proper synchronization, leading to unpredictable or incorrect results. Using mutexes or atomic operations can prevent this.
