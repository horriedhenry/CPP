- [Recursion(CS)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Recursion](https://en.wikipedia.org/wiki/Recursion)

# Recursion

```c++
void prt_nbr(int n) {
    std::cout << n << " " << std::endl;
    prt_nbr(n + 1);
}
```

- Output

```bash
261794
261795
261796
261797
r.sh: line 1: 12112 Segmentation fault      (core dumped) ./a
```

- prints numbers till `261797` and then seg faults coz there is not stop. 
- Example for a `for` loop to get out of it we have some kind of a variable that check's if it is in bounds, and in similar way for a while loop there is a condition, till that condition is true it goes on.

```c++
void prt_nbr(int n) {
    std::cout << n << " " << std::endl;
}

int main (int argc, char *argv[]) {
    for (int i = 0; i < 5; i++){
        prt_nbr(i);
    }
    return 0;
}
```

- output
```console
0
1
2
3
4
```

- similarly for a `while` loop it looks something like this
```c++
int i = 0;
while (i <= 5) {
	prt_nbr(i);
	i++;
}
```

- output
```console
1
2
3
4
5
```

- if we look at the pattern, there is some kind of a `condition` which checks to continue looping or to stop.Let's to the same with recursion, but before that.. there is something called as [call stack](https://en.wikipedia.org/wiki/Call_stack).

# Call Stack

- Reference : [Call stack](https://en.wikipedia.org/wiki/Call_stack)

- The call stack is a **temporary memory** that keeps track of **active functions** and **where they should return to** when they're done. it is like a **stack of activation records**, each representing a currently running function.

### Function Call

- when you call a function, it's **activation record** is pushed onto the call stack. this record stores information like :
  - **local variables** of the function.
  - the **return address** : the instruction to return to after the function finished executing.

### Function Execution

- The program starts executing the called function.

### Function Completion

- When the function finishes, its activation record is **popped** from the stack. This means:
	- **Local variables** are no longer accessible
	- Control returns to the instruction at the **return address**


### Importance

- `Nested Calls     :` Allows functions to call other functions, forming a hierarchy. The call stack keeps track of the nesting and ensures each function returns to its correct caller.
- `Return Mechanism :` Provides a way for functions to return control to the point where they were called, ensuring proper program flow.
- `Error Handling   :` Helps identify errors like trying to access variables from a function that has already finished (as its activation record is no longer on the stack).

# TODO : notes are undone
