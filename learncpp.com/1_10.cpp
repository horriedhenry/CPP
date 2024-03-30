#include <iostream>

/*

You're absolutely right. In the statement `int x = y = 10;`, it's not guaranteed which variable (`x` or `y`) gets assigned the value 10 first. Here's why:

**C++ Evaluation Order for Side Effects**

C++ doesn't enforce a specific order when evaluating expressions with side effects, like assignments in this case. The compiler has some leeway in how it performs the evaluation.

Here's a breakdown of what happens in `int x = y = 10;`:

1. **Expression Evaluation:** The expression `10` is evaluated first, resulting in the value 10.
2. **Side Effects (Uncertain Order):**
   - The assignment to `y` (`y = 10`) happens.
   - The assignment to `x` (`x = y`) happens.

The key point is that the order of these assignments (step 2) is not guaranteed by the C++ language standard. The compiler might assign 10 to `y` first, then use that assigned value to assign to `x`. Or, it might do it the other way around.

**Why This Doesn't Usually Matter**

In most practical scenarios, the order in which `x` and `y` receive the value 10 doesn't affect the final outcome of the program. They both end up with the same value (10) at the end.

**When Order Might Matter**

However, there are rare cases where the order of evaluation can lead to unexpected behavior. This could happen if the values of `x` and `y` are used in a complex calculation that relies on a specific assignment order.

**Best Practices**

To avoid potential issues and make your code more readable, it's generally recommended to perform separate assignments for clarity:

```c++
int x = 10;
int y = 10;
```

This ensures that both `x` and `y` are explicitly assigned the value 10 in a well-defined order.

By understanding the concept of side effects and evaluation order, you can write more predictable and maintainable C++ code. 

*/

int main (int argc, char *argv[])
{
    // Part of Bard's Explanation
    int y;
    int x = y = 10; // the order of evaluation is not guaranteed.
    // or 
    // int x { y = 5 };
    std::cout << y << "\n";
    // 2 + 3; clang: Expression result unused [-Wunused-value]
    return 0;
}
