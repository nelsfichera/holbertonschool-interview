# 0. Radix sort
## Write a function that sorts an array of integers in ascending order using the Radix sort algorithm
- Prototype: void radix_sort(int *array, size_t size);
- You must implement the LSD radix sort algorithm
- You can assume that array will contain only numbers >= 0
- You are allowed to use malloc and free for this task
- You’re expected to print the array each time you increase your significant digit (See example below)
```
alexa@ubuntu-xenial:0x1B-radix_sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:0x1B-radix_sort$
```