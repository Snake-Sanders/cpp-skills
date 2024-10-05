# **Object-Oriented Programming (OOP)** 

## 1. **Polymorphism**
Polymorphism allows objects of different classes to be treated as objects of a common base class. It enables **method overriding**, where derived classes provide specific implementations of methods that are declared in their base class.

## 2. **Inheritance**
Inheritance allows one class (derived) to acquire the properties and methods of another class (base). It promotes **code reusability** and creates a natural hierarchy between classes.

## 3. **Encapsulation**
Encapsulation is the concept of **bundling data** (attributes) and methods (functions) that operate on the data within a class. It restricts access to certain details by using access specifiers like `private`, `protected`, and `public`.

## 4. **Abstraction**
Abstraction simplifies complex systems by hiding internal details and exposing only essential features. In C++, **abstract classes** (with at least one pure virtual function) allow for defining an interface that derived classes must implement.

## 5. **Virtual Function**
A virtual function is a function in a base class that can be **overridden** in derived classes. When a function is declared `virtual`, C++ uses **dynamic dispatch** to call the correct version of the function at runtime based on the actual object type.

## 6. **Abstract Class**
An abstract class is a class that cannot be instantiated on its own. It contains at least one **pure virtual function** and serves as a blueprint for other classes to implement its methods.

## 7. **Interfaces**
In C++, interfaces are implemented using **abstract classes** that contain only pure virtual functions. They define a contract that derived classes must follow without specifying how the methods should be implemented.

## 8. **Multiple Inheritance**
Multiple inheritance allows a class to inherit from more than one base class. However, it can lead to issues like the **diamond problem**, where ambiguities arise from inheriting the same base class multiple times, resolved using **virtual inheritance**.

## 9. **Diamond Problem**
The diamond problem occurs in **multiple inheritance** when a derived class inherits from two classes that both inherit from the same base class. This can create ambiguity, which is resolved by using **virtual inheritance**.

# Examples 

## 9. Virtaul inheritance 

```c++
class Vehicle {
public:
    std::string licensePlate;
    void startEngine() { /* common engine start logic */ }
};

class Car : virtual public Vehicle {
    // Cars share common vehicle properties
public:
    int numberOfDoors;
};

class Truck : virtual public Vehicle {
    // Trucks share common vehicle properties
public:
    int loadCapacity;
};

class PickupTruck : public Car, public Truck {
    // PickupTruck inherits from both Car and Truck
public:
    bool hasExtendedCab;
};
```
