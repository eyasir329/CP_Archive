# 📚 Table of Contents

* 🔢 [Operator Precedence](#-operator-precedence)
* 📈 [Exponential and Logarithmic Functions](#-exponential-and-logarithmic-functions)
* ⏱️ [Time and Space Complexity](#-time-and-space-complexity)
* 🧮 [Algorithm Complexity Table](#-algorithm-complexity-table)
* 🔍 [Common Complexities & Constraints](#-common-complexities--constraints)
* 🧼 [Memory Initialization](#-memory-initialization)

---

## 🔢 Operator Precedence

* [Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

  ![Operator Table](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjDm_FtxeGKfyUhd-byPJ8Y34EKecgA7GwKXuF_IxJPrE4TKqzOsdZKybAkHC42NM7rs74hUzIklDTlhFCzq1RdLJm4sonfEEuA6fFSbP9SDXUfCicb2HO2kFimKV58CGr9Rx3RYsXR04Ie/s1600/untitled_thumb.png)

---

## 📈 Exponential and Logarithmic Functions

* $a^k = x \Rightarrow \log_a(x) = k$

|  x  |   $2^x$   | $\log_2(Y)$<br/>(where $Y = 2^x$) |
| :-: | :-------: | :-------------------------------: |
|  20 |   $10^6$  |                19.9               |
|  30 |   $10^9$  |                29.9               |
|  60 | $10^{18}$ |                59.8               |

---

### 🔁 Repeated Division Idea

* Some number, every time divide it by 2 (or $k$) until it becomes 1
  → **How many operations?** → $\lfloor \log_k(N) \rfloor$

[2020A\_Find Minimum Operations](./5_basic_maths/divisors_modulo/2020A_Find%20Minimum%20Operations.cpp)

* [Log formulas – Cuemath](https://www.cuemath.com/log-formulas/)

![Log Properties](https://storage.googleapis.com/wzukusers/user-19977666/images/5866e108c1fb01HOWam7/Logarithm-properties-ultimate-cheat-sheet-formula-product-quotient-power-root-inverse-identity-zero-change-equality-reciprocal_d600.PNG)

---

### 🧠 Other Logarithmic Notes

* $\log_3(100) = \frac{\log_2(100)}{\log_2(3)}$
* **Number of digits in base $k$**:

  $$
  \lfloor \log_k(N) \rfloor + 1
  $$

---

### 📊 Digits in Factorial $n!$ (for $n \leq 10^5$)

* Using log product property:

```cpp
double sum = 0;
for (int i = 1; i <= n; i++) {
    sum += log10(i);
}
cout << floor(sum) + 1 << endl;
```

---

## ⏱️ Time and Space Complexity

* [USACO Time Complexity Guide](https://usaco.guide/bronze/time-comp?lang=cpp)

* Big O notation expresses **worst-case** time complexity as a function of $n$ as $n$ grows large.

![Time Complexity Chart](https://miro.medium.com/v2/resize\:fit:1400/1*xq73u1N7ZsTE2MJ9jsj0CA.png)

---

### ⚙️ Memory Considerations

* 1s ⟷ $10^8$ operations

#### Array Sizes & Memory Use

* `bool` array → $n \times 1$ byte
  *(1MB = bytes / 1e6)*
  *(8x slower than vector<bool>)*

* `vector<bool>` / `bitset` → $n \times 1$ **bit**

* `vector<int>` → $n \times 4$ bytes
  *(1 byte = 8 bits)*

#### 256MB Limit (int array example)

```
4x / 1e6 = 256
→ x = 6.4e7
```

> **bitset** can go up to \~1e9+

---

### ⚠️ Big-O Tips

* In Big-O notation, **ignore constant factors**

---

## 🧮 Algorithm Complexity Table

* [Full Table (PAPS.pdf → Page 99)](https://usaco.guide/PAPS.pdf#page=99)

![Algorithm Table](https://i.ibb.co.com/gJcN1Q4/Screenshot-from-2024-10-11-00-22-26.png)

* Also covered in:
  [https://usaco.guide/bronze/time-comp?lang=cpp](https://usaco.guide/bronze/time-comp?lang=cpp)

---

## 🔍 Common Complexities & Constraints

* **O(1)** – Mathematical formula

* **O(log n)** – Binary search, map/set access

* **O(n)** – Reading input, simple loops

* **O(n log n)** – Sorting (e.g., mergesort)

* **O(n²)** – Java `Arrays.sort()` worst case (quicksort)

* **O(n^k)** – All size-k subsets (e.g. triplets → O(n³))

* **O(2^n)** – All subsets → `(1 << n)`

* **O(n!)** – All permutations

---

## 🧼 Memory Initialization

### 🧵 `memset` – Byte-Level Initialization

```cpp
// works byte by byte
char s[10];
memset(s, 'a', 5); // first five replaced by 'a'
s[5] = '\0';
cout << s << endl;
```

```cpp
// int = 4 bytes, long long = 8 bytes
// accidental correctness for (0/-1)
int a[10];
memset(a, 0, 10 * 4); // a[0] = 4 bytes
// for long long:
memset(a, 0, 10 * 8); // a[0] = 8 bytes

// also works for multi-dimensional:
memset(a, 0, sizeof(a));
```

---

### 🧩 `fill` – Value-Wise Initialization

```cpp
// works for every number type
fill(a, a + n, x);
```

* `memset` is faster than `fill`, but both are **O(n)**
* By default, **global variables are zero-initialized**, but **local variables are not**
* Declare **large arrays globally** (stored in **data segment**, which is larger than **stack**)

---