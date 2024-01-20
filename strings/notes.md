# char array

Excalidraw : 

- char arrays are different in c++, not similar to that of c.

```c++
    char arr[] = "s"; // works
    char arr[10] = "shiva"; // works
    std::cout << arr;
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "size : " << size << "\n";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        std::cout << arr[i];
    }
```

- Need not to specify size for character array `std::cout << arr;` prints `shiva`
  No loop required to print each character.
- If you specify size dynamically `char arr[10] = "shiva";` the remaining chars
  in the array will be null or just empty character.
- `char arr[] = "s"` the size of this is 2. 
- `char arr[10] = "shiva"` the size of this is `10` and we just use 5 , and the
  remaining slots will be empty.

