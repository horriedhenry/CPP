# Resources 

- [Big(O) CheatSheet](https://www.bigocheatsheet.com/)


# Time & Space Complexity

- `Time Complexity  :` Measure of how the runtime of an algorithm grows with the size of its input. It provides an understanding of how the algorithm performs as the input size increases.
- `Space Complexity :` Amount of memory an algorithm requires to execute as a function of the size of its input. It measures how much additional memory (beyond the input itself) is needed by the algorithm to store temporary variables, data structures, and other internal variables during its execution.

# Time Complexity

## O(n) - Linear Time

- When we say an algorithm has a time complexity of O(n), we mean that the time it takes to run the algorithm grows linearly with the size of the input.
- Let's understand with this example.
- Given an array iterate through every element and mark it as `0`.
- input `arr = {1, 2, 3, 4, 5, 6, 7}`

```c++
void linear_time(std::vector<int> arr, int key) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}
```

- To complete this operation, the best and worst case time complexity is `O(n)`, coz we have to visit each and every element no matter what. Here `n` is the size of the array, and n grows linearly.
