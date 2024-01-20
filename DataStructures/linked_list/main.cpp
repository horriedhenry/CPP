#include <iostream>

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

void print_nodes() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
}

int main (int argc, char *argv[]) {
    insert_end(12);
    insert_end(22);
    insert_end(23);
    print_nodes();
    return 0;
}
