#### Class & Object

`Class :` A class is like an object that defines the structure and behaviour of an object. It describes how an object should look like (it's attributes or data) and what it can do (it's members or functions).

`Object :` An Object is an instance of a class. While a class is like a general template, an object is an actual thing that is created based on that template.

- **Objects** are **entities** in real world.

- **Class** is like a blueprint of/for these entities.

#### Syntax

```c++
class Name
{
    // attributes / properties
    int age;

    // methods / functions
    void print_age()
    {
        std::cout << age;
    }
};
```

#### Access Modifiers

- `private :` data / attributes  & methods / functions  accessible inside class. By default all the attributes and methods of a class are private.

- `public :` data & methods accessible for everyone.

- `protected :` data & methods accessible inside class & to it's derived class (inheritence).

#### getter & setter

- `setter `  set / initialize private values of a class with a value.

- `getter ` get / access private values of a class, ex : get value of a private variable, or print the value of a private variable.

#### Encapsulation

- Encapsulation is **wrapping up** of data & member functions in a single unit called class.

- Grouping data / attributes or properties and member functions / methods into a single unit and encapsulating it or putting it inside one unit(class) is called encapsulation.

- Creating a class with attributes and methods / functions is called as encapsulating in a single unit called class

- Encapsulation also helps in **data hiding** i.e making some attributes private so that user canno access them directly when creating an object. You can either have a getter or a setter to access these "hidden" attributes or just don't allow the user to access them at all.

#### Constructor

Constructor is a special method that is invoked automatically at the time of object creation. And it is used for initializing the object. A constructor has these rules..

- Same name as class.
- Does not have a return type.
- Constructor is called once (automatically), at the time of object creation.
- Memory allocation happens when the constructor is called, which happens at the time of object creation.

---

- When there is not constructor for a class the compiler will create a constructor.
- Memory is not allocated for a class until an object is initialized.

```c++
class Name {
private:
    int x {5};
}
```
- when the compiler reaches this class it will not allocation any memory for variable x. It is just a literal in the code file.

```c++
Name obj;
```
- Now variable `x` will have a memory address, since it is initialized.

- This memory allocation happens when the constructor is called, it be a user defined or by the compiler.

- Constructor is used for initializing the object, ex.. we can assign values for private class attributes or call a method of that class, or we can do anything at the time of initializing an object using the constructor.

##### Types of constructor's

- non-parameterized , default constructor does not have any parameters.
- parameterized (has parameters, user defined)
- copy

##### Constructor overloading

- You can have multiple constructor's with different parameters. This is called as constructor overloading (kind of similar to function overloading). 

- If you have one constructor i.e non-parameterized and the other that has two parameters. And at the time of object creation if you pass any arguments then the compiler will call the constructor with parameters, or if you did not provide any arguments the it will call the one with no parameters.

- Say, you have 3 constructors one has zero parameters and one with 2 and the other with 3. At the time of object creation if you pass zero arguments the the constructor with zero parameters will be called and if you pass 2 arguments then the constructor with 2 parameters will be called and if you pass 3 arguments the constructor with 3 parameters will be called.

- Constructor overloading is a example of polymorphism. One of the example for polymorphism is constructor overloading.

#### this pointer

- `this` is a special pointer in c++ that points to the current instance of the class inside a non-static member function. It allows the object to refer to itself and all it's member functions and attributes.

- `this` is implicitly used when accessing member variables or methods. `this->memberFunction()` is equivalent to `memberFunction()`. However `this` is used when member variables are shadowed by local variables with the same name.

```c++
class Example{
private:
    int x;

public:
    Example(int x)
    {
        this->x = x; // this->x is a member variable and x is a constructor parameter.
    }

}
```

- `this` pointer is only available in non-static member functions, because static functions are not tied to any particular object.

- **this->attribute** is equivalent to ***(this).attribute**. It will be dereferenced first which evaluates to an object and then `.` is used to access the object attributes.


#### Shallow copy & Deep copy constructor

A **shallow** copy of an object copies all the member values from one object to another. And the default copy constructor does shallow copy.

- If there is no user defined copy constructor, then the default copy constructor will be used. It will perform a shallow copy. ex

```c++
#include <iostream>

class Student
{
private:
    std::string name;
    float cgpa;

public:
    Student(std::string&& name, float&& cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    void changeInfo(std::string&& name, float&& cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << this->cgpa << "\n";
    }
};

int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);
    s1.getInfo();

    Student s2(s1);
    s2.getInfo();

    s2.changeInfo("someone", 5.0);
    s2.getInfo();
    return 0;
}
```

```console
henry
7.5
henry
7.5
someone
5
```

- The default copy constructor takes a reference to an object, and copies every variables from that object to the new object.

##### User defined copy constructor (shallow)

```c++
Student(Student& orgObj)
{
    this->name = orgObj.name;
    this->cgpa = orgObj.cgpa;
}
```
- the above constructor works similar to the default copy constructor.

```console
henry
7.5
henry
7.5
someone
5
```

- shallow copy is fine in most cases but when it comes to a variable that has dynamically allocated memory instead of statically allocated memory on stack.. shallow does not work as intended...

#### Issue with shallow copy

- The example below shows the issue with shallow copy for dynamically allocated memory for a variable.

```c++
class Student
{
private:
    std::string name;

public:
    float* cgpaPtr;
    Student(std::string&& name, float&& cgpa)
    {
        this->name = name;
        cgpaPtr = new float;
        *cgpaPtr = cgpa;
    }

    // user defined copy constructor (shallow same as default but this will be
    // used instead of default)
    Student(Student& orgObj)
    {
        this->name = orgObj.name;
        this->cgpaPtr = orgObj.cgpaPtr;
    }

    void changeInfo(std::string&& name, float&& cgpa)
    {
        this->name = name;
        *cgpaPtr = cgpa;
    }

    void getInfo()
    {
        std::cout << this->name << "\n";
        std::cout << *cgpaPtr << "\n";
    }
};


int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 5;

    s1.getInfo();

    return 0;
}
```

- This should print

```console
henry
7.5
henry
7.5
```

- but .. it does this

```console
henry
7.5
henry
5
```

- we did not mean to change the member variable of object `s1` all we did is change the values of object `s2`. But what happened is that...

- We know that when `s1` object is created, the compiler will allocate a new memory location for that object and we know that each memory location is unique for every object. so when we use shallow copy to copy variables of `s1` to `s2`, the compiler will create new memory for `s2` object and copies every variable from `s1` to `s2`. When we don't have any variable that has dynamically allocated memory i.e the compiler will statically allocate memory in the stack we had no problem using shallow copy. But we have a variable `float* cgpaPtr` in Student class and it uses dynamically allocated memory (using `new`).. i.e `cgpaPtr` will be in `heap` instead of `stack` memory. and what happens is that...

- when we initialize `s1` using `Student s1("henry", 7.5)`, which invokes this..

```c++
Student(std::string&& name, float&& cgpa)
{
    this->name = name;
    cgpaPtr = new float;
    *cgpaPtr = cgpa;
}
```

- for `s1` object the compiler will allocate memory in the stack and `name` variable will also be in stack, but for `cgpaPtr` we will use a new memory location in heap and then in that memory location we will store `cgpa` value that is passed in the `class constructor` and let's say that `cgpaPtr` is at `200` memory location, and it's value is `7.5`.

- now when we use shallow copy here..

```c++
Student s2(s1);
```
- using the copy constructor

```c++
Student(Student& orgObj)
{
    this->name = orgObj.name;
    this->cgpaPtr = orgObj.cgpaPtr;
}
```

- every variable will be copied to s2 from s1 as is.. i.e previously `cgpaPtr` has a memory location and it's `200`, now in the above constructor when we use `Student s3(s1)` in this case it is `orgObj` what this `this->cgpaPtr = orgObj.cgpaPtr;` does is that it copies the memory location of `cgpaPtr` which was `200` to `s2`..

- so when we used this...

```c++
Student s2(s1);
*(s2.cgpaPtr) = 5;

s1.getInfo();
```

- it copied the memory location of `cgpaPtr` which was `200` and modified that using `*(s2.cgpaPtr) = 5`.. i.e why the `cgpa` is `5` instead of `7.5`. This is the problem with shallow copy for dynamically allocate member variables.

- to solve this we use deep copy for dynamically allocated member variables.

#### Deep copy

- Deep copy constructor not only copies the member values but also makes copies of dynamically allocated memory that the member point to.

- To solve the issue when shallow copy for dynamic memory, the solution is simple. Allocate memory for  `cgpaPtr` inside the copy constructor so that it will not copy the memory location of the object that it is copying from.

```c++
Student(Student& orgObj)
{
    this->name = orgObj.name;
    cgpaPtr = new float;
    *cgpaPtr = *orgObj.cgpaPtr;
}
```
- This allocates new memory location for `cgpaPtr` and then copies the value of `cgpaPtr` from `orgObj` using `*cgpaPtr = *orgObj.cgpaPtr;`

- Now.. let's run this again..

```c++
int main (int argc, char *argv[])
{
    Student s1("henry", 7.5);
    s1.getInfo();

    Student s2(s1);
    *(s2.cgpaPtr) = 5;

    s1.getInfo();

    return 0;
}
```

```console
henry
7.5
henry
7.5
```

- The above output is accurate, and it is what a copy constructor should do for variables with dynamically allocated memory.

- These will help understanding the difference between shallow and deep copy.

![one](./assets/1one.png)

![two](./assets/2two.png)

![three](./assets/3three.png)

![four](./assets/4four.png)

![five](./assets/5five.png)
