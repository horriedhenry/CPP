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

void create_head_node(int data) {
    head = _malloc();
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
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
    insert->data = data;
    insert->prev = NULL;
    insert->next = NULL;
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
    insert->data = data;
    insert->prev = NULL;
    insert->next = NULL;
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
    insert->data = data;
    insert->prev = NULL;
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

int main (int argc, char *argv[]) {
    insert_end(100);
    insert_end_using_tail(101);
    insert_beg(99);
    delete_beg();
    delete_end_using_tail();
    print_data_values();
    // std::cout << tail->data << std::endl;
    // std::cout << tail->prev->data << std::endl;
    return 0;
}
