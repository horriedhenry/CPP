# Resources

- [Big(O) CheatSheet](https://www.bigocheatsheet.com/)

- [Big_O_notation](https://en.wikipedia.org/wiki/Big_O_notation)

- [ThePrimeagen fem](https://theprimeagen.github.io/fem-algos/lessons/algorithms-and-time-space-complexity/time-and-space-complexity)

- [Ben Awad](https://www.youtube.com/watch?v=uHjPTUpQOAk&t=8s)

# Big O

- Big O is a way to categorize your algorithms time or memory requirements based on input. It is not meant to be an exact measurement. It will not tell you how many CPU cycles it takes, instead it is meant to generalize the growth of you algorithm.
- Example, when someone says Oh of N, they mean your algorithm will grow linearly based on input.

### Why do we use it

- Often it will help us make decisions about what data structures and algorithms to use. Knowing how they will perform can greatly help create the best possible solution or program/algorithm.

### Big O, said differently

- As you input grows how fast does computation or memory grow.
- **Growth** is with respect to the input.
- **In the real world...** Obviously memory growing is not computationally free, but in the matter of thinking about algorithms we don't necessarily think aobut that.

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
