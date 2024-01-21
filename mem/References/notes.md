[PointersReferences](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html)

- In addition to pointers like the ones in C, C++ has _references_.
- These are pointer types that cannot be reassigned once set and cannot be null.
- They also have the same syntax as the variable itself:
- No `*` is needed for dereferencing and `&` (address of) is not used for assignment.


- In C++, an rvalue reference is a reference that can bind to an rvalue. It's denoted by &&. Rvalue references were introduced in C++11 and play a crucial role in enabling move semantics.

Here's a brief overview:

- Lvalue Reference (&):
    Binds to lvalues (named objects with a persistent identity).
    Example: int x = 42; int& ref = x;

- Rvalue Reference (&&):
    Binds to rvalues (temporary objects or expressions that do not have a persistent identity).
    Used for move semantics, enabling efficient transfers of resources.
    Example: int&& rref = 42;


```c++
string foo = "I am foo";
string bar = "I am bar";
```

```c++
string& fooRef = foo; // This creates a reference to foo.
fooRef += ". Hi!"; // Modifies foo through the reference
cout << fooRef; // Prints "I am foo. Hi!"
```

- Doesn't reassign `fooRef`. This is the same as `foo = bar`, and `foo == I am bar` after this line.

```c++
std::cout << &fooRef << endl; //Prints the address of foo
fooRef = bar;
std::cout << &fooRef << endl; //Still prints the address of foo
std::cout << fooRef;  // Prints "I am bar"
```

- The address of fooRef remains the same, i.e. it is still referring to foo.


```c++
const string& barRef = bar; // Create a const reference to bar.
// Like C, const values (and pointers and references) cannot be modified.
barRef += ". Hi!"; // Error, const references cannot be modified.
```


> An r-value reference is a reference type introduced in C++11 that is used to bind to temporary objects or r-values. It is denoted by the double ampersand (`&&`) syntax.

> In C++, an l-value refers to an object that has a persistent identity and can be referenced multiple times. Examples of l-values are named variables, objects with a specific memory address, or references to other objects.


```c++
// l-value example
int a = 12; // has identity (a name)
```

> On the other hand, an r-value refers to a temporary object or a value that does not have a persistent identity. It is typically the result of an expression or a temporary object created during evaluations. Examples of r-values are literals, temporary objects, or the result of a function call.

```c++
// r-value example
int&& r_ref = 42;
```
- Creates an `rvalue` reference `rref` that refers to the literal value 42. This is an `rvalue` because it's a temporary value without a persistent identity.

> An r-value reference allows you to bind a reference to an r-value. It extends the lifetime of the temporary object, allowing you to use it beyond the lifetime of the expression in which it was created. This can be useful when you want to move or modify the temporary object efficiently.

```c++
// example demonstrating r-value
std::string temp_obj() {
    // the return string is not defined
    // and when this string is returnd ,
    // then it will copy this entire string
    // ex : in main func() we do 
    // string = temp_obj();
    return "temp string from temp_obj()";
}

void r_value_ref(std::string&& param) {
    // r_value_ref(temp_obj())
    std::cout << param << std::endl; // takes ownership of
    // the returned value
    // from temp_obj() gives it an identity.
}

int main (int argc, char *argv[]) {
    std::string str = temp_obj(); // this will copy the
    // return value from temp_obj().
    std::cout << str << std::endl;
    std::string&& strs = temp_obj(); // this will not copy
    // the string , it will refer to the return value
    // returned from temp_obj().
    std::cout << strs << std::endl;
    return 0;
}
```

> One common use of r-value references is in move semantics, where the resources of an object can be efficiently transferred (moved) from one object to another without making unnecessary copies. R-value references are also used in perfect forwarding, which allows passing arguments through multiple layers of function calls while preserving their value category (l-value or r-value).

## std::move()
- `std::move()` is used to indicate a willingless to move the resource, allowing efficient operations

```c++
void std_move() {
    std::string&& r_ref = "r_reference";
    r_value_ref(std::move(r_ref));
    std::cout << r_ref << std::endl;
}

int main (int argc, char *argv[]) {
    std_move();
    return 0;
}
```
- in `std_move()` the `std::move(r_ref)` function moves the r-value reference `r_ref` to `r_value_ref()` function and the scope of the `r_ref` will be in `r_value_ref()` function.

- ChatGpt's corrected response for above point.
- It's important to note that `std::move()` itself doesn't move anything; it just casts an `lvalue` to an `rvalue` reference. The actual move operation occurs when the `rvalue` reference is used, typically as an argument to a function or in an assignment.

- Attempting to use `r_ref` after the move leads to  undefined behavior.

```c++
void std_move() {
    std::string&& r_ref = "r_reference";
    r_value_ref(std::move(r_ref));
    std::cout << r_ref << std::endl;
}
```
- But we tried to print r_ref after moving it into r_value_ref(). The compiling environment I have did not cause any undefined behavior, but it is a violation of the C++ standard (C++11 and later), and relying on this behavior is not recommended.
```
