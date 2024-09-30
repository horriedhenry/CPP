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

