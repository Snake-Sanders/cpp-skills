<!--toc:start-->
- [Object-Oriented Programming (OOP)](#object-oriented-programming-oop)
  - [1. **Polymorphism**](#1-polymorphism)
  - [2. **Inheritance**](#2-inheritance)
  - [3. **Encapsulation**](#3-encapsulation)
  - [4. **Abstraction**](#4-abstraction)
  - [5. **Virtual Function**](#5-virtual-function)
  - [6. **Abstract Class**](#6-abstract-class)
  - [7. **Interfaces**](#7-interfaces)
  - [8. **Multiple Inheritance**](#8-multiple-inheritance)
  - [9. **Diamond Problem**](#9-diamond-problem)
- [Examples](#examples)
  - [3. Encapsulation](#3-encapsulation)
    - [Friend Functions](#friend-functions)
    - [Friend Classes](#friend-classes)
  - [9. Virtual inheritance](#9-virtual-inheritance)
<!--toc:end-->

# Object-Oriented Programming (OOP)

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

## 3. Encapsulation

### Friend Functions

A non-member function can be declared as a friend of a class,
granting it access to the class’s private and protected members.

```c++
class MyClass {
private:
    int secretValue;
public:
    friend void revealSecret(MyClass& obj);
};

void revealSecret(MyClass& obj) {
    std::cout << obj.secretValue;
}
```

### Friend Classes

A whole class can be declared a friend of another class,
allowing all the methods of the friend class to access the private members of
the other.

```c++
class A {
private:
    int hiddenData;
    friend class B;  // B can access hiddenData
};

class B {
public:
    void accessA(A& a) {
        std::cout << a.hiddenData;  // Legal access
    }
};
```

## 9. Virtual inheritance

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
