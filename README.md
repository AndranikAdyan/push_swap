# 📦 push\_swap

> A 42 project that sorts a stack of integers using only a constrained set of stack operations.
> This implementation uses a **Butterfly sort** (an optimized Radix sort) for efficiency with large data sets.

---

## 🧠 Project Objective

Create a program that receives a list of integers and sorts them using two stacks (**A** and **B**) and a limited set of allowed operations. The challenge is to write the most **optimized** solution in terms of **operation count**.

---

## ⚙️ Allowed Operations

| Operation | Description                           |
| --------: | ------------------------------------- |
|      `sa` | Swap the top two elements of stack A  |
|      `sb` | Swap the top two elements of stack B  |
|      `ss` | `sa` and `sb` at the same time        |
|      `pa` | Push the top of B onto A              |
|      `pb` | Push the top of A onto B              |
|      `ra` | Rotate A up (first becomes last)      |
|      `rb` | Rotate B up                           |
|      `rr` | `ra` and `rb` at the same time        |
|     `rra` | Reverse rotate A (last becomes first) |
|     `rrb` | Reverse rotate B                      |
|     `rrr` | `rra` and `rrb` at the same time      |

---

## 🏗️ Build Instructions

```bash
make
```

This will generate the executable:

```
./push_swap
```

To clean object files:

```bash
make clean
```

To remove all binaries:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

---

## 🚀 Usage

```bash
./push_swap <list_of_integers>
```

### Example:

```bash
./push_swap 3 2 1
```

Output:

```bash
sa
rra
```

You can verify correctness using the `checker` program (bonus part):

```bash
make bonus
```

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Expected output: `OK`

---

## 🧮 Sorting Algorithm – Butterfly Sort

This project uses an optimized **Butterfly Sort**, a variant of **Radix Sort**, designed specifically for stack-based sorting using push\_swap operations.

### How It Works:

1. Normalize all numbers to indexes (i.e. map the smallest number to 0, next to 1, etc.).
2. Loop through each bit from LSB to MSB of the max index.
3. For each bit:

   * If bit is 0 → `pb`
   * If bit is 1 → `ra`
4. After each pass, return all elements from stack B back to stack A (`pa`).
5. Repeat until fully sorted.

### Why Butterfly Sort?

* **O(n log n)** performance
* Very few operations (\~700–1500 for 100 numbers, \~5000–7000 for 500)
* Easy to implement and debug
* Works extremely well with bit manipulation

---

## 🧪 Input Validation

* Handles negative numbers
* Detects duplicates
* Checks for non-integer input
* Handles values beyond 32-bit signed int range

---

## ✅ Project Constraints

* No use of standard sorting functions
* Only allowed C standard library functions: `write`, `malloc`, `free`, `exit`
* Must be fully **Norminette-compliant**
* Must handle edge cases (already sorted, one number, invalid input, etc.)

---

## 📊 Performance Benchmarks (Typical)

| Size | Target Ops (42) | Butterfly Sort (avg) |
| ---- | --------------- | -------------------- |
| 5    | ≤ 12            | 2–8                  |
| 100  | ≤ 700           | \~500–700            |
| 500  | ≤ 5500          | \~4500–5500          |
