#include <cstdlib>
#include <iostream>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

Node *head = NULL;
Node *tail = NULL; // useful for when needed to traverse backwards.
// or delete last node.

Node* _malloc() {
    return (Node *)malloc(sizeof(Node));
}

void assign(Node* ptr, int data) {
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
}

void create_head_node(int data) {
    head = _malloc();
    assign(head,data);
    tail = head;
}

void print_data_values() {
    if (head == NULL) {
        std::cout << "[print_data_values] : List is empty " << std::endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void insert_end(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* temp = head;
    Node* insert = _malloc();
    assign(insert,data);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = insert;
    insert->prev = temp;
    tail = insert;
}

void insert_end_using_tail(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert,data);
    tail->next = insert;
    insert->prev = tail;
    tail = insert;
}

void insert_beg(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert,data);
    insert->next = head;
    head->prev = insert;
    head = insert;
}

void delete_beg() {
    if (head == NULL) {
        std::cout << "[delete_beg] : List is empty " << std::endl;
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = nullptr;
        free(tail);
        tail = nullptr;
    }
    Node* temp = head->next;
    free(head);
    head = nullptr;
    head = temp;
}

void delete_end() {
    if (head == NULL) {
        std::cout << "[delete_end] : List is empty " << std::endl;
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = nullptr;
        free(tail);
        tail = nullptr;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    tail = temp->prev;
    free(temp);
    temp = nullptr;
}

void delete_end_using_tail() {
    if (head == NULL) {
        std::cout << "[delete_end] : List is empty " << std::endl;
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = nullptr;
        free(tail);
        tail = nullptr;
    }
    Node* temp = tail->prev;
    free(tail);
    tail = nullptr;
    tail = temp;
    tail->next = NULL;
}

int count() {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_at_pos(int data, int pos) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    if (pos == 1) {
        insert_beg(data);
        return;
    }
    if (pos > count()) {
        insert_end(data);
        return;
    }
    Node* temp = head;
    Node* insert = _malloc();
    assign(insert,data);
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    insert->prev = temp;
    insert->next = temp->next;
    temp->next = insert;
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        std::cout << "[delete_at_pos] : List is empty " << std::endl;
        return;
    }
    if (pos == 1) {
        delete_beg();
        return;
    }
    if (pos >= count()) {
        std::cout << "[delete_at_pos] : pos >= count calling delete_end() " << std::endl;
        delete_end_using_tail();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    // if (temp->next->next == NULL) {
    //     // if list = 1->2->3 and pos == 3 i.e delete the last node
    //     // or just use if (pos >= count) -> delete_end();
    //     delete_end_using_tail();
    //     return;
    // }
    Node* del_node = temp->next;
    temp->next = del_node->next;
    del_node->next->prev = temp;
    free(del_node);
    del_node = nullptr;
}

void insert_after_given_pos(int data, int pos) {
    // TODO : Notes [**IMP** : Document how this func() works, all the if statements]
    if (head == NULL) {
        std::cout << "[insert_after_given_pos] : List is empty and pos = " << pos << "calling insert_beg() " << std::endl;
        insert_beg(data);
        return;
    }
    if (head->next == NULL) {
        std::cout << "[insert_after_given_pos] : head->next == NULL, there is only one node \n and pos = "<< pos << "calling insert_end_using_tail() " << std::endl;
        insert_end_using_tail(data);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        insert_end_using_tail(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert, data);
    insert->next = temp->next;
    insert->prev = temp;
    temp->next = insert;
}

int main (int argc, char *argv[]) {
    insert_beg(99);
    insert_end(100);
    insert_end(102);
    insert_end(103);
    insert_after_given_pos(101, 2);
    std::cout << std::endl;
    print_data_values();
    return 0;
}
