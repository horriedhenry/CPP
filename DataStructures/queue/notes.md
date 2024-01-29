# Queue

- Queue follows `FIFO`, the first item in will be the first item out, IRL it is similar to any `queue` anywhere, the first persone arriving is the first person to leave.
- In queue insertion happens from one end and deletion happens from other.
- `insertion` happens from `back` and `deletion` happens from `front`.

# Queue operations

- `enqueue()` - similar to `push()` used to add `element` into `queue`.
- `dequeue()` - similar to `pop()` deletes the `first` element `in` into the queue, and after deletion it will `point` to `2nd` element `in` and so on..
- `peek()`    - similar to `top()` points to `first` element `in` into the queue, returns `queue[first]`, whatever `first` points to .
- `empty()`   - return `true` if `queue` is empty.

# Queue implementation using array.

- We use two pointers `front` and `back`, `front` points to the first element `in` into the array, and `back` points to the last element `in` into the array or `latest` element in the array.
- I implemented queue before making these notes... I explained this to my self just to make sure that i can just express what i know, that i know what i know..in engblish (it's `english` ik).

```c++
#include <iostream>

const int size = 6;
int front = -1;
int back = -1;
int queue[size] = {0};

void push(int x) {
    // enqueue()
    back++;
    if (back > size - 1) {
        std::cout << "queue overflow" << "\n";
        return;
    }
    queue[back] = x;
    if (front == -1) {
        front++;
    }
}

void pop() {
    // dequeue()
    if (front > back || front == -1) {
        return;
    }
    front++;
}

int top() {
    // peek()
    if (front > back || front == -1) {
        return -1;
    }
    return queue[front];
}
```

### Approach

- As we know `insertion` and `deletion` happens from diffrent ends.. we have a queue of size `6`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 0 | 0 | 0 | 0 | 0 | 0 |
     +---+---+---+---+---+---+
b=-1 
f=-1
```

- when ever we `insert` an element into the `queue` we will `increment` back by `1` and at that pos we will insert the new element.
- when ever we `delete` an element from the `queue` we will `increment` front by `1` to point to `2nd` most element or `3rd` most and so on..

### Understand how queue works with an example.

- `enqueue()` or `push()` element `1` into queue.
- `increment` `b` by `1` and insert `1` at `queue[b]`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
f=-1
```

- `front` or `f` should point to `first` element `in` into the `queue` but it is still `-1`, so for the first element `in` into the `queue` we also `increment` `f` by `1`, but only when `insertion` is done for the first time.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
       f
```

- when ever `insertion` is done for the first time or `enqueue()` is called for the first time, we check if `first` is still `-1` if so `increment` `first` also.

#### Edge case - why should we increment `f` when calling `enqueue()` for the first time.

- what happens if we don't `f++` for the first time when calling `enqueue()`...
- let's Understand with an example.
- calling `enqueue()` and inseting `1` into the queue, and not incrementing `f`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
f=-1
```

- calling `enqueue()` and inseting `2` into the queue.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | N | N | N | N |
     +---+---+---+---+---+---+
           b
f=-1
```

- now let's call `dequeue()` what dequeue does is just increment `f` by `f++`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | N | N | N | N |
     +---+---+---+---+---+---+
       f   b
```

- `f` should not point to `1` we called `dequeue()` to just move from the `first` element, but it is still pointing to `first` element..
- if we call `dequeue()` again for the `second` time , then queue will move from `first` element.. this should not happen..

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | N | N | N | N |
     +---+---+---+---+---+---+
           b
           f
```

- calling `dequeue()` for the `second` time should remove the `second` element but it did not...
- to prevent this from happening we increment `first` pointer when calling `enqueue()` for the first time.

### continuation...on how queue works.

- this was our `queue()`..

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
       f
```

- calling `enqueue(2)`.. insert one more element into the `queue`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | N | N | N | N |
     +---+---+---+---+---+---+
       f   b
```

- calling `enqueue(3)`. 

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | N | N | N |
     +---+---+---+---+---+---+
       f       b
```

- calling `enqueue(4)`. 

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | N | N |
     +---+---+---+---+---+---+
       f           b
```

- calling `peek()`. this will return `1` coz that is the first item in the `queue` right now.
- calling `dequeue()`, remove whatever is at `front` and move the `front` pointer to next `item` in the `queue`. this is how the `queue` looks like after this..

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | N | N |
     +---+---+---+---+---+---+
           f       b
```

- calling `peek()`. this will return `2` coz that is the first item in the `queue` right now.

### When do we know that queue is cleared, and queue overflow

- say this is our queue right now....

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
       f                   b
```

- say we called `dequeue()` for `4` times..this is how the `queue` looks like...

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
                       f   b
```

- call `dequeue()` for one more time...

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
                           b
                           f
```

- now calling `peek()` will return `6`.

- now lets call `dequeue()` for one more time...

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
                           b
                                f>b
```

- if `front > back` we know that `queue` is clear...
- so in `peek()` we should have a condition to check `if (front > back)` if so just return.

#### queue overflow

- this is our queue.. right now

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
                           b
                           f
```

- call `enqueue(7)`...

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | 3 | 4 | 5 | 6 |
     +---+---+---+---+---+---+
                               b
                           f
```

- now `enqueue(7)` will try to insert new item into queue at `queue[6]` but it is out of bonds, it exceeded the size limit...
- in `enqueue()` add a condition to check  `if back > size - 1` then just return... dont insert any item..

