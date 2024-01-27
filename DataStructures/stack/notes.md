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


# Linked List Implementation of stack. 

### Stack struct

```c++
typedef struct Stack {
    struct Stack* next;
    int data;
} Stack;

Stack top = NULL; // as top is not pointing to anything, stack is empty.
```

- Linked List is better than array, because array will have size limit where as with Linked list we can have as many nodes as we want.
- When it comes to operatoins on a stack.. they look like this...

### stack Operations with Linked List (single) .

- push()  - when pushing to Linked list always `insert at beginning`, this perfecly folows the `LIFO`, if we insert at end then when we do `pop` operation we will loose the link to previous node. As a single link link only points to next node, we should not use `insert at end`.
- pop()   - remove `head` node and assign the new head use for the node next to `head`. or we can use `top` to point to the first node, instead of naming it `head`.
- top()   - return `top->data`
- empty() - if `top == NULL` then return `true` else return `false`.
- erase() - we can use `erase` to delete the entire stack to free memory, this is just delete all nodes in the linked list.

### Implementation

```c++
#include <cstdlib>
#include <iostream>

typedef struct Stack {
    struct Stack* next;
    int data;
} Stack;

Stack* top = NULL; // top points to the latest node inserted.

Stack* _malloc() {
    return (Stack *)malloc(sizeof(Stack));
}

void assign(Stack* ptr, int x) {
    ptr->next = NULL;
    ptr->data = x;
}

void push(int x) {
    if (top == NULL) {
        Stack* push_ = _malloc();
        assign(push_,x);
        top = push_;
        return;
    }
    Stack* push = _malloc();
    assign(push,x);
    push->next = top;
    top = push;
}

void pop() {
    if (top == NULL) {
        std::cout << "[pop] : stack is empty" << std::endl;
        return;
    }
    Stack* next = top->next;
    free(top);
    top = nullptr;
    top = next;
}

int Top() {
    if (top == NULL) {
        std::cout << "[Top] : stack is empty" << std::endl;
        return -1;
    }
    return top->data;
}

bool empty() {
    if (top == NULL) {
        return true;
    }
    return false;
}

void erase() {
    if (top == NULL) {
        return;
    }
    Stack* del = top;
    while (del != NULL) {
        top = del->next;
        free(del);
        del = nullptr;
        del = top;
    }
}
```

### This is how it looks...

- if `top == NULL` then stack is empty.
- `push(1)` results in...

```text
+-----------+
| 1  | NULL |->NULL
+-----------+
     a       
    top
```

- `push(2)` to the stack would be...

```text
+--------+  +-----------+ 
| 2  | a |->| 1  | NULL |
+--------+  +-----------+
     b              a       
    top
```

- `push(3)` to the stack would be..

```text
+--------+  +--------+  +-----------+ 
| 3  | b |->| 2  | a |->| 1  | NULL |
+--------+  +--------+  +-----------+
     c         b              a       
    top
```

- `pop()` deletes the top node

```text
+--------+  +-----------+ 
| 2  | a |->| 1  | NULL |
+--------+  +-----------+
     b              a       
    top
```

- `top()` return the `data` of `top` node, returns `2` in this case.
- `empty()` right now returns `false` as `top != NULL`.
- `erase()` deletes all nodes from memory.

