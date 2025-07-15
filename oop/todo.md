# to-do's
- [ ] notes for static and non-static member functions and variables , what is it when is it used / when to use, what to use as static, what not to ect...(at the end)
    - [ ] you can use `ClassName::static_attribue` inside the class and it's legal but not recommend what does the compiler do in this case.
    - [ ] Definition of static data members must exist once at global scope, so memory can be allocated.
- [ ] how memory is allocated for instance of a class, a class has different methods how are they called like when you create an object and call one of the non-static methods will the object have their own copy of methods ??
    - [ ] memory allocation for static attributes/variables
    - [ ] when is memory allocation for non-static attributes
- [ ] different syntax for constructor `ClassName(parameter) : attribute(parameter) {}`, this is a different way to initialize private attributes.
- [ ] Rule of Three : when learning about operator overloading
    - [ ] Since the class manages dynamic memory, you should also implement the copy assignment operator to comply with the Rule of Three.
    - [ ] use operator overloading for `=` operator is what above definition mean.
- [ ] here : https://chatgpt.com/c/6874c29e-3fdc-800d-b5d1-fe65b88ffc7b look for : ✅ Are Methods Copied Per Object? and make notes at end q&a.
    - [ ] hint if the chat is deleted : method(&obj);   // the object address is passed as an implicit argument
    - [ ] method(s);  // where s is the pointer to the heap object
- [ ] Order in which constructor and destructor are called when inheriting and why (imp q is why, i know why but find a good explanation)
- [ ] Is it possible to have a private constructor (parameterised & non-parameterised) and what happens if you inherit from a class that has a private constructor/s only.

```cpp
Student(std::string name, int age, int rollno)
{
    Person(name, age); // This would not work the way you expect!
    this->rollno = rollno;
}
```
- [x] Before revising about types of inheritence : Do this first, learn about what happend under the hood when inheriting from a class, is a temp object created ect.. and why is the above syntax wrong
    - [x] why wouldn't this work and what does, can't call a constructor on an existing object (like Person in this case) in the constructor body. Will inheritence create multiple objects or what does it refer to, why is it wrong ?
- [ ] (at last); remove all the chatgpt explanation and type your own; and/or put all the questions at the end of the readme in questions section.

# AtTheEnd
- [ ] Do/Create a_project/multiple_projects that use all aspects of oop...like
    - [ ] inheritence (all types)
    - [ ] polymorphism
    - [ ] static keyword / use static attributes & members
    - [ ] function overloading / virtual functions
    - [ ] abstraction & abstraction class
