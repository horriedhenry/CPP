# Linked List
- Linked List Node

```c++
typedef struct Node {
    // linked list node
    int data;
    struct Node *link;
} Node;
```

- `struct Node *link` the link part of the node stores the address of 'Node' type.

### Create a Simple Linked List

```c++
Node *head = (Node *)malloc(sizeof(Node));
head->data = 10;
head->link = NULL;
Node *second = (Node *)malloc(sizeof(Node));
second->data = 10;
second->link = NULL;
std::cout << head->data << std::endl; // print data value of first node
std::cout << second->data << std::endl; // print data value of second node
```

- Not possible to Create all the notes this way. so just write a function that inserts a node at the end of linked list.

# TODO : Make Notes.
