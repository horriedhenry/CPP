#include <cstdlib>
#include <iostream>

/* 

NOTE : All functions handle all edge cases or all cases.

void print_available_func() {
    std::cout << "create_head_node() : Create's a head node" << std::endl;
    std::cout << "_malloc()          : allocate memory for a new node , return type (Node *)" << std::endl;
    std::cout << "insert_beg()"    << std::endl;
    std::cout << "insert_end()"    << std::endl;
    std::cout << "insert_at_pos()" << std::endl;
    std::cout << "delete_beg()"    << std::endl;
    std::cout << "delete_end()"    << std::endl;
    std::cout << "delete_at_pos()" << std::endl;
    std::cout << "delete_all_nodes() : Delete entire linked list" << std::endl;
    std::cout << "print_node_data()" << std::endl;
}

*/

typedef struct Node {
    // linked list node
    int data;
    struct Node *link;
} Node;

Node *head = NULL;

Node* _malloc() {
    return (Node*)malloc(sizeof(Node));
}

void create_head_node(int data) {
    head = _malloc();
    head->data = data;
    head->link = NULL;
}

void insert_end(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node *temp = head;
    Node* next = _malloc();
    next->data = data;
    next->link = NULL;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = next;
}

void print_node_data() {
    if (head == NULL) {
        std::cout << "[print_node_data] : List Is Empty" << std::endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
    std::cout << std::endl;
}

void insert_beg(int data) {
    // works
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* node = _malloc();
    node->data = data;
    node->link = head;
    head = node;
}

void delete_end() {
    // works
    if (head == NULL) {
        std::cout << "[delete_end] : List Is Empty" << std::endl;
        return;
    }
    if (head->link == NULL) {
        free(head);
        head = NULL;
        std::cout << "[delete_end] : Node deleted" << std::endl;
        return;
    }
    Node* temp = head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    std::cout << "[delete_end] : Node deleted" << std::endl;
}

void delete_beg() {
    // works
    if (head == NULL) {
        std::cout << "[delete_beg] : List Is Empty" << std::endl;
        return;
    }
    if (head->link == NULL) {
        free(head);
        head = NULL;
        std::cout << "[delete_beg] : Node Deleted" << std::endl;
        return;
    }
    Node *temp = head->link;
    head->link = NULL;
    free(head);
    head = NULL;
    head = temp;
    std::cout << "[delete_beg] : Node Deleted" << std::endl;
}

int count_nodes() {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->link;
        count++;
    }
    return count;
}

void insert_at_pos(int data, int pos) {
    // TODO : Notes on how insert_at_pos() work [pos--, pos - 1] (document this)
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
    pos--;
    Node* new_node = _malloc();
    new_node->data = data;
    new_node->link = NULL;
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->link;
    }
    new_node->link = temp->link;
    temp->link = new_node;
}

void delete_at_pos(int pos) {
    // TODO : notes about delete_at_pos() [pos--,pos - 1] in case of 
    // delete_at_pos() (document this) 
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
        // remaining code..which starts from pos-- [Explain in TODO above] (document this)
        delete_end();
        return;
    }
    pos--;
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->link;
    }
    Node *del = temp->link;
    temp->link = temp->link->link;
    free(del);
    del=nullptr;
}

void delete_all_nodes() {
// TODO : notes [used while (head->link != NULL) first instead of head == NULL &&
// when should we use head->link & when should we head != NULL ] (document this)
    if (head == NULL) {
        std::cout << "[delete_all_nodes] : List Is Empty" << std::endl;
        return;
    }
    if (head->link == NULL) {
        free(head);
        head = NULL;
    }
    Node *temp;
    while(head != NULL) {
        temp = head->link;
        free(head);
        head = NULL;
        head = temp;
    }
    std::cout << "[delete_all_nodes] : Entire linked list is deleted" << std::endl;
}

void reverse_linked_list() {
// TODO : notes [Explain this to my self (the entire process), 
// and name ptr1..3 with a better ones]
    if (head == NULL) {
        std::cout << "[reverse_linked_list] : List Is Empty" << std::endl;
    }
    if (head->link == NULL) {
        return;
    }
// if head->link is not NULL then we have more than two nodes in the linked list.
    Node *ptr1 = head;
    Node *ptr2 = ptr1->link;
    Node *ptr3;
    while(ptr2->link != NULL) {
    // didn't watch any video or referred any article, solved this my self
    // took a while to solve but i did.....
        ptr3 = ptr2->link;
        ptr2->link = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
    }
    // TODO : notes [Explain the steps below]
    ptr2->link = ptr1;
    head->link = NULL;
    head = ptr2;
}

int main (int argc, char *argv[]) {
    insert_beg(100);
    insert_end(101);
    insert_end(102);
    insert_end(103);
    insert_end(104);
    reverse_linked_list();
    std::cout << std::endl;
    print_node_data();
    // output = 104 103 102 101 100
    return 0;
}
