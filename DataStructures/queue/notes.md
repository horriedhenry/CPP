# Queue

- Queue follows `FIFO`, the first item in will be the first item out, IRL it is similar to any `queue` anywhere, the first persone arriving is the first person to leave.
- In queue insertion happens from one end and deletion happens from other.
- `insertion` happens from `back` and `deletion` happens from `front`.

## Operations

- `enqueue()` - similar to `push()` used to add an `item` into `queue`.
- `dequeue()` - similar to `pop()` deletes the `first` item `in` into the queue, and after deletion it will `point` to `2nd` item `in` and so on..
- `peek()`    - similar to `top()` points to `first` item `in` into the queue, returns `queue[first]`, whatever `first` points to .
- `empty()`   - return `true` if `queue` is empty.

## Queue Implementation using array.

- We use two pointers `front` and `back`, `front` points to the `first item` `in` into the array, and `back` points to the last `item` `in` into the array or `latest` `item` in the array.
- I implemented queue before making these notes... I explained this to my self just to make sure that i can just express what i know, that i know what i know..in engblish (it's `english` ik).
- I used `item` instead of `element`...it does not matter...

```c++
const int size = 6;
int front = -1;
int back = -1;
int queue[size] = {0};

bool empty() {
    if (front == -1 || front > back) {
        return true;
    }
    return false;
}

void enqueue(int x) {
    // push()
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

void dequeue() {
    // pop()
    if (front > back || front == -1) {
        return;
    }
    front++;
}

int peek() {
    // top()
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

- when ever we `insert` an item into the `queue` we will `increment` back by `1` and at that pos we will insert the new item.
- when ever we `delete` an item from the `queue` we will `increment` front by `1` to point to `2nd` most item or `3rd` most and so on..

### Understand how queue works with an example.

- `enqueue()` or `push()` item `1` into queue.
- `increment` `b` by `1` and insert `1` at `queue[b]`.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
f=-1
```

- `front` or `f` should point to `first` item `in` into the `queue` but it is still `-1`, so for the first item `in` into the `queue` we also `increment` `f` by `1`, but only when `insertion` is done for the first time.

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | N | N | N | N | N |
     +---+---+---+---+---+---+
       b
       f
```

- when ever `insertion` is done for the first time or `enqueue()` is called for the first time or it's just adding an `item` into `queue` for the first time, we check if `first` is still `-1` if so `increment` `first` also.

#### **IMP** Why should we increment `f` when calling `enqueue()` for the first time.

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

- `f` should not point to `1` we called `dequeue()` to just move from the `first` item, but it is still pointing to `first` item..
- if we call `dequeue()` again for the `second` time , then queue will move from `first` item.. this should not happen..

```text
       0   1   2   3   4   5  
     +---+---+---+---+---+---+
     | 1 | 2 | N | N | N | N |
     +---+---+---+---+---+---+
           b
           f
```

- calling `dequeue()` for the `second` time should remove the `second` item but it did not...
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

- calling `enqueue(2)`.. insert one more item into the `queue`.

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

- this is the queue.. right now

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

# Queue using Singl Linked List

- WKT `insertion` happens from `back` and `deletion` happens from `front`.
- in case of `insertion` or `push` is just `insert node at end` operation on ll.
- in case of `deletion` or `pop` it is just `remove first node` operation on ll.
- we keep trace of both `first` and `last` node of linked list for `insertion` and `deletion`.

### Operations

- `enqueue()` - insert node at the end of ll.
- `dequeue()` - delete first node.
- `peek()`    - print data value of first node.
- `empty()`   - return `true` if `front == NULL`.

### Implementation

```c++
// Queue Node
typedef struct Queue {
    struct Queue* next;
    int data;
} Queue;

Queue* front = NULL; // used for insertion - enqueue()
Queue* back = NULL; // used for deletion - dequeue()

Queue* _malloc() {
    return (Queue *)malloc(sizeof(Queue));
}

void assign(Queue* ptr, int x) {
    ptr->next = NULL;
    ptr->data = x;
}

bool empty() {
    if (front == NULL) {
        return true;
    }
    return false;
}

void push(int x) {
    if (empty()) {
        // if Queue is empty , it means this is the first insertion, so front and back will point to same node.
        Queue* push = _malloc();
        assign(push, x);
        back = push;
        front = back;
        return;
    }
    // add item from end of ll
    Queue* push = _malloc();
    assign(push, x);
    back->next = push;
    back = push;
    return;
}

void pop() {
    if (!empty()) {
        // if Queue is not empty then pop the first node.
        Queue* next = front->next;
        free(front);
        front = next;
        return;
    }
    std::cout << "[pop] : Queue is empty" << std::endl;
}

void peek() {
    // first item in Queue at the time.
    if (!empty()) {
        // if Queue is not empty then print the data value of first node.
        std::cout << std::endl;
        std::cout << front->data << std::endl;
        return;
    }
    std::cout << "[peek] : Queue is empty" << std::endl;
}

void erase() {
    while(!empty()) {
        pop();
    }
}
```

### Understand with an example.

- initially `front` and `back` pointers are `NULL`.
- so to check if `queue` is `empty` we just need to check `if (front == NULL)` or we can also use `if (back == NULL)` instead.., both work.
- `push(1)` looks like..

```text
+----------+
| 1 | NULL |
+----------+
     a
   front
   back
```

- As this is the first insertion `front` and `back` point to `first` node. And i know why...(check the doc).

- `push(2)`

```text
+-------+  +----------+
| 1 | b |->| 2 | NULL |
+-------+  +----------+
     a           b       
   front        back
```

- `push(3)`

```text
+--------+  +--------+  +-----------+
| 1  | b |->| 2  | c |->| 3  | NULL |
+--------+  +--------+  +-----------+
     a           b           c
   front                    back
```

- `peek()` will print `1`
- `pop()` on ll will look like....

```text
+--------+  +----------+
| 2  | c |->| 3 | NULL |
+--------+  +----------+
     b           c       
   front        back
```

- `pop()`

```text
+----------+
| 3 | NULL |
+----------+
    c       
  front
   back
```

- `peek()` will return `3`.
- `pop()` would make `front = NULL` and `back = NULL`, this will make the `Queue` empty. 

#### empty() condition

- we can just use `if (front == NULL)` return `true`, if it's `NULL` it means Queue is empty.
- what if there is only one node and we do `pop()` if so , `front` and `back` will be `NULL`, which makes `queue` `empty`.

#### erase()

```c++
void erase() {
    while(!empty()) {
        pop();
    }
}
```

- Using while list is not empty `while (!empty())` is just better than using `delete all nodes` method, that is used in case of a single linked list. (This is good, the way i implemented pop() will not print `[pop]..` statement from `pop()`).

