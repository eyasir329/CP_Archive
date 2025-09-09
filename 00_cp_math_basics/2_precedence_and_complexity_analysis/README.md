# Precedence & Complexity Analysis

## 📚 Table of Contents

- [Operator Precedence & Associativity](#operator-precedence)
- [Exponential and Logarithmic Functions](#exponential-and-logarithmic-functions)
- [Time and Space Complexity](#time-and-space-complexity)
- [Example of Complexity Analysis](#example-of-complexity-analysis)
- [Algorithm Complexity Table](#algorithm-complexity-table)
- [Common Complexities & Constraints](#common-complexities--constraints)
- [Memory Initialization](#memory-initialization)

---

## Operator Precedence

- Official reference: [C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

![Operator Precedence Table](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjDm_FtxeGKfyUhd-byPJ8Y34EKecgA7GwKXuF_IxJPrE4TKqzOsdZKybAkHC42NM7rs74hUzIklDTlhFCzq1RdLJm4sonfEEuA6fFSbP9SDXUfCicb2HO2kFimKV58CGr9Rx3RYsXR04Ie/s1600/untitled_thumb.png)

- before post then pre (inc/dec)
- (\*,/,%) has same priority

---

## Associativity

- left associativity (+,-,\*,/ ...)
- right associativity (=,exp, pre-incre/decrement, ternary operator, logical(!)/bitwise not(~), (+=, -=, \*=, /=, %=, <<=,>>=,&=,^=,|=))

```
a = b = c; => a = (b = c)
```

## Exponential and Logarithmic Functions
> The logarithm of a number x to the base b is the power to which b must be raised to get x.

- $a^k = x \Rightarrow \log_a(x) = k$

| $x$ | $2^x$     | $\log_2(Y)$ (where $Y = 2^x$) |
| --- | --------- | ----------------------------- |
| 20  | $10^6$    | 19.9                          |
| 30  | $10^9$    | 29.9                          |
| 60  | $10^{18}$ | 59.8                          |

> - Exponential functions grow very quickly — doubling with every increment of $k$.
> - Logarithms are the inverse of exponentials.
> - Logarithm answers: _How many times do we multiply a base to get a number?_

Example:

$$
2^3 = 8 \quad \Rightarrow \quad \log_2(8) = 3
$$

---
> Natural logarithms are logarithms to the base e. (e~2.71828) -> ln(x)
### 🔁 Repeated Division Idea

- Divide a number by 2 (or any base $k$) repeatedly until it becomes 1.
- Number of divisions ≈ $\lfloor \log_k N \rfloor$

Example problem:
[2020A_Find Minimum Operations](./5_basic_maths/divisors_modulo/2020A_Find%20Minimum%20Operations.cpp)

---

### Logarithm Properties (Reference: [Cuemath](https://www.cuemath.com/log-formulas/))

![Logarithm Properties](https://storage.googleapis.com/wzukusers/user-19977666/images/5866e108c1fb01HOWam7/Logarithm-properties-ultimate-cheat-sheet-formula-product-quotient-power-root-inverse-identity-zero-change-equality-reciprocal_d600.PNG)

---

### 🧠 Additional Notes

- Change of base formula:

$$
\log_3(100) = \frac{\log_2(100)}{\log_2(3)}
$$

- Number of digits of $N$ in base $k$:

$$
\lfloor \log_k(N) \rfloor + 1
$$

---

### 📊 Digits in Factorial $n!$ (for $n \leq 10^5$)

Using log properties:

```cpp
double sum = 0;
for (int i = 1; i <= n; i++) {
    sum += log10(i);
}
cout << floor(sum) + 1 << endl;
```

---

## Time and Space Complexity

- [USACO Time Complexity Guide](https://usaco.guide/bronze/time-comp?lang=cpp)
- Big-O notation expresses **worst-case time complexity** as input size $n$ grows.

![Time Complexity Chart](https://miro.medium.com/v2/resize:fit:1400/1*xq73u1N7ZsTE2MJ9jsj0CA.png)

---

### ⚙️ Time & Memory Considerations

- $1s \approx 10^8$ operations (typical modern CPU)
- Time Taken $ \approx f(N)/10^8$ s
  > if n = 1e5, f(n) = n^2 + 5n + 10 => f(N) = 1e10; (1e10/1e8 = 100s)

#### Array Sizes & Memory Use

| Type                      | Size               | Notes                                         |
| ------------------------- | ------------------ | --------------------------------------------- |
| `bool` array              | $n \times 1$ byte  | 1 MB = $10^6$ bytes; slower than vector<bool> |
| `vector<bool>` / `bitset` | $n \times 1$ bit   | Compact representation                        |
| `vector<int>`             | $n \times 4$ bytes | 1 byte = 8 bits                               |

---

#### Example: 256 MB Memory Limit

> 256 MB ~ 256 * 1024 * 1024 bytes

For `int` arrays:

$$
(4 \times x) / 10^6 = 256 \Rightarrow x = 6.4 \times 10^7
$$

> upto 6.4e7 integer variable can be store

- Memory Taken $$ \approx \sum f(N) \times (4\ \text{bytes}) \approx \frac{x}{1024 \times 1024}\ \text{MB} $$

  > if n = 500, f(n) = n + n^3 => f(N) = 500*4 + 500^3 * 4 = (x/1024/1024) MB = 476.837 MB, 4 for int type variable

`bitset` can handle up to $\sim 10^9$ bits.

---

### ⚠️ Big-O Tips

- Ignore constant factors (e.g., $O(2n) = O(n)$)
- Focus on dominant terms for large inputs

---

## Example of Complexity Analysis

### 🧠 Complex Function Example – Nested Loops with Conditions

### 🔧 Function

```cpp
int countPairs(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if ((nums[i] + nums[j]) % 2 == 0) {
                ++count;
            }
        }
    }
    return count;
}
```

---

### 📈 Step-by-Step Time Complexity Analysis

### Step 1: Outer Loop

Runs $n$ times, where $n = nums.size()$.

### Step 2: Inner Loop

For each $i$, inner loop runs $(n - i - 1)$ times. Total inner loop executions:

$$
(n-1) + (n-2) + \dots + 1 = \frac{n(n-1)}{2}
$$

### Step 3: Condition Check

Constant time $O(1)$.

---

### 🧮 Final Time Complexity

$$
T(n) = \frac{n(n-1)}{2} \times O(1) = O(n^2)
$$

---

### 📦 Space Complexity

Only uses an integer `count` → $O(1)$.

---

### ✅ Optimization Idea

Because sum is even if both numbers are even or both are odd:

- Count evens and odds separately.
- Calculate pairs from evens and odds individually.

### Optimized Code

```cpp
int countPairsOptimized(vector<int>& nums) {
    int even = 0, odd = 0;
    for (int num : nums) {
        if (num % 2 == 0) ++even;
        else ++odd;
    }
    return (even * (even - 1)) / 2 + (odd * (odd - 1)) / 2;
}
```

---

### ⏱ Time Complexity (Optimized)

- One pass over array: $O(n)$
- Constant-time arithmetic: $O(1)$

Total: $O(n)$

### 📦 Space Complexity

Still $O(1)$.

---

## 📊 Summary

| Version     | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute-force | $O(n^2)$        | $O(1)$           |
| Optimized   | $O(n)$          | $O(1)$           |

---

### 🧠 Recursive Function Example – Subset Sum

**Problem**: Given array `arr[]` and integer `target`, determine if subset exists with sum exactly `target`.

### Recursive Code

```cpp
bool isSubsetSum(vector<int>& arr, int n, int target) {
    if (target == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] > target)
        return isSubsetSum(arr, n - 1, target);

    return isSubsetSum(arr, n - 1, target) ||
           isSubsetSum(arr, n - 1, target - arr[n - 1]);
}
```

---

### 🔎 Time Complexity Derivation

- Each element → two choices: include or exclude.
- At each step, recursive calls double → binary recursion tree.

Number of calls:

$$
T(n) = 2^n
$$

Because:

$$
\sum_{i=0}^{n} 2^i = 2^{n+1} - 1 = O(2^n)
$$

**Time complexity**:

$$
O(2^n)
$$

---

### 📦 Space Complexity Derivation

- Maximum recursion depth = $n$ → stack holds $n$ calls
- Space complexity:

$$
O(n)
$$

---

### 🔁 With Memoization

- Store computed results for each $(n, target)$ pair.
- Number of states: $n \times (target+1)$
- Each state computed once →

$$
O(n \times target)
$$

- Space for DP + stack:

$$
O(n \times target)
$$

---

## ✅ Summary Table

| Version         | Calls per node | Total Nodes       | Time Complexity      | Space Complexity     |
| --------------- | -------------- | ----------------- | -------------------- | -------------------- |
| Naive Recursion | 2              | $2^n$             | $O(2^n)$             | $O(n)$               |
| Memoization     | 1 (cached)     | $n \times target$ | $O(n \times target)$ | $O(n \times target)$ |

---

## Time Complexities Examples

| #   | Complexity         | Code Example          | Max Input (1s)                 |
| --- | ------------------ | --------------------- | ------------------------------ |
| 1   | $O(1)$             | Access first element  | Any size                       |
| 2   | $O(\log n)$        | Binary Search         | $n \leq 10^{18}$ (theoretical) |
| 3   | $O(\sqrt{n})$      | Prime Check           | $n \leq 10^{16}$               |
| 4   | $O(n)$             | Find Max              | $n \leq 10^{8}$                |
| 5   | $O(n \log n)$      | Merge Sort            | $n \leq 10^{6}$                |
| 6   | $O(n \log^2 n)$    | FFT                   | $n \leq 10^{5}$                |
| 7   | $O(n \log \log n)$ | Sieve of Eratosthenes | $n \leq 10^{7}$                |
| 8   | $O(n^2)$           | Bubble Sort           | $n \leq 10^{4}$                |
| 9   | $O(n^3)$           | Floyd-Warshall        | $n \leq 500$                   |
| 10  | $O(n^4)$           | 4D DP                 | $n \leq 100$                   |
| 11  | $O(2^n)$           | Fibonacci (naive)     | $n \leq 25$                    |
| 12  | $O(n \times n!)$   | Permutations          | $n \leq 10$                    |

> n \* sqrt(n), n <= 1e5

---

## Algorithm Complexity Table

- See full table in [USACO PAPS.pdf, page 99](https://usaco.guide/PAPS.pdf#page=99)

![Algorithm Table](https://i.ibb.co/gJcN1Q4/Screenshot-from-2024-10-11-00-22-26.png)

---

## Common Complexities & Constraints

- $O(1)$: Mathematical formula
- $O(\log n)$: Binary search, map/set access
- $O(n)$: Reading input, simple loops
- $O(n \log n)$: Sorting algorithms like mergesort
- $O(n^2)$: Nested loops for pairs
- $O(n^k)$: Size-k subsets (e.g., triplets $O(n^3)$)
- $O(2^n)$: All subsets
- $O(n!)$: All permutations

---

## Memory Initialization

### 🧵 `memset` – Byte-Level Initialization

```cpp
// works byte by byte
char s[10];
memset(s, 'a', 5); // first five replaced by 'a'
s[5] = '\0';
cout << s << endl;
```

```cpp
// For int (4 bytes), long long (8 bytes):
int a[10];
memset(a, 0, 10 * sizeof(int));        // initializes all elements to 0
memset(a, -1, 10 * sizeof(int));       // sets all bytes to 0xFF, often -1 for ints

// Works for multi-dimensional arrays as well:
memset(a, 0, sizeof(a));
```

---

### 🧩 `fill` – Value-Wise Initialization

```cpp
// Works for any number type
fill(a, a + n, x);
```

- `memset` is faster but limited to byte-wise patterns.
- Global variables are zero-initialized by default; locals are not.
- For large arrays, prefer global declaration (stored in data segment, larger than stack).

---
