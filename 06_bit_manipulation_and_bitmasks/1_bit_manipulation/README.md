# 🧠 Bit Manipulation Deep Dive

A comprehensive guide to bitwise operations, their techniques, C++ built-ins, and problem links.

---

## 📚 Table of Contents
- [Basic Boolean Operations](#🧩-basic-boolean-operations)
- [Basic Technique](#🔧-basic-technique)
- [Basic Bitwise Operation](#📍-basic-bitwise-operation)
- [Built-in Functions in C++](#⚙️-built-in-functions-in-c)
- [The Bit Law](#🧪-the-bit-law)
- [Bitwise OR](#🧪-bitwise-or)
- [Bitwise AND](#🧪-bitwise-and)

---

## 🧩 Basic Boolean Operations

<details>
  <summary><strong>Basic</strong></summary>

| Operation | Symbol | Description       | Example     |
|----------:|:------:|-------------------|-------------|
| AND       |   `·`  or `∧` | True if both are true | `A ∧ B` |
| OR        |   `+`  or `∨` | True if at least one is true | `A ∨ B` |
| NOT       |   `¬`  or `'` | Inverts the value      | `¬A` or `A'` |
| XOR       |   `⊕`  | True if only one is true | `A ⊕ B` |

</details>


<details>
  <summary><strong>Truth Table</strong></summary>

| A | B | ¬A | A ∧ B | A ∨ B | A ⊕ B |
|---|---|----|--------|--------|--------|
| 0 | 0 |  1 |   0    |   0    |   0    |
| 0 | 1 |  1 |   0    |   1    |   1    |
| 1 | 0 |  0 |   0    |   1    |   1    |
| 1 | 1 |  0 |   1    |   1    |   0    |

</details>


<details>
  <summary><strong>Fundamental Laws</strong></summary>

### Identity Laws
- `A + 0 = A`
- `A · 1 = A`

### Null Laws
- `A + 1 = 1`
- `A · 0 = 0`

### Idempotent Laws
- `A + A = A`
- `A · A = A`

### Involution Law
- `(A')' = A`

### Complement Laws
- `A + A' = 1`
- `A · A' = 0`

</details>

<details>
  <summary><strong>Duality Principle</strong></summary>

> **Interchange** `+` and `·`, and **swap** `0` and `1` — the expression still holds.

Example:  
- Original: `A + 0 = A`  
- Dual: `A · 1 = A`

</details>


<details>
  <summary><strong>DeMorgan’s Theorems</strong></summary>

- `(A · B)' = A' + B'`
- `(A + B)' = A' · B'`

Used for simplifying and implementing logic circuits using only NAND/NOR gates.

</details>

<details>
  <summary><strong>Boolean Identities</strong></summary>

| Law Type       | Expression              |
|----------------|-------------------------|
| **Double Negation** | `(A')' = A`            |
| **Absorption**      | `A + A·B = A`          |
| **Distributive**    | `A · (B + C) = A·B + A·C` |
| **Associative**     | `A + (B + C) = (A + B) + C` |
| **Commutative**     | `A + B = B + A`        |
| **Consensus**       | `A·B + A'·C + B·C = A·B + A'·C` |

</details>


---
### 🔧 Basic Technique

🔗 [Codeforces Blog: Bit Tricks by Errichto](https://codeforces.com/blog/entry/73490)

- Bitwise operations must be thought of **bit by bit** – decimal intuition often misleads.
- Always use **parentheses** for clarity with bitwise expressions.
- **Left Shift**:  
  `(x << k)` = `x × 2^k`  
  Example: `(1 << 3) = 8`
- **Right Shift**:  
  `(x >> k)` = `x ÷ 2^k`
- `(1 << n)` = `2^n`
- Use `(1LL << k)` for `long long` (to avoid overflow beyond 2³¹−1)
- `~a == ~-a` (bitwise NOT)
- XOR: `(a ^ b)` gives `1` only if bits differ.

### ⬅️ Left vs Right Shift Example

```
LEFT SHIFT                         RIGHT SHIFT
  13 =     1101                      13 =   1101
```
```
(13 << 2) =   110100              (13 >> 2) =     11
```

### 🧠 Bitwise Insights

```
* x & 1 = last bit = 1 if odd, 0 if even

* x & 1 = x  |  x & 0 = 0

* For any integer n:

  * (x & n) ≤ n (AND gives smaller/equal)
  * (x | n) ≥ n (OR gives larger/equal)
  * (x ^ n): unpredictable, depends on bits

* Subarrays:

  * min AND value → entire array
  * max OR value → entire array
  * max AND/min OR → subarrays of length 1
````

---

## 📍 Basic Bitwise Operation


### <u> Check if a bit is set</u>
```cpp
bool isBitSet(int num, int bitPos) {
    return (num & (1 << bitPos)) != 0;
}

bool isBitSet(int num, int bitPos) {
    return (num >> bitPos) & 1;
}
```

### <u> Count set bits (population count)</u>
```cpp
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
```

### <u> Check if number is even/odd</u>
```cpp
bool isEven(int num) { return (num & 1) == 0; }
bool isOdd(int num) { return (num & 1) != 0; }
```

## Bit Modification

### <u> Set a bit</u>
```cpp
int setBit(int num, int bitPos) {
    return num | (1 << bitPos);
}
```

### <u> Clear a bit</u>
```cpp
int clearBit(int num, int bitPos) {
    return num & ~(1 << bitPos);
}
```

### <u> Toggle a bit</u>
```cpp
int toggleBit(int num, int bitPos) {
    return num ^ (1 << bitPos);
}
```

## Mathematical Operations

### <u> Multiply/Divide by 2</u>
```cpp
int multiplyByTwo(int num) { return num << 1; }
int divideByTwo(int num) { return num >> 1; }  // For positive numbers
```

### <u> Power of 2</u>
```cpp
int powerOfTwo(int exponent) { return 1 << exponent; }
```

### <u> Check if power of 2</u>
```cpp
bool isPowerOfTwo(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}
```

## Utility Functions

### <u> Print all set bits</u>
```cpp
void printSetBits(int num) {
    cout << "Set bits: ";
    for (int i = 0; i < sizeof(int)*8; i++) {
        if (num & (1 << i)) cout << i << " ";
    }
    cout << endl;
}
```

### <u> Print all unset bits</u>
```cpp
void printUnsetBits(int num) {
    cout << "Unset bits: ";
    for (int i = 0; i < sizeof(int)*8; i++) {
        if (!(num & (1 << i))) cout << i << " ";
    }
    cout << endl;
}
```

## Notes
- All operations assume 32-bit integers by default
- For unsigned operations, use `unsigned int`
- Many compilers provide built-ins like `__builtin_popcount()` for faster bit counting
- Right shift behavior differs for signed vs unsigned numbers

## Right Shift Behavior: Signed vs Unsigned

### Key Difference
- **Unsigned numbers**: Right shift performs _logical shift_ (fills with 0s)
- **Signed numbers**: Right shift performs _arithmetic shift_ (fills with sign bit)

### Examples

### 1. Unsigned Right Shift (Logical Shift)
```cpp
unsigned int u = 0b10001100; // 140
u = u >> 2;
// Result: 0b00100011 (35)
// Fills left bits with 0s
```

### 2. Positive Signed Right Shift (Same as unsigned)
```cpp
int s = 0b00001100; // 12
s = s >> 2;
// Result: 0b00000011 (3)
// Fills left bits with 0s (same as unsigned)
```

### 3. Negative Signed Right Shift (Arithmetic Shift)
```cpp
int s = 0b10001100; // -116 (assuming 8-bit 2's complement)
s = s >> 2;
// Result: 0b11100011 (-29)
// Fills left bits with 1s (preserves sign)
```
---

## ⚙️ Built-in Functions in C++

🔗 [Programiz C++ Bitwise Operators](https://www.programiz.com/cpp-programming/bitwise-operators)

```cpp
int x = 20;
long long y = 30;

// 1. Count set bits
__builtin_popcount(x);      // 2
__builtin_popcountll(y);    // 4

// 2. Count leading zeros
__builtin_clz(x);           // 27
__builtin_clzll(y);         // 59

// 3. Count trailing zeros
__builtin_ctz(x);           // 2
__builtin_ctzll(y);         // 1

// 4. Position of first set bit (1-based)
__builtin_ffs(x);
__builtin_ffsll(y);

// 5. Parity of set bits
__builtin_parity(x);
__builtin_parityll(y);

// 6. Index of highest set bit (MSB)
31 - __builtin_clz(x);      // 4
63 - __builtin_clzll(y);    // 4
__lg(x);                    // 4
__lg(y);                    // 4

// 7. Index of lowest set bit (LSB)
__builtin_ffs(x) - 1;       // 2
__builtin_ctz(x);           // 2
```

---
## 🧪 The Bit Law

<pre>
Always think bit by bit. If the solution is independent of the other bits, then we can solve the problem for each bit separately. 
</pre>
---

## 🧪 Bitwise OR

> Coming soon: techniques and applications

---

## 🧪 Bitwise AND

> Coming soon: techniques and applications

---


## 🔗 Useful Links & Problems

[1601A_Array Elimination](./1_bit_manipulation/1601A_Array%20Elimination.cpp)

<pre>
Everytime select k element, do "bitwise and" for all of that element, 
Calculate x=ai1 & ai2 & … & aik,
Subtract x from each of ai1,ai2,…,aik; all other elements remain untouched.

print all values k, such that it's possible to make all elements of a equal to 0 in a finite number of elimination operations with the given parameter k

- firstly think to solve of zero/one array
- then solve independent bit (if possible) 
- if all a[i] = 1, then select k such that our "and" outcome would be 1, then 1-1 = 0
- count of 1 is a multiple of k

- every bit is independent 
</pre>

- https://toph.co/p/prime---prime---prime


* [Codeforces 2108B – XOR/AND](https://codeforces.com/contest/2108/problem/B)
* [Codeforces 1514B – Bitmask](https://codeforces.com/problemset/problem/1514/B)
* [Codeforces 1615B – XOR Count](https://codeforces.com/problemset/problem/1615/B)



You're given several queries, each consisting of a range $[l, r]$ where $1 \le l \le r \le 10^9$. For each query, you need to find the **minimum number of elements you must remove** so that the **bitwise AND of the remaining elements is non-zero**.

<details>
  <summary><strong>Solution</strong></summary>

## ✅ Key Insight

A non-zero bitwise AND across some subset of numbers requires that:

- At least **one bit** remains set across **all** chosen numbers.

That means:

- For some bit position `b`, **all numbers in the subset must have the b-th bit set**.

---

### 🔁 Strategy (Optimized via Complement and Bit-counting)

Let’s define:

- $cnt_b$: count of numbers in $[l, r]$ where the `b`-th bit is set.

Then:

- If we want all numbers to have bit `b` set, we must **remove the numbers that don’t**.
- So, minimum elements to remove = $(r - l + 1) - cnt_b$

To make the AND non-zero, it’s enough to **keep the best possible bit position** $b$ — one with the highest `cnt_b`.

---

## ✅ Final Answer

$$
\text{answer} = (r - l + 1) - \max_{0 \le b \le 19} \text{cnt}_b
$$

Why up to `19`? Because $2^{20} = 1,048,576 > 10^6$, and $2^{30} = 1,073,741,824 > 10^9$. So we check up to 30-bit integers if needed.

---

## ✅ Efficient `cnt_b` Computation

You **don’t need precomputation or prefix arrays** here since $[l, r]$ can be huge. You can compute `cnt_b` on the fly with a helper like this:

### 🔧 `cntb(int l, int r, int k)` = how many numbers in $[l, r]$ have k-th bit set?

Use this method:

```cpp
int cntb(int r, int k) {
  int fullCycle = 1 << (k + 1);     // Full pattern size
  int halfCycle = 1 << k;          // Ones appear in this length
  int blocks = r / fullCycle;
  int rem = r % fullCycle;
  return blocks * halfCycle + max(0, rem - halfCycle + 1);
}

int cntb(int l, int r, int k) {
  return cntb(r, k) - cntb(l - 1, k);
}
```

## 🧠 Why This Works

You're always choosing the bit position `b` such that **most numbers in the range have that bit on**, and remove the rest. This ensures the resulting subsequence has a non-zero AND.

Let's **fully explain** how this bitwise trick works:

You're trying to compute:

> ✅ **`cntb(l, r, k)` = how many integers in \[l, r] have the `k`-th bit set (i.e., equal to 1)?**

This is done using:

```cpp
int cntb(int r, int k) {
  int fullCycle = 1 << (k + 1);     // pattern length = 2^(k+1)
  int halfCycle = 1 << k;           // number of ones per pattern = 2^k
  int blocks = r / fullCycle;
  int rem = r % fullCycle;
  return blocks * halfCycle + max(0, rem - halfCycle + 1);
}
```

Let’s walk through this **with visualization and explanation**.

---

## 🧠 Key Idea: Bit Pattern is Cyclic

Consider counting how many times the `k`-th bit is set in numbers from `1` to `r`.

### 🔁 The binary pattern of any bit is **repetitive every 2^(k+1)**.

For example:

- For `k = 0`: the bit pattern is `01010101...` (1 set every other bit)
- For `k = 1`: the bit pattern is `00110011...` (2 zeroes, 2 ones)
- For `k = 2`: the bit pattern is `0000111100001111...` (4 zeroes, 4 ones)

### 💡 So every **`2^(k+1)`** numbers:

- Exactly **`2^k`** of them have bit `k` set to 1.

---

## 🔎 Step-by-Step Explanation

### `int fullCycle = 1 << (k + 1);`

- `fullCycle` is the length of the repeating pattern: `2^(k+1)`

### `int halfCycle = 1 << k;`

- In every `fullCycle`, the bit `k` is set exactly `halfCycle` times: `2^k` times

---

## 🔢 Example (k = 1)

Binary of numbers from 0 to 7:

| Number | Binary | Bit-1 (k=1) |
| ------ | ------ | ----------- |
| 0      | 000    | 0           |
| 1      | 001    | 0           |
| 2      | 010    | 1 ✅        |
| 3      | 011    | 1 ✅        |
| 4      | 100    | 0           |
| 5      | 101    | 0           |
| 6      | 110    | 1 ✅        |
| 7      | 111    | 1 ✅        |

Pattern: **2 zeroes, 2 ones** → repeats every `2^(1+1) = 4` numbers

---

### ✅ Formula Logic

Now apply to `cntb(r, k)`:

```cpp
int blocks = r / fullCycle;
int rem = r % fullCycle;
int totalSetBits = blocks * halfCycle + max(0, rem - halfCycle + 1);
```

#### 1. `blocks * halfCycle`

- There are `blocks` full patterns up to `r`, each has `halfCycle` ones in the `k`-th bit.

#### 2. `rem - halfCycle + 1`

- This handles the **remaining `rem` numbers** after the last full pattern.
- If the remainder section **crosses into the region where the bit is set**, we count how many.

We take `max(0, rem - halfCycle + 1)` to:

- Only count ones in the second half of the pattern (where bit `k` is set)

---

## 🧮 Finally, to compute for a range \[l, r]:

```cpp
cntb(l, r, k) = cntb(r, k) - cntb(l - 1, k);
```

This uses prefix count from 1 to r, minus count from 1 to l-1 → standard prefix sum trick.

---

## ✅ Summary

The function `cntb(r, k)` computes how many integers from `1` to `r` have the `k`-th bit set. It does this by:

1. Counting full bit-pattern blocks (repeating every $2^{k+1}$)
2. Counting remaining bits after the last full pattern
3. Using `cntb(l, r, k)` to get count in `[l, r]`

## </details>
