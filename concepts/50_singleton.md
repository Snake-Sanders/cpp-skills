# Singleton

A Singleton is a design pattern used to ensure that a class has only one 
instance throughout the program and provides global access to that instance. 

## Use cases:

* Controlled access to a shared resource is needed, like a database connection, 
logging service, or configuration manager.
* You need to ensure global state across multiple components, but without making
the entire class static.
* You want to avoid multiple instances of a class that could lead to issues like
resource contention or inconsistent states.

## Key Benefits:
Global access to a single instance.
Lazy initialization, meaning the instance is created only when it's first needed.
Can be used to manage shared resources efficiently.

## Example

```cpp
class Singleton {
private:
    // Private constructor to prevent instantiation from outside
    Singleton() {}

    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static instance pointer
    static Singleton* instance;

public:
    // Static method to access the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();  // Lazy initialization
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Singleton instance called!\n";
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

```
