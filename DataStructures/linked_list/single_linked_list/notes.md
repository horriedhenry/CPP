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

```text
+-------+  +-----------+
| 1 | b |->| 2  | NULL |->NULL
+-------+  +-----------+
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

```text
+-----------+
| 3  | NULL |->
+-----------+
     c       
```

- Current Linked List. And head is pointing at a.

```text
+-------+  +-----------+
| 1 | b |->| 2  | NULL |->NULL
+-------+  +-----------+
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

```text
+-------+  +--------+  +-----------+
| 1 | b |->| 2  | c |->| 3  | NULL |-> NULL
+-------+  +--------+  +-----------+
    a           b             c       
```

- insert_beg, delete_end, delete_beg are simple to implement..

# print data values & Count no.of nodes

### print data values

- Current lined list...

```text
+-------+  +--------+  +-----------+
| 1 | b |->| 2  | c |->| 3  | NULL |-> NULL
+-------+  +--------+  +-----------+
    a           b             c       
```
- should print `1 2 3`...

#### Method

- Iterate through each node until there is no node left to traverse and for every iteration print the data of the current node we are at.
- As mentioned use `iterator != NULL` as this will iterate the entire list and when it reaches the last node and try to do `iterator->link` this will be `NULL` so the while loop will break.

```c++
void print_node_data() {
    if (head == NULL) {
        std::cout << "[print_node_data] : List Is Empty" << std::endl;
        return;
    }
    Node* iterator = head;
    while (iterator != NULL) {
        std::cout << iterator->data << " ";
        iterator = iterator->link;
    }
    std::cout << std::endl;
}
```

- print the data of the current node the `iterator` is pointing to and then move to the next node i.e update the `iterator` using `iterator = iterator->link`. 
- if we use `iterate->link != NULL` then we will leave the last node, as we know that the last node is ignored we can just print the `data` of the last node after the while loop is done executing using `iterator->data`.

```c++
Node* iterator = head;
while (iterator->link != NULL) {
    std::cout << iterator->data << " ";
    iterator = iterator->link;
}
std::cout << iterator->data << " " << std::endl;
```

### Count no.of nodes

- Current list....

```text
+-------+  +--------+  +-----------+
| 1 | b |->| 2  | c |->| 3  | NULL |-> NULL
+-------+  +--------+  +-----------+
    a           b             c       
```

- return the no.of nodes..i.e `3` in this case.

#### Method

- Iterate through the entire list until there is no node left to traverse.
- As mentioned above we should use `iterate != NULL` with a `while` loop so that we don't miss any node, for every iteration increate the `count` by `1`. 

```c++
int count_nodes() {
    Node* iterator = head;
    int count = 0;
    while(iterator != NULL) {
        iterator = iterator->link;
        count++;
    }
    return count;
}
```

- if we use `iterator->link != NULL` after the loop just increment `count` by `1`.

```c++
while(temp->link != NULL) {
    temp = temp->link;
    count++;
}
count++;
return count;
```


# Insert node at given position.

- Current linked list...

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
```

- `1,2,3` are the position of the nodes i.e 1st node is a.. i did not use a zero index approach so index starts form 1.
- insert a new node named `d` at pos 3.

```text
+-----------+  
| 13 | NULL |
+-----------+  
    d       
```

- Result should be....

```text
     1            2           3           4
+--------+  +--------+  +---------+  +-----------+
| 10 | b |->| 11 | d |->| 13  | c |->| 12 | NULL |-> NULL
+--------+  +--------+  +---------+  +-----------+
    a          b             d             c       
  head
```

#### Approach

- `pos = 3`, i.e insert the new node at `pos = 3` and by looking at the result we know what to update in order to get the result we want.
- By looking at the result, let's check what got updated, the `link` part of the node before `pos 3` is updated with the address of the new node, and the `link` part of the new node i.e `d` is updated with the `link` part of the node before that i.e `pos 2` which was `c`.
- The things that got updated were the `link` part of the node before the given `pos` and the link part of the new node, i.e `d`.

- To get what we want we should get to the previous node or the `pos` before the actual `pos` , in simple words if the `pos = 3` go to the `2nd` node.
- After we get to `pos - 1` i.e `3 - 1` if we update the `link` part of the `2nd` node with the address `d` this will be the result.


```text
     1            2           3      
+--------+  +--------+  +-----------+
| 10 | b |->| 11 | d |->| 13 | NULL |-> NULL
+--------+  +--------+  +-----------+
    a          b              d       
  head
```

- This is not the result we want, so.......
- Let's just check what we had before....This was our initial linked list

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
```

- If we look, at `pos 3` we have node named `c` and the node before that is `b` and `b` is pointing to `c`.
- And we are trying to insert a node at `pos 3`, i.e the node at `pos 3` will become the node at `pos 4` , if we update the link part of the `node` before `pos 3` i.e `pos 2` we will not have access to `4th` node at all.
- So to get the result that we want.. the `link` part of the node before given `pos` should be the `link` part of the new node, and the `link` part of the node before given `pos` should be updated with the address of new `node`.
- But we already tried to updated the `link` part of the node before the given `pos` to point to the address of the new `node`, that did not work.. so keep track of the `link` part of the node before the given `pos` and then update the `link` part of the node before given `pos` with the address of new `node`, and then update the `link` part of the new node with the address that we kept track of i.e `link` part of the `node` before the given `pos`.
- Let's dry run the approach.

- This is the initial list..

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
```

- new node 

```text
+-----------+  
| 13 | NULL |
+-----------+  
    d       
```

- keep track of the address of `2nd` node , coz that is the node before `3`.
- `track = c`
- update the `link` part of `2nd` node to the address of new node i.e `d`.

- Or instead of keeping track of `c` we just update the `link` part of  `new node` with the link part of the `previous node`, and then update the `link` part of the `previous node` with the address of `new node`.

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | d |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
```

- and then update the `link` part of the new `node` i.e `d` with the address we kept track of i.e `c`. and this is how it looks.

```text
+--------+  
| 13 | c |
+--------+  
    d       
```

- now we have what we want.

```text
     1            2           3           4
+--------+  +--------+  +---------+  +-----------+
| 10 | b |->| 11 | d |->| 13  | c |->| 12 | NULL |-> NULL
+--------+  +--------+  +---------+  +-----------+
    a          b             d             c       
  head
```

#### Implementation

```c++
void insert_at_pos(int data, int pos) {
    if (head == NULL) {
        std::cout << "[insert_at_pos] : List Is Empty" << std::endl;
        return;
    }
    if (pos == 1) {
        insert_beg(data);
        return;
    }
    if (pos < 1) {
        std::cout << "[insert_at_pos] : Indexing Starts at 1 , Invalid Pos " << std::endl;
        return;
    }
    int count = count_nodes();
    if (pos > count) {
        insert_end(data);
        return;
    }
    Node* new_node = _malloc();
    new_node->data = data;
    new_node->link = NULL;
    Node* iterator = head;
    for (int i = 1; i < pos - 1; i++) {
        iterator = iterator->link;
    }
    new_node->link = iterator->link;
    iterator->link = new_node;
}
```

- The reason why we used `pos - 1` is because we are trying to go to the node before the given `pos` that is why we use `pos - 1`. we use `pos - 1` when the indexing starts from `1`.
- Let's understand the above condition with our current linked list.
- Initial list

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
  head
```

- iterator is pointing to head which is pointing to `a`.
- The input `pos = 3` and the for loop looks like this.

```c++
for (int i = 1; i < 2; i++) {
    iterator = iterator->link;
}
```

- `1 < 2` so move the iterator to next node using `iterator = iterator->link`, and now iterator is at `b` and `i` is incremented by `1`.
- `2 < 2 == false` so the for loop will break, and we reached the `node` that we want.
- after we reached where we want to reach.. we do this..

```c++
new_node->link = iterator->link;
iterator->link = new_node;
```

- if `pos = 1` the condition in the `for` loop will not be satisfied hence will not enter the loop, and every thing would be good but the new node will node be assigned as head node, and the previous `head node` will remain the same so when we try to `print data` it will start printing from the `previous` head node.
- This is what i mean..

```text
     1            2           3           4
+--------+  +--------+  +---------+  +-----------+
| 13 | a |->| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +--------+  +---------+  +-----------+
    d          a             b             c       
              head
```

- Instead of `printing` `13 10 11 12` `print_data` will print `10 11 12`, so when we have `pos = 1` we also need to assign the `new node` as `head`, we can either do that manually or just call `insert_beg` function.
- If `pos = 4` this would work... as we are not keeping track of a `tail` pointer.

```c++
new_node->link = iterator->link;
iterator->link = new_node;
```

- And the other edge cases in `insert_at_pos` are self explanatory.

