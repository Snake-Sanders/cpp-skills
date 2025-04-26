# Const

## Const function

```cpp
class MyClass {
public:
    // This method is read-only and doesn't (shouldn't) 
    // change the internal state.
    int getValue() const;
};
```

This function doesn't modify the object’s member variables.
You can call it on a const MyClass object.

```cpp
const MyClass obj;
obj.getValue();  // okay because getValue() is const
```

## Const return value

```cpp
class MyClass {
public:
    const std::string getName();  // const return value
};
```

This means the returned value is const, so you can’t modify it:

```cpp
MyClass obj;
obj.getName() = "New Name";  // Error — return value is const

```

But: this is usually not useful for return-by-value types (like std::string),
because you're working on a copy anyway.

More useful if returning a reference:
`const std::string& getName();`

## Const parameter

```cpp
class MyClass {
public:
    void printMessage(const std::string& msg);
};
```

The function won’t modify the msg parameter. Good for safety and optimization
(especially for references).

```cpp
void MyClass::printMessage(const std::string& msg) {
    std::cout << msg;
    // msg = "hello"; Error — can't modify const reference
}
```

```cpp
class User {
private:
    std::string name;
public:
    const std::string& getName() const;            // 1 & 2
    void setName(const std::string& newName);      // 3
};
```

* getName() const → safe to call on const User
* const std::string& → caller can't modify the name
* setName(const std::string&) → doesn't modify input string
