_This project has been created as part of the 42 curriculum by bdayakli, bayseven._

# Push_Swap: The Adaptive Sorting Algorithm

## Description
The Push_Swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks. The goal is to write a C program which calculates and displays on the standard output the smallest program, made of Push_Swap language instructions, that sorts the integers received as arguments.

**Project Overview:**
This repository contains a custom, highly optimized implementation of Push_Swap. Unlike standard implementations that use a single algorithm for all inputs, our program features an **Adaptive Sorting Engine**. It analyzes the input data, calculates a "disorder percentage," and dynamically selects the most efficient sorting strategy. It also includes a custom benchmarking mode to log time complexity, operation counts, and strategy details without interfering with the standard output.

---

## Instructions

### Compilation
To compile the project, simply use the provided Makefile at the root of the repository.

```bash
# Compile the main executable
make

# Clean object files
make clean

# Clean everything including the executable
make fclean

# Recompile entirely
make re
```

### Execution
Run the program with a list of integers formatted as a single string or multiple arguments.

```bash
# Standard execution
./push_swap 4 67 3 87 23

# Execution with custom flags
./push_swap --complex 4 67 3 87 23
```

**Available Flags:**
* `--simple`: Forces the Simple strategy (Selection/Bubble based).
* `--medium`: Forces the Medium strategy (Chunking/Bucket based).
* `--complex`: Forces the Complex strategy (Radix bitwise sort).
* `--adaptive`: Analyzes the disorder and chooses automatically (Default behavior if no flag is provided).
* `--bench`: Logs benchmark data (disorder percentage, strategy name, total operations, etc.) to the standard error (`stderr`).

*Example of benchmarking:*
```bash
./push_swap --bench --adaptive 5 4 3 2 1 2> bench.log > /dev/null && cat bench.log
```

---

## Algorithm Explanation and Justification

Our implementation relies on multiple strategies to ensure the lowest possible instruction count across different dataset sizes and states.

### 1. Simple Strategy (O(n^2))
* **Explanation:** A straightforward approach (similar to Selection Sort) that iteratively finds the smallest element and pushes it to Stack B, then returns them to Stack A.
* **Justification:** While O(n^2) is mathematically inefficient for large inputs, it produces extremely short instruction sets for very small arrays (e.g., 3 to 5 numbers) or arrays that are already nearly sorted. The overhead of complex algorithms is unnecessary here.

### 2. Medium Strategy (O(n√n))
* **Explanation:** Uses a chunking or bucket approach. The data is divided into proportional segments, allowing us to push chunks of numbers to Stack B and then sort them as they return to Stack A.
* **Justification:** This serves as a middle-ground optimization. It is highly effective for medium-sized inputs where O(n^2) becomes too expensive, but the strict bitwise operations of Radix might do more rotations than necessary.

### 3. Complex Strategy (O(n log n) / Radix O(d * n))
* **Explanation:** We implemented a bitwise **Radix Sort**. Before sorting, the input is compressed into indexes (Coordinate Compression) to handle negative numbers and large gaps. Then, the algorithm sorts the numbers based on their binary representation using bitwise right shift (`>>`) and AND (`& 1`) operations.
* **Justification:** This is the core of our large-input sorting (100 to 500 numbers). By separating 0s and 1s at the bit level, we ensure a stable, highly predictable execution time. It easily passes the strict 42 performance requirements (<700 operations for 100 numbers, <5500 for 500 numbers).

### 4. Adaptive Strategy (Default)
* **Justification:** A one-size-fits-all approach is flawed. We calculate the "distance" of each number from its target position to generate a **Disorder Percentage**. Based on this percentage and the total element count, the program automatically routes the data to the Simple, Medium, or Complex engine, ensuring maximum efficiency dynamically.

---

## Resources

**Classic References:**
* *Push_Swap visualizers:* Used extensively to debug stack movements.
* *Radix Sort and Bitwise Operations:* Researched standard binary sorting implementations and two's complement behavior with negative integers.
* *Coordinate Compression:* Studied indexing techniques to map arrays to `0...N-1` safely.

**AI Usage:**
AI was utilized during the development of this project for the following specific tasks:
1.  **Refactoring and Norminette:** Used AI to brainstorm ways to reduce line counts in core functions to comply with the strict 42 Norminette 25-line rule, specifically by conceptualizing the removal of redundant variables.
2.  **Theoretical Understanding:** Discussed the mathematical difference between O(n log n) and Radix Sort's actual O(d * n) complexity to better prepare for the peer evaluation defense.
3.  **Documentation Formatting:** Assisted in structuring and drafting this `README.md` to ensure all evaluation requirements and markdown formatting standards were met professionally.