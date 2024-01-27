#include<iostream>

const int size = 5;
int _top = -1;
int stack[size];

bool empty() {
    if (_top == -1) {
        return true;
    }
    return false;
}

void push(int x) {
    _top++;
    if (_top > size) {
        // std::cout << "[push] : stack overflow" << std::endl;
        return;
    }
    stack[_top] = x;
}

void pop() {
    if(empty()) {
        std::cout << "[pop] : stack is empty" << std::endl;
        return;
    }
    stack[_top] = 0;
    _top--;
}

int top() {
    if(empty()) {
        // std::cout << "[top] : stack is empty" << std::endl;
        return -1;
    }
    return stack[_top];
}

int main (int argc, char *argv[]) {
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    std::cout << top() << std::endl;
    return 0;
}
