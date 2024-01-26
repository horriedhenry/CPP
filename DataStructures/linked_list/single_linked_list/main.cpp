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
    // int count = count_nodes();
    // if (pos > count) {
    //     // if there are 3 nodes and the pos = 4
    //     // pos > count + 1 will be false and this function will execute the 
    //     delete_end();
    //     return;
    // }
    Node* iterator = head;
    for (int i = 1; i < pos - 1; i++) {
        iterator = iterator->link;
        if (iterator->link == NULL) {
            std::cout << "Reached the end of the list, pos > the no.of nodes.. returning.." << std::endl;
            return;
        }
    }
    Node *del = iterator->link;
    iterator->link = iterator->link->link;
    free(del);
    del=nullptr;
}

void delete_all_nodes() {
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
    if (head == NULL) {
        std::cout << "[reverse_linked_list] : List Is Empty" << std::endl;
    }
    if (head->link == NULL) {
        return;
    }
// if head->link is not NULL then we have more than two nodes in the linked list.
    Node *first = head;
    Node *second = first->link;
    Node *next;
    while(second != NULL) {
        // changed from second->link != NULL
    // didn't watch any video or referred any article, solved this my self
    // took a while to solve but i did.....
        next = second->link;
        second->link = first;
        first = second;
        second = next;
    }
    head->link = NULL;
    head = first; // check notes.md (in reverse_linked_list)
    // used these 3 lines before
    // second->link = first;
    // head->link = NULL;
    // head = second;
    first = nullptr;
}

int main (int argc, char *argv[]) {
    insert_end(1);
    insert_end(2);
    insert_end(4);
    insert_at_pos(3,3);
    std::cout << std::endl;
    reverse_linked_list();
    print_node_data();
    return 0;
}
