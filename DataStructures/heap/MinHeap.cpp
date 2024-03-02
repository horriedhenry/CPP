#include <iostream>
#include <vector>

#define endl std::endl

class Heap
{
private:
    std::vector<int> heap_arr;
public:
    int pIdx(int idx) { return (idx - 1) / 2; }

    int leftChildIdx(int idx) { return (2 * idx) + 1; }

    int rightChildIdx(int idx) { return (2 * idx) + 2; }

    void heapifyUp(int idx)
    {
        if (idx <= 0) {
            return;
        }

        int parentIdx = pIdx(idx);
        int parentVal = this->heap_arr[parentIdx];
        int curr_val = this->heap_arr[idx];

        if (parentVal > curr_val) {
            this->heap_arr[parentIdx] = curr_val;
            this->heap_arr[idx] = parentVal;
            heapifyUp(parentIdx);
        }
    }

    void heapifyDown(int idx, int size)
    {
        int rIdx = rightChildIdx(idx);
        int lIdx = leftChildIdx(idx);

        if (idx >= size || lIdx > size) {
            return;
        }

        int lVal = this->heap_arr[lIdx];
        int rVal = this->heap_arr[rIdx];
        int currVal = this->heap_arr[idx];

        if (rIdx > size && this->heap_arr[lIdx] < this->heap_arr[idx]) {
            this->heap_arr[idx] = lVal;
            this->heap_arr[lIdx] = currVal;
            return;
        }

        if (lVal > rVal && currVal > rVal) {
            this->heap_arr[idx] = rVal;
            this->heap_arr[rIdx] = currVal;
            heapifyDown(rIdx, size);
        } else if (rVal > lVal && currVal > lVal) {
            this->heap_arr[idx] = lVal;
            this->heap_arr[lIdx] = currVal;
            heapifyDown(lIdx, size);
        }
    }

    void insert(int val)
    {
        this->heap_arr.push_back(val);
        int size = this->heap_arr.size() - 1;
        if (size == 0) {
            return;
        }
        heapifyUp(size);
    }

    void del()
    {
        int size = this->heap_arr.size() - 1;
        if (size == 0) {
            this->heap_arr.pop_back();
            return;
        }
        this->heap_arr[0] = this->heap_arr.back();
        this->heap_arr.pop_back();
        heapifyDown(0, size);
    }

    void peek() {
        if (!this->heap_arr.empty()) {
            std::cout << this->heap_arr[0] << endl;
            return;
        }
        else {
            std::cout << "[peek]: empty" << endl;
            return;
        }
    }
};

int main(int argc, char *argv[])
{
    Heap heap;
    heap.insert(10);
    heap.insert(11);
    heap.insert(19);
    heap.del();
    heap.del();
    heap.peek();
    return 0;
}
