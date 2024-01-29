#include <iostream>

// in queue insertion happens from one side and deletion happens from other side
// follows FIFO - First In First Out, similar to a queue IRL. The first who gets to the counter leaves first

const int size = 6;
int front = -1; // initially front and back don't point to anything.
int back = -1;
int queue[size] = {0};

bool empty() {
    if (front == -1 || front > back) {
        return true;
    }
    return false;
}
void push(int x) {
    // enqueue()
    back++;
    if (back > size - 1) {
        std::cout << "queue overflow" << "\n";
        return;
    }
    queue[back] = x;
    if (front == -1) {
        front++;
    }
}

void pop() {
    // dequeue()
    if (!empty()) {
        // if queue is not empty
        front++;
        return;
    }
    std::cout << "no element to pop()" << "\n";
}

int top() {
    // peek()
    if (!empty()) {
        return queue[front];
    }
    return -1;
}

int main (int argc, char *argv[]) {
    return 0;
}
