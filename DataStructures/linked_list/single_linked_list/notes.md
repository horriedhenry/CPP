# Single Linked List
- Linked List Node

```c++
typedef struct Node {
    // linked list node
    int data;
    struct Node *link;
} Node;
```
- A Single Linked list stores the address of next node , can only traverse in one direction. from start to end of the list.
- We will have a `head` node that points to the first node in the linked list. this will help us to traverse the linked list, for insertion, deletion..etc...
- Each node can store any type of data or n nbr of data points but should point to next node or if there are none point to NULL.
- `struct Node *link` the link part of the node stores the address of 'Node' type. In this case it stores the address of next node.

### Create a Simple Linked List

```c++
Node *head = (Node *)malloc(sizeof(Node));
head->data = 1;
head->link = NULL;
Node *second = (Node *)malloc(sizeof(Node));
second->data = 2;
second->link = NULL;
std::cout << head->data << std::endl; // print data value of first node
std::cout << second->data << std::endl; // print data value of second node
```

```c++
_________  _____________
| 1 | b |->| 2  | NULL |->NULL
---------  -------------
    a           b
```

- Result Linked list. Assume a Node with `1` as it's data and is at memory location `a` and `Node->link` has address of 2nd node i.e `b` and and `2` is at memory location `b` and it is not pointing to any other node.
- `head` points to a.

# Prerequisites

```c++

Node *head = NULL;

Node* _malloc() {
    return (Node*)malloc(sizeof(Node));
}

void create_head_node(int data) {
    head = _malloc();
    head->data = data;
    head->link = NULL;
}
```
- I will declare a head node just to avoid the overhead of passing head node the every function that needs it.
- `_malloc()` allocates memory for the node and returns the address of that memory location, with this i don't have to do `(Node*)malloc(sizeof(Node))` every time i need to allocate memory.
- if `head == NULL` anytime then just call create_head_node() function. As the name clearly states this node will be the `head` node. we will call this when we have no linked list. or the list is empty.

# Insert a node at the end of the list


- insert a new node say node `c`.  with `data = 3`.

```c++
Node* new = _malloc(); // name = c
new->data = 3;
new->link = NULL;
```

```c++
_____________
| 3  | NULL |->
-------------
     c       
```

- Current Linked List. And head is pointing at a.

```c++
_________  _____________
| 1 | b |->| 2  | NULL |->NULL
---------  -------------
    a           b       
```

- Insert `c` at the end of the list.

### Method
- Traverse the list until the iterator finds a node in which the link part is `NULL`.
```c++
void insert_end(int data) {
    if (head == NULL) {
        create_head_node(data); // if list is empty just create_head_node
        return;//
    }
    // traverse the list until node->link is null
    Node* iterator = head; // iterator to iterate the list and we start at head node. coz that is the only way.
    while (iterator->link != NULL) {
        iterator = iterator->link;
    }
}
```
- while `iterator->link != NULL` is false just keep moving forwad until it's true.
- now we found the that has `NULL` in the link part.
- After we found it just update the `iterator->next` to our new node that is `c`.

```c++
void insert_end(int data) {
    if (head == NULL) {
        create_head_node(data); // if list is empty just create_head_node
        return;//
    }
    Node* insert = _malloc(); // create a new node , say the name is c.
    insert->data = 3; // assign data
    insert->link = NULL; // update the link part
    // traverse the list until node->link is null
    Node* iterator = head; // iterator to iterate the list and we start at head node. coz that is the only way.
    while (iterator->link != NULL) {
        iterator = iterator->link;
    }
    // found the last node
    iterator->next = insert; // update the last node to point to the new node.
}
```
- All the above code does is that iterate till the last node and update the link part with the new node (insert) `b->link = c`.

#### While Loop condition

- if we don't use `iterator->next != NULL` and instead use `iterator != NULL`.
- say we used the second one, we will reach the last node and `iterator` would not be null even we reached the last node, the loop will keep going for one more step and in the last step `iterator` will be `NULL` and if we try to do `iterator-link = insert` we are trying to do `NULL->link = c` , null does not exist and we are trying to access it , so this throws a `segmentation fault`.
- so use `iterate->next != NULL` to stop at the last node.

#### Result

```c++
_________  __________  ____________
| 1 | b |->| 2  | c |->| 3  | NULL |-> NULL
---------  ----------  ------------
    a           b             c       
```

