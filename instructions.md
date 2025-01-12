# Push Swap Project Instructions

## V.1 The Rules

### Stacks
- You have **two stacks** named `a` and `b`.
- **Initial State**:
  - Stack `a`: Contains a random number of integers (both positive and/or negative, no duplicates).
  - Stack `b`: Initially empty.

### Goal
Sort the numbers in **ascending order** in stack `a` using the following operations:

### Operations
1. **`sa` (swap a):**  
   Swap the first two elements at the top of stack `a`.  
   *Does nothing if there is only one or no elements.*

2. **`sb` (swap b):**  
   Swap the first two elements at the top of stack `b`.  
   *Does nothing if there is only one or no elements.*

3. **`ss`:**  
   Perform `sa` and `sb` simultaneously.

4. **`pa` (push a):**  
   Take the first element at the top of stack `b` and put it at the top of stack `a`.  
   *Does nothing if `b` is empty.*

5. **`pb` (push b):**  
   Take the first element at the top of stack `a` and put it at the top of stack `b`.  
   *Does nothing if `a` is empty.*

6. **`ra` (rotate a):**  
   Shift up all elements of stack `a` by 1.  
   The first element becomes the last one.

7. **`rb` (rotate b):**  
   Shift up all elements of stack `b` by 1.  
   The first element becomes the last one.

8. **`rr`:**  
   Perform `ra` and `rb` simultaneously.

9. **`rra` (reverse rotate a):**  
   Shift down all elements of stack `a` by 1.  
   The last element becomes the first one.

10. **`rrb` (reverse rotate b):**  
    Shift down all elements of stack `b` by 1.  
    The last element becomes the first one.

11. **`rrr`:**  
    Perform `rra` and `rrb` simultaneously.

---

## V.2 Example

To illustrate how some of these instructions work, here is an example of sorting a random list of integers. Both stacks grow from the right.

### Initial Stacks
```
Stack a: 2 1 3 6 5 8
Stack b: _
```

### Step-by-Step Operations

1. **`sa`**:
   ```
   Stack a: 1 2 3 6 5 8
   Stack b: _
   ```

2. **`pb pb pb`**:
   ```
   Stack a: 6 5 8
   Stack b: 3 2 1
   ```

3. **`ra rb` (equivalent to `rr`)**:
   ```
   Stack a: 5 8 6
   Stack b: 2 1 3
   ```

4. **`rra rrb` (equivalent to `rrr`)**:
   ```
   Stack a: 6 5 8
   Stack b: 3 2 1
   ```

5. **`sa`**:
   ```
   Stack a: 5 6 8
   Stack b: 3 2 1
   ```

6. **`pa pa pa`**:
   ```
   Stack a: 1 2 3 5 6 8
   Stack b: _
   ```

### Summary
- The integers from stack `a` are sorted in **12 instructions**.  
- **Challenge:** Can you do better?

---

## V.3 The Program

### Requirements
1. Write a program named `push_swap` that takes a list of integers as an argument.
   - The **first argument** corresponds to the **top of stack `a`**.
   - The program must output the smallest list of instructions needed to sort stack `a` in ascending order.
2. **Output**:
   - Instructions must be separated by a newline (`\n`) and nothing else.
3. **Error Handling**:
   - If no arguments are given, the program should output nothing.
   - For errors (e.g., invalid arguments, duplicates, non-integers, etc.), display `Error` followed by a newline on standard error.
4. **Rules**:
   - Global variables are forbidden.
   - Must include a `Makefile` to compile your source files (should not relink).
5. **Evaluation**:
   - The program will be tested for:
     - Correctness of sorting.
     - Minimization of the number of operations.

---

## V.4 Benchmark

### Validation Criteria
1. **Minimal Validation** (for a minimum grade of 80):
   - Sort **100 random numbers** in **fewer than 700 operations**.
2. **Maximal Validation** (to achieve bonuses):
   - Sort **500 random numbers** in **fewer than 5500 operations**.

--- 

