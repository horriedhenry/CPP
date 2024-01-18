# The '*' operator

- This is used to declare a pointer like below.
```c++
int *ptr;
```

- store the address of a var

```c++
int a = 12;
int *aptr = &a;
```

- The '&' operator returns the memory address of a variable (in this case).
  '&' is also used for reference. but in this case it returns the address of
  'a'.


### Dereference

- Say we want to access a , but using 'aptr'.

```c++
std::cout << *(aptr) << std::endl; // prints 12
```
- we use '*' to Dereference what is present at that memory location, in this case
  it is '12'.

---

- we can also modify the value of 'a' using `aptr` that is pointing to memory
location of 'a'.

```c++
*aptr = 20; // modify the value of a using it mem address.
std::cout << a << std::endl;
```

- prints 20
- Modify the memory location with a new value that is '20'.
- say the memory address of a is (0x7ffe5e152c04) and at (0x7ffe5e152c04) 12 was 
  present previously, now change that value to 20. 


- If we dont use `*`, and do something like this

```c++
aptr = 20;
```
- throws and error.

```c++
./pointers.cpp: In function ‘void de_reference()’:
./pointers.cpp:36:12: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
   36 |     aptr = 20;
      |            ^~
      |            |
      |            int
```
- the reason it throws an error is because we are trying to modify the memory location
  i.e we are trying to change the value from (0x7ffe5e152c04) to 20 , which is not 
  possible we are trying to modify the address.

- that's whey `*aptr = 20` is used.

```c++
*aptr = 20;
a = 20;
```
- both `*aptr = 20` and `a = 20` are similar statements.
- we just use the address of a to modify a.

