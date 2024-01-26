# Stack

- A Stack is a linear data structure that holds a linear, ordered sequence of elements. It is an abstract data type. A Stack works on the LIFO process (Last In First Out), i.e., the element that was inserted last will be removed first.
- Insertion and deletion are done from only one end.

# Stack Operations

- push() - push an element.
- pop() - remove the last element.
- top() - points to the top most element in stack, i.e the element inserted at last.
- empty() - checks if the stack is empy.

# Implement stack using an array

### top = -1

- **NOTE** we are using an array as stack.
- to perform any of the Operations mentioned above we should have a pointer that points to the top most element or the element inserted recently or at last.
- we use `top` pointer to take care of that.
- initially `top = -1` because top is currently not pointing to any index in the stack(array).
- **IMP**so if we want to `push`, we should increment `top` by `1` because top was pointing to some index. so increment `top` by `1` fist and then at that `top` pos insert an element using `stack[top] = element`.

- `int stack[size]`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 0 | 0 | 0 | 0 | 0 | 0 |
     +---+---+---+---+---+---+
t=-1 
```

### stack Operations with array.

- push()  - push an element, to the array using `top` pointer, increment `top` first then at `stack[top]` `push` the element. when trying to push check if we reached the end of the array by doing `if(top > size)` then just return, or print we are out of size.
- pop()   - remove the last element. in terms of array just decrement the top pointer by `top--`. as we cannot delete an array memory location. check if stack is empty by using `if(top == -1)` then just return, there is not element to pop. If we want we can just do `stack[top] = 0` and then decrement the `top` pointer.
- top()   - points to the top most element in stack, i.e the element inserted at last.return the top most element, also check if the stack is empty.
- empty() - checks if the stack is empty, return `true` if stack is empty, `false` if not. use `if(top == -1) return true` else return `false`. use `empty()` function in all the above operatoins.

### Implementation

- define size of stack; as an array should have a size.
- Let size be `4`.
- define stack with given size `stack[size]`.
- and `top = -1` as we did not push any element into the stack yet.

- This is how the stack looks currently.
- `0` indicates that there is no element at `x` location in the array.
- `t` is `top`.

```text
       0   1   2   3  
     +---+---+---+---+
     | 0 | 0 | 0 | 0 |
     +---+---+---+---+
t=-1 
```

- now `push(2)`, increment `top` by `top++` because `top` must have been pointing to something, so increment that and then at that index assign `2`.
- do `top++` top will be `0` now

```text
       0   1   2   3  
     +---+---+---+---+
     | 0 | 0 | 0 | 0 |
     +---+---+---+---+
       t 
```

- `stack[0] = 2`

```text
       0   1   2   3  
     +---+---+---+---+
     | 2 | 0 | 0 | 0 |
     +---+---+---+---+
       t 
```

- `push(3)` top was pointing at `0` increment that first and then add `3` at that index.

```text
       0   1   2   3  
     +---+---+---+---+
     | 2 | 3 | 0 | 0 |
     +---+---+---+---+
           t 
```

- `push(4)`, `push(5)`.

```text
       0   1   2   3  
     +---+---+---+---+
     | 2 | 3 | 4 | 5 |
     +---+---+---+---+
                   t 
```
- `push(6)` we cannot push because we reached the end of the array.

- `pop()`

```text
       0   1   2   3  
     +---+---+---+---+
     | 2 | 3 | 4 | 0 |
     +---+---+---+---+
               t 
```

- `pop()`

```text
       0   1   2   3  
     +---+---+---+---+
     | 2 | 3 | 0 | 0 |
     +---+---+---+---+
           t 
```

- `top()`
- prints `3` as that is the top most element.

- `pop()` `pop()`

```text
       0   1   2   3  
     +---+---+---+---+
     | 0 | 0 | 0 | 0 |
     +---+---+---+---+
t=-1 
```

- `pop()` , `top` will be `-1` so just return, because stack is empty there is no element to pop
- This is array Implementation of stack, and i've tried my best, to explain why we should use `top++` and then push the element, maybe when i know how to frame a sentence properly, i will make this doc better. But for now that's the english i got.

