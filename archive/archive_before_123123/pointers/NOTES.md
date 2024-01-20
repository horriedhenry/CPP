# Pointers

- A pointer is a pointer variable that holds the address of other variable.
- A pointer can be of any type (void, int, double) etc.
- Void pointer can point to any type of variable i.e it can just store the address.
  of any type of variable.
```cpp
int a = 10;
void* aPtr = &a;
std::cout<<"Address of a is : "<<aPtr<<endl;
std::cout<<"Address of a is : "<<&aPtr;
```
> ==std::cout<<"Address of a is : "<<aPtr<<endl;== prints the value that 
  aPtr is holding i.e address of a in the memory.

> ==std::cout<<"Address of a is : "<<&aPtr;== prints the address of aPtr in the 
  memory.

- There is something called as dereferencing a pointer.
- It means we can dereference a pointer and manipulate the actual value using
  it's memory location.
- But it is not possible with a void pointer, we cannot dereference a void pointer.
  void pointer can just hold a memory address of any type of variable, we cannot
  manipulate or change the value of a variable with a void pointer it is useless
  no one uses a void pointer.
- That's why we specify what type of variable we are pointing to is it int, float,
  etc.
- By this we know that we are pointing to a memory location that stores a value
  of a certain type(int, float, doubl, struct, etc).

---
# Pointer pointing to a certain type(int, float, doubl, struct, etc)
```cpp
int a = 10;
float b = 10f;

int* aPtr = &a;
float* bPtr = &b;

std::cout<<aPtr<<endl;
std::cout<<*aPtr<<endl;

```
- aPtr points to the memory location of a, which is of type int.
- bPtr points to the memory location of b, which is of type float.
- ==std::cout<<aPtr<<endl;== prints the address of the variable a.
- ==std::cout<<*aPtr<<endl;== here `*aPtr` is called as dereferencing.
- So basically `aPtr = address of a` right aPtr has a value and it is the address 
  of a right.
- When we do something like this `*aPtr` and print, it prints the value of a i.e
  12.
- In simple words `aPtr` is storing the address of a, when we do this `*aPtr`
  it dereference the address(memory location at which the variable is present)
  and give us the value that is present in that memory location in this case it
  gives us the value of `a` i.e `12`.The same goes for `bPtr` and `*bPtr`.

---
# The `&` for address of a variable
> The `&` operator placed before any variable gives it's address.
  ex : `std::cout<<&a;` prints the address of a.

> `&` is similar in c and c++.(i.e in case of being able to give the address).

> The `&` operator is also used in references(in c++) like this `int& aRef = a;`. 
  `aRef` now refers to `a`.It's like an alias to an existing variable.
  check references commit for more about references.
  But here we use it to get address of a variable.


```cpp
std::cout<<&aPtr<<endl;
```
- Prints the memory location of aPtr not its value(i.e memory location of a)
- We can dereference it once, lets see what happens.

```cpp
std::cout<<*&aPtr<<endl;
```
- We know that when we dereference a pointer, it gives us what is stored at a
  certain memory location right.
- When we do this `*&aPtr` it dereference this `&aPtr` and gives us the value
  that is being stored at that memory location.
- Lets see what `aPtr` and  `&aPtr` and `*&aPtr` prints.

> Code
```cpp
int main (int argc, char *argv[]) {
    int a = 12;
    int* aPtr = &a;
    std::cout<<"The value of aPtr : "<<aPtr<<endl;
    std::cout<<"Deference aPtr (i.e *aPtr): "<<*aPtr<<endl;
    std::cout<<"The address of aPtr : "<<&aPtr<<endl;
    std::cout<<"Deference aPtr : "<<*&aPtr<<endl;
}
```

> Output
```text
The value of aPtr(i.e aPtr) : 0x44347ffd6c
Deference aPtr (i.e *aPtr): 12
The address of aPtr(using &aPtr): 0x44347ffd60
Deference aPtr (i.e *&aPtr): 0x44347ffd6c
```
- From the above code and output we can notice what statement outputs what value.
- When we use `aPtr` it gives us the value of aPtr i.e memory location of a.
- When we use `*aPtr` it dereference aPtr and gives us what is present at the
  memory location that `aPtr` is storing, it gives us `12`.
- When we use `&aPtr` it prints the address of `aPtr` not what it is storing.
- Now when we dereference `&aPtr` by doing `*&aPtr` it dereference `&aPtr` i.e
  the it dereference the address or memory location of `aPtr` by doing this `*&aPtr`
  and gives us what is present at that memory location, i.e it gives what is
  stored at that memory location .
- In simple words this statement `*&aPtr` gives us what value is `aPtr` storing,
  we all know what it is storing , it is storing the memory location of `a`.
- This statement `*&aPtr` is equal to this `aPtr` both gives us what value is
  being stored by that location.
- `aPtr` stores the location of `a`
- `&aPtr` gives the address of aPtr in the memory.
- `*&aPtr` dereference `&aPtr` by doing `*&aPtr` and gives us what is stored at
  this (i mean &aPtr's location) and gives us the location of `a` as `aPtr` is
  storing the address of `a`.

### What does `**&aPtr` do
```cpp
std::cout<<"Deference *&aPtr(i.e **&aPtr) : "<<**&aPtr<<endl;
```
- We know what `*&aPtr` gives i.e the address of a.
- Now we dereference the address again by doing this `**&aPtr`
- Now it's simple by doing `**&aPtr` we get the value of a.

-> We can also re-use the pointer and store the address of other variable.
```cpp
int b = 13;
aPtr = &b;
std::cout<<"Deference aPtr after (aPtr = &b) : "<<*aPtr<<endl;
```
-> When we are done using the pointer we can free the pointer, and clear it from
   the memory to free up space.
```cpp
aPtr = nullptr;
free(aPtr);
```
-> `aPtr = nullptr` makes `aPtr` null, i.e `aPtr` is not storing anything at it's
   memory location.
-> `free(aPtr)`, completly frees up aPtr from the memory, now `aPtr` do not exist
   in the memory. We cannot use it after calling `free()` on `aPtr`.

---
- Don't think about it a lot, you got it, you got this far, you did understand
something.
- This is all, that's what pointer's do, Read through this entire file you will
  understand what a pointer is.

# TODO
# Pointers to Arrays & Pointers to String
```c++
int arr[3] = {1, 2, 3};
int* arrPtr = arr;
// use pointer Arithmetics to print array elements
for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    cout<<*(arrPtr + i)<<endl;
}
```
- *Arrays in c++ are stored in contiguous memory location*.
  i.e in a linear way.
  If we have 3 elements in an int array and the 1st element of the array is at mem
  location 2000. Then the second element will be at 2004 memory location, as an
  inteter occupies 4 bytes of memory.
- We use pointer arithmetics to print array elements.
- When we use `*(arrPtr + 0)` say `i == 0`, what it does is it prints the 1 element 
  of the array using its memory location.
- *When we do this`*(arrPtr + 0)` it adds 0 bytes to the current mem location, and
  when we use `*(arrPtr + 1)` it adds 4 bytes to the current mem location(coz an
  inteter is of size 4 bytes. and when we do this `*(arrPtr + 2)` it adds 4 bytes
  twice to the first mem location of the array i.e `2000` in this case*
- When we use `*(arrPtr + 0)` say `i == 1`, what it does is it moves 4 bytes ahead
  in the memory and prints the second element of the array, and the same process
  goes on till it prints the last element.
- This `*(arrPtr + 0)` is called as pointer arithmetics, as we are using addition
  operator to manipulate mem location.

### Pointers to String is almost similar
```c++
std::string str = "Hello, Iam Underwater";
std::string* strPtr = &str;
std::cout<<*strPtr;
```

- When we use `*strPtr` it prints the entire string.
- But when it comes to array if we use `*arrPtr` it prints the first element of
  the array.
- So to go through each character in the given string we use something like this
  `(*strPtr)[i]`, with this we can access each character of the string.

> In C we do it this way.

- As c does not have string keyword or what ever we use character array, to
  access individual element of the string or char array.
```c++
#include <string.h>
int main (int argc, char *argv[]) {
    char string[] = "Hello, Iam Underwater";
    char* strPtr = string;
    for(int i = 0; i < strlen(string); i++) {
        printf("%c", *(strPtr + i));
    }
}
```

# Pointer to struct
```c++
typedef struct House {
    std::string location;
    int sqFoot;
    int noOfBedrooms;
}House;

int main() {
    // Create a new House object called house. 
    // Or a new struct house using House struct, whatever.
    House house = {"Dholakpur", 300, 6};
}
```
- When a struct is created it will be allocated with x bytes of memory based on 
  members of the struct. Lets take the example of the above struct.
- It has 3 members 1 string and 2 integers that means when a new struct object 
  is created it will be allocated with 8 + 4 + 4 bytes of memory i.e 16 bytes of
  memory.

> NOTE : When a struct is allocated with x bytes of memory, all the members of
  that struct will be located in those x bytes of memory, this does not mean
  that they will be given contiguous memory like an array, they can be
  any where in that memory location with those x bytes of memory.

## Accessing house members, the `.` and `->` operators.
- To access the house members we can use the house object directly.
```c++
house.location;
house.sqFoot;
house.noOfBedrooms;
```
- When we use the house struct directly we use the `.` operator.

### Pointer to a struct the `->` operator.
```c++
int main() {
    House* housePtr = &house;
    std::cout<<"Using pointer to structure (->) :"<<"\n";
    std::cout<<housePtr->location<<std::endl;
    std::cout<<housePtr->sqFoot<<std::endl;
    std::cout<<housePtr->noOfBedrooms<<std::endl;
}
```
- When we are trying to access the members of the struct using the address of the
  struct we use `->` operator.


# Void pointer `void*`
```c++
int num = 112;
void* numPtr = &num;
std::cout<<numPtr;
std::cout<<*numPtr;// cannot do this, gives an error.
```
- `std::cout<<*numPtr` gives an error, coz a void pointer just points to a memory
  location of any type of variable.
- we can just use `std::cout<<numPtr` to print the address, we cannot dereference it.

## Typecasting a `void*` pointer
```c++
std::cout<<*((int *)numPtr);
```

- First we use `(int *)numPtr` to change the memory location to store address 
  of a variable of type int.
- Then we use `*((int *)numPtr)` to dereference the memory location and print
  what is present at the memory location.

## malloc()
- `malloc()` function allocates a chunk of memeory of x bytes provided by the user
  and returns a void pointer to that memory location.
- Example to deal with `malloc()`.

```c++
pHouse = (House *)malloc(sizeof(House));
```
- It's simple when we use `malloc(sizeof(House))` `malloc()` allocates a chunk
  of memory of size `House struct` whatever the size of it, and returns a void
  pointer to that memory location.
- Then after that we dereference it to be of type `House` using `(House *)`,
  so now this statement or whatever `(House *)malloc(sizeof(House))`, converts
  the memory location allocated by `malloc(sizeof(House))` and converts that
  memory location to a `House` type which is a struct.

```c++
void* MyAlloc(size_t param) {
    return malloc(sizeof(param));
}
```
- So the above function does the same thing as `malloc()`.

