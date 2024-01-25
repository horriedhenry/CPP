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
    std::cout << std::endl;
    Node* iterator = head;
    while (iterator != tail) {
        std::cout << iterator->data << "->";
        iterator = iterator->next;
    }
    // TODO : Document the error [do while]
    // BUG :-
    // do while is not working , found the bug when trying to reverse_list 
    // when there is only one node
    // with a do while loop the output is 1->1->NULL
    // with a while loop it's just 1->NULL

    // do {
    //     // well this worked out (no it did not)(yes it did)
    //     // say we have 2 nodes 1->2
    //     // first iterator->data prints 1 and then moves the iterator to next
    //     // node which is 2 and 2->next == head so the loop breaks
    //     // and just prints 1->
    //     // so we just print the tail node at the very last
    //     // but the good thing is that we dont need a condition to check if there
    //     // is only one node and have a while loop and print the tail data at the
    //     // end this do while loop is just better
    //     std::cout << iterator->data << "->";
    //     iterator = iterator->next;
    // } while(iterator->next != head);
    std::cout << tail->data << "->";
    std::cout << "NULL" << std::endl;
}

void reverse_list() {
    // TODO : Document [iterator != tail]
    if (head == NULL) {
        std::cout << "[reverse_list] : List is empty " << std::endl;
        return;
    }
    if (head->next == head) {
        return;
    }
    Node *iterator = head;
    Node *next;
    Node *swap;
    while (iterator != tail) {
        next = iterator->next;
        swap = iterator->next;
        iterator->next = iterator->prev;
        iterator->prev = swap;
        iterator = next;
    }
    swap = iterator->next;
    iterator->next = iterator->prev;
    iterator->prev = swap;
    swap = head;
    head = tail;
    tail = swap;
}

void insert_beg(int data) {
    if (head == NULL) {
        create_head_node(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert, data);
    insert->prev = tail;
    insert->next = head;
    head->prev = insert;
    head = insert;
    tail->next = head;
}

int count() {
    if (head == NULL) {
        return 0;
    }
    if (head == tail) {
        return 1;
    }
    int count = 0;
    Node *iterator = head;
    while (iterator->next != head) {
        count ++;
        iterator = iterator->next;
    }
    count++; // when iterator reaches last node iterator->next == head 
    // but the loop will not increment the count by 1 for the last node
    // so after the loop increment count by 1 for the last node.
    return count;
}

void insert_at_pos(int data, int pos) {
    if (head == NULL) {
        std::cout << "[insert_at_pos] : List is empty calling insert_beg " << std::endl;
        insert_beg(data);
        return;
    }
    if (pos == 1) {
        insert_beg(data);
        return;
    }
    int count_ = count();
    if (pos > count_) {
        std::cout << "[insert_at_pos] : pos : " << pos << " > " << "count : " << count_ << " , calling insert_end " << std::endl;
        insert_end(data);
        return;
    }
    Node* insert = _malloc();
    assign(insert, data);
    Node* iterator = head;
    for (int i = 1; i < pos - 1; i++) {
        iterator = iterator->next;
    }
    iterator->next->prev = insert;
    insert->next = iterator->next;
    insert->prev = iterator;
    iterator->next = insert;
}

void delete_beg() {
/*

if (head == tail) {
    head = nullptr;
    tail = nullptr;
    free(head);
    free(tail);
}
// if (head->next == tail) {
//     tail->next = head->prev;
//     tail->prev = head->next;
//     free(head);
//     head = nullptr;
//     head = tail;
// }

TODO : Document why these two conditions don't work
TODO : This is not working. -> REASON : forgot to add return statement.

*/
    // TODO : Document delete_beg (include errors).
    if (head == NULL) {
        std::cout << "[delete_beg] : List is empty " << std::endl;
        return;
    }
    if (head == tail) {
        free(head);
        head = nullptr;
        tail = nullptr;
        return; // forgot to add return statement and the code below
        // executed, fucked me up for a while.
        // KEY : DO NOT FORGET RETURN STATEMENTS.
    }
    Node* next_node_after_head = head->next;
    tail->next = next_node_after_head;
    next_node_after_head->prev = tail;
    free(head);
    head = nullptr;
    head = next_node_after_head;
}

void delete_end() {
    if (head == NULL) {
        std::cout << "[delete_end] : List is empty " << std::endl;
        return;
    }
    if (head == tail) {
        free(head);
        head = nullptr;
        tail = nullptr;
        return; // return statement is important here, You Know why.
    }
    if (head->next == tail) {
        head->next = tail->next;
        head->prev = tail->prev;
        free(tail);
        tail = nullptr;
        tail = head;
        return; // this is important 🫠
    }
    Node *temp_tail = tail->prev;
    temp_tail->next = head;
    free(tail);
    tail = nullptr;
    tail = temp_tail;
    temp_tail = nullptr;
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        std::cout << "[delete_at_pos] : List is empty " << std::endl;
        return;
    }
    Node* del = head;
    if (pos == 1) {
        delete_beg();
        return;
    }
    int count_ = count();
    if (pos > count_) {
        std::cout << "[delete_at_pos] : pos > no of nodes present, calling delete_end " << std::endl;
        delete_end();
        return;
    }
    for (int i = 1; i < pos; i++) {
        del = del->next;
    }
    if (del->next == head) {
        delete_end();
        return;
    }
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
    del = nullptr;
}

void delete_entire_list() {
    if (head == NULL) {
        std::cout << "[delete_entire_list] : List is empty " << std::endl;
        return;
    }
    if (head == tail) {
        free(head);
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node* next;
    // head is the iterator.
    while (head != tail) {
        next = head->next;
        free(head);
        head = nullptr;
        head = next;
    }
    free(head);
    tail = nullptr;
    head = nullptr;
    // or 
    // free(tail);
    // tail = nullptr;
    // head = nullptr;
}

int main (int argc, char *argv[]) {
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    delete_at_pos(4);
    print_data();
    delete_entire_list();
    print_data();
    return 0;
}
