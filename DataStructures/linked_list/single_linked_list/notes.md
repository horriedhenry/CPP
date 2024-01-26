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

# Delete node at given pos

- Current list

```text
     1            2           3           4
+--------+  +--------+  +---------+  +-----------+
| 10 | b |->| 11 | d |->| 13  | c |->| 12 | NULL |-> NULL
+--------+  +--------+  +---------+  +-----------+
    a          b             d             c       
  head
```

- delete node at `pos 3`.
- result should be this list...

```text
     1            2           3
+--------+  +---------+  +-----------+
| 10 | b |->| 11  | c |->| 12 | NULL |-> NULL
+--------+  +---------+  +-----------+
    a           b             c       
  head
```

#### Approach

- Go the previous node of the given `pos` , if `pos = 3` then go to the `3 - 1` node, and then update the `link` part of that `previous node` with the link part of the `next node`. If `pos = 3` go to `2nd` node and update `link` of that node with the `link` of the `3rd` node.
- This is simiar to `insert_at_pos`, instead of inserting a node we delete it.

```c++

Node* del = iterator->link; // the node we want to delete
iterator->link = iterator->link->link; // update the previous node link with what ever the node we want to delete is pointing to.
// or
iterator->link = del->link;

```

#### Implementation

```c++
void delete_at_pos(int pos) {
    if (head == NULL) {
        std::cout << "[delete_at_pos] : List Is Empty" << std::endl;
        return;
    }
    if (pos == 1) {
        delete_beg();
        return;
    }
    if (pos < 1) {
        std::cout << "[delete_at_pos] : Indexing starts at 1 , invalid pos .. cannot delete" << std::endl;
        return;
    }
    int count = count_nodes();
    if (pos > count) {
        // if there are 3 nodes and the pos = 4
        // pos > count + 1 will be false and this function will execute the 
        delete_end();
        return;
    }
    Node* iterator = head;
    for (int i = 1; i < pos - 1; i++) {
        iterator = iterator->link;
    }
    Node *del = iterator->link;
    iterator->link = iterator->link->link;
    free(del);
    del=nullptr;
}
```

#### Reason for using `pos - 1`

- If we dont use `pos - 1` the `iterator` will go to the node we want to delete, but if we do go to the node we want to delete and just delete it the `previous` node before the given `pos` will not be there any more and if there is a `node` after given `pos` we will also lose that because the `node` at the given `pos` has the link to the `next node`.
- So we go to the `previous node` of the given `pos` and update the `link` part of that `previous node` to point to what ever the node at `given pos` is point to using..
- If we don't use `i = 1` and instead use `i = 0` then we have to do `pos - 2` instead of `pos - 1`

#### IMP

- **IMP** The `iterator`  starts at `head` node so when the `iterator` enters the `for loop` and executes for the first time it will reach to `2nd` node..
- **IMP** i.e for the `1st` iteration it will reach `2nd` node and for the `2nd` iteration it will reach `3rd` node..and so..on..
- **IMP** If `pos = 3` we should go the the `2nd` node so we just have to `iterate` the `for loop` for `one time` to go to the `2nd` node, and if `pos = 4` go to `3rd` node and to go to that `for loop` should run for `two times` to reach `3rd` node.
- **VVIMP** The `iterator` is already at the `first node` so `1` iteration is gonna move the `iterator` to `2nd` node and `2` iterations are gonna move the `iterator` to `3rd` node. so the no.of `iterations` should be equal to `pos - 1` if the `iterator` will start the `for loop` with `i = 1`, and if `i = 0` then we should use `pos - 2`.

- Say we want to delete the `3rd` node from a list , and the list has a total of `4` nodes.
- If we use `i = 0` and the just use `3 - 1` (pos - 1) then the iterator starts at `0` goes till `2` so the loop runs `3 times` but the `loop` should only run for `1 time` to reach to `2nd` node.
- For that to work we should use `for (int i = 0; i < pos - 2; i++)` condition .
- If we apply the above condition for `pos = 3` the loop only runs for `1 time` to reach to `2nd` node, and that is what we want.
- Else we can just use `for (int i = 1; i < pos - 1; i++)`, this also works fine
- When ever we are trying to insert a `node` at a certain `pos` we should use this condition to go the `node` before the given `pos`.

# Delete entire linked list.

### Approach

- Iterate through each node and while doing that keep track of `next` node and delete the current node the `iterator` is at and after deleting it set the `iterator` to point to `next` node, do this until there is no node left.
- We should keep looping till the `iterator == NULL` i.e use `while(iterator != NULL)` , while the condition is true.. keep track of `next` using `next = iterator->link` and then delete the node using `free(iterator)` and `iterator = nullptr` and then assign `iterator` to `next` node, keep repeating these steps until `iterator == NULL`.

### Implementation

```c++
void delete_all_nodes() {
    if (head == NULL) {
        std::cout << "[delete_all_nodes] : List Is Empty" << std::endl;
        return;
    }
    if (head->link == NULL) {
        free(head);
        head = NULL;
    }
    Node *next;
    while(head != NULL) {
        next = head->link;
        free(head);
        head = NULL;
        head = next;
    }
    std::cout << "[delete_all_nodes] : Entire linked list is deleted" << std::endl;
}
```

- I used `head` pointer as an `iterator`, and `next` to keep track of next node.
- If we use `head->link != NULL` then the `iterator` will reach the `last node` at stop there, if so we have to again after the while loop do `free(head)` and then `head = nullptr` to complete the process, instead of that just use `head != NULL`, this is the same approach that we use to `print_node_data` this condition makes sure that we go through each and every node even the `last` one. 
