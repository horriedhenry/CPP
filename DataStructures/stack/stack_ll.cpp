#include <cstdlib>
#include <iostream>

typedef struct Stack {
    struct Stack* next;
    int data;
} Stack;

Stack* top = NULL;

Stack* _malloc() {
    return (Stack *)malloc(sizeof(Stack));
}

void assign(Stack* ptr, int x) {
    ptr->next = NULL;
    ptr->data = x;
}

void push(int x) {
    if (top == NULL) {
        Stack* push_ = _malloc();
        assign(push_,x);
        top = push_;
        return;
    }
    Stack* push = _malloc();
    assign(push,x);
    push->next = top;
    top = push;
}

void pop() {
    if (top == NULL) {
        std::cout << "[pop] : stack is empty" << std::endl;
        return;
    }
    Stack* next = top->next;
    free(top);
    top = nullptr;
    top = next;
}

int Top() {
    if (top == NULL) {
        // std::cout << "[Top] : stack is empty" << std::endl;
        return -1;
    }
    return top->data;
}

bool empty() {
    if (top == NULL) {
        return true;
    }
    return false;
}

void erase() {
    if (top == NULL) {
        return;
    }
    Stack* del = top;
    while (del != NULL) {
        top = del->next;
        free(del);
        del = nullptr;
        del = top;
    }
}

int main (int argc, char *argv[]) {
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    std::cout << Top() << "\n";
    erase();
    return 0;
}
