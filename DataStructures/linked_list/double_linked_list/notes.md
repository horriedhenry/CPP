# Double Linked List

```c++
typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;
```

- A Double Linked List node stores the address of both `previous` and `next` node.
- Here's an example.

```text

+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
| NULL | 1 | b |<-->| a | 1 | c |<-->| b | 1 | d |<-->| c | 1 | NULL |
+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
       a                b                c                d      
     head                                                tail         
```

- In DLL we can traverse in two directions, we can traverse forward and backward.
- If needed we can also have a `tail` pointer that always points to the last node, with this inserting at end would be easy, we dont need to traverse the entire list to get to the end like in single linked list, and with a `tail` pointer we can also print elements in reverse order.

# Insert at end & Insert at beginning.

- If we want to insert a new node at the beginning, just update the `head->prev` part with the address of `new_node` and then assign the `new_node` as head using `head = new_node`.
- Inserting at end can be done in two ways.. we can iterate the entire list until we reach the last node and once we reach the last node update `last_node->next` with the address of `new_node` , and as a double linked list has a pointer to previous node we should update the `prev` part of `new node` with the address of `last_node`. Or we can just use `tail` to insert at end.

### Insert at end

- insert node `f` at the end.
- initial list


```text

+------+---+---+    +---+---+---+    +---+---+------+
| NULL | 1 | b |<-->| a | 1 | c |<-->| b | 1 | NULL |
+------+---+---+    +---+---+---+    +---+---+------+
       a                b                c            
     head                               tail         

```

- assume that `iterator` is pointing to last node i.e `c` and then as `new_node` will be our last node, the last node should point to node before that, to do that update the `prev` part of `new_node` with the address of `iterator` and then update the `next` part of `iterator` to point to `new_node`.
- The result will look something like this..


```text

+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
| NULL | 1 | b |<-->| a | 1 | c |<-->| b | 1 | f |<-->| c | 1 | NULL |
+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
       a                b                c                f      
     head                                                tail         
```

### Insert at beginning.

- Update the `prev` part of `head` with the address of `new_node` and then update `next` part of `new_node` with the address of `head` and then make `new_node` the new `head` pointer.

```text

+------+---+---+    +---+---+---+    +---+---+---+
| NULL | 1 | b |<-->| a | 2 | c |<-->| b | 3 | d |
+------+---+---+    +---+---+---+    +---+---+---+
       a                b                c        
     head                               tail         
```

- insert new node `f` at the beginning of the list.
- do the first step...

```text

+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
| NULL | 4 | a |<-->| f | 1 | b |<-->| a | 2 | c |<-->| b | 3 | NULL |
+------+---+---+    +---+---+---+    +---+---+---+    +---+---+------+
       f                a                b                c      
     head                                                tail         

```

