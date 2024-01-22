#include <iostream>
// in cll head->prev will point to last node , and lastnode->next will point 
// to head.

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

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
    assign(head, data);
    tail = head;
    head->prev = tail;
    tail->next = head;
}

void insert_end(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert, data);
    insert->prev = tail;
    insert->next = head;
    tail->next = insert;
    tail = insert;
    head->prev = tail; // forgot to add this 
    // found this out when i tried to print head->prev->data 
    // on this cll [1->2] which should print the data of tail node but instead 
    // it was printing head->data coz i did not updata the head->prev with tail.
}

void print_data() {
    if (head == NULL) {
        std::cout << "[print_data] : List is empty " << std::endl;
        return;
    }
    // if (head == tail) {
    //     std::cout << std::endl;
    //     std::cout << head->data << "->NULL"<< std::endl;
    //     return;
    // }
    std::cout << std::endl;
    Node* iterator = head;
    // while (iterator->next != head) {
    //     std::cout << iterator->data << "->";
    //     iterator = iterator->next;
    // }
    do {
        // well this worked out (no it did not)(yes it did)
        // say we have 2 nodes 1->2
        // first iterator->data prints 1 and then moves the iterator to next
        // node which is 2 and 2->next == head so the loop breaks
        // and just prints 1->
        // so we just print the tail node at the very last
        // but the good thing is that we dont need a condition to check if there
        // is only one node and have a while loop and print the tail data at the
        // end this do while loop is just better
        std::cout << iterator->data << "->";
        iterator = iterator->next;
    } while(iterator->next != head);
    std::cout << tail->data << "->";
    std::cout << "NULL" << std::endl;
}

int main (int argc, char *argv[]) {
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    print_data();
    // std::cout << head->data << std::endl;
    // std::cout << head->prev->data << std::endl;
    return 0;
}
