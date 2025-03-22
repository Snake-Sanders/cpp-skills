# Double Address Operator

&& is a new reference operator defined in the C++11 standard. 
int&& a means "a" is an r-value reference.


```cpp
void foo(int&& age)
{
    println("%d", age);
}

int main()
{
   int age;
   foo(age);     //Error. An rValue reference cannot be pointed to a lValue.
   foo(42);      // ok: passing a rvalue.
   foo(b + 10);  // ok: passing a rvalue.
   int&& c = b;  //Error. An rValue reference cannot be pointed to a lValue.
   int&& d = 7;  // ok: passing a rvalue.
}
```
