#include <cstdlib>
#include <iostream>

typedef struct Queue {
    struct Queue* next;
    int data;
} Queue;

Queue* front = NULL; // used for insertion - enqueue()
Queue* back = NULL; // used for deletion - dequeue()

Queue* _malloc() {
    return (Queue *)malloc(sizeof(Queue));
}

void assign(Queue* ptr, int x) {
    ptr->next = NULL;
    ptr->data = x;
}

bool empty() {
    if (front == NULL) {
        return true;
    }
    return false;
}

void push(int x) {
    if (empty()) {
        // if Queue is empty , it means this is the first insertion, so front and back will point to same node.
        Queue* push = _malloc();
        assign(push, x);
        back = push;
        front = back;
        return;
    }
    // add item from end of ll
    Queue* push = _malloc();
    assign(push, x);
    back->next = push;
    back = push;
    return;
}

void pop() {
    if (!empty()) {
        // if Queue is not empty then pop the first node.
        Queue* next = front->next;
        free(front);
        front = next;
        return;
    }
    std::cout << "[pop] : Queue is empty" << std::endl;
}

void peek() {
    // first item in Queue at the time.
    if (!empty()) {
        // if Queue is not empty then print the data value of first node.
        std::cout << std::endl;
        std::cout << front->data << std::endl;
        return;
    }
    std::cout << "[peek] : Queue is empty" << std::endl;
}

void erase() {
    while(!empty()) {
        pop();
    }
}

int main (int argc, char *argv[]) {
    push(1);
    push(2);
    push(3);
    erase();
    return 0;
}
