# Stars and Bars

<pre>
Stars and bars is a mathematical technique for solving certain combinatorial problems. It occurs whenever you want to count the number of ways to group identical(similar) objects.
</pre>

![img](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj9yYmyp1o3zqgg9mmFmbGkYbMpohVzdvSDUHX04jFiQ7NfjF_Uu2q5ESs-nfIT2_v0Rmik96HeimRno1GkYq1BJ3-9IYa1TG8F-mHewF9vVDETyO-p4tZqkrcmlOYoENyqpHa27_A5LQ8c/s400/maxresdefault.jpg)

<pre>
-> a + b + c = 10, a>=1, b>=1, c>=1, how much solution have? => C(9,2) two wall inside 10 star (place 9)
-> a + b + c + d + e = 25 => C(25,4)

if(x<sub>i</sub>>=1) then C(m-1,n-1)
if(x<sub>i</sub>>=0) then change to prervious form > x<sub>i</sub>+1>=0+1

-> a + b + c = 10, (a>=0, b>=0, c>=0) => a+1 + b+1 + c+1 = 10, (a+1>=1, b+1>=1, c+1>=1) => a' + b' + c' = 13 => C(n+r-1,r-1)

-> a + b + c + d + e = 25 ((a>=2,b>=-1,c>=0,d>=1,e>=1)
=> a-1 + b+2 + c+1 + d + e = 27 (a-1>=1,b+2>=1,c+1>=1, d>=1,e>=1)
=> a' + b' + c' + d' + e' = 27 (a'>=1,b'>=1,c'>=1,d'>=1,e'>=1)
=> C(26,4)
</pre>

![pr](pr.png)

https://forthright48.com/stars-and-bars-theorem/

### **Stars and Bars Theorem**

**Problem:**
Given \( K \) variables,

```math
 a_1, a_2, a_3, \dots, a_K
```

, and a value \( N \), how many ways can we write:

```math
a_1 + a_2 + a_3 + \dots + a_K = N,
```

where

```math
 a_1, a_2, a_3, \dots, a_K
```

are non-negative integers?

**Example:**
For \( K = 3 \) and \( N = 2 \), there are 6 solutions:

```math
\begin{array}{c|c|c}
a_1 & a_2 & a_3 \\
\hline
2 & 0 & 0 \\
0 & 2 & 0 \\
0 & 0 & 2 \\
1 & 1 & 0 \\
1 & 0 & 1 \\
0 & 1 & 1 \\
\end{array}
```

**Solution:**
The problem can be visualized using the Stars and Bars method. Consider distributing \( N \) stars in \( K \) partitions, where each partition represents a variable. The total number of positions available is \( N + K - 1 \), consisting of \( N \) stars and \( K - 1 \) bars.

We need to select \( N \) positions for the stars, and the remaining \( K - 1 \) positions will automatically be for the bars. This is equivalent to the binomial coefficient:

```math
\binom{N + K - 1}{N} \quad \text{or equivalently} \quad \binom{N + K - 1}{K - 1}.
```

For our example, where \( K = 3 \) and \( N = 2 \):

```math
\binom{2 + 3 - 1}{2} = \binom{4}{2} = 6.
```

### **Stars and Bars Theorem:**

For any pair of positive integers \( N \) and \( K \), the number of \( K \)-tuples of non-negative integers whose sum is \( N \) is:

```math
\binom{N + K - 1}{N} \quad \text{or equivalently} \quad \binom{N + K - 1}{K - 1}.
```

This is also known as the **Ball and Urn Theorem**:

- **Ball and Urn Theorem:** If we have \( K \) distinguishable containers (urns) and \( N \) indistinguishable balls (stars), the number of ways to distribute them is:

```math
\binom{N + K - 1}{N} \quad \text{or equivalently} \quad \binom{N + K - 1}{K - 1}.
```

---

### **Extensions of Stars and Bars**

1. **Positive Number of Stars in Each Partition:**

   What if every partition must have at least one star? In this case, we place one star in each partition and subtract those from the total. This transforms the problem into:

```math
a_1 + a_2 + \dots + a_K = N, \quad \text{where} \quad a_1, a_2, \dots, a_K > 0.
```

This is equivalent to solving:

```math
a'_1 + a'_2 + \dots + a'_K = N - K,
```

where

```math
a'_1, a'_2, \dots, a'_K \geq 0 .
```

The number of solutions is then:

```math
\binom{N - 1}{K - 1}.
```

2. **Lower Bound with Each Partition:**

   If each partition \( a_i \) has a lower bound \( L_i \), we subtract \( L_i \) from each variable:

```math
a_1 + a_2 + \dots + a_K = N, \quad \text{where} \quad a_1 \geq L_1, a_2 \geq L_2, \dots, a_K \geq L_K.
```

This becomes equivalent to:

```math
a'_1 + a'_2 + \dots + a'_K = N - (L_1 + L_2 + \dots + L_K),
```

where

```math
 a'_1, a'_2, \dots, a'_K \geq 0 .
```

The number of solutions is:

```math
\binom{N - (L_1 + L_2 + \dots + L_K) + K - 1}{K - 1}.
```

- https://atcoder.jp/contests/abc178/tasks/abc178_d

3. **Equation with Inequality:**

   If the problem is to find:

```math
a_1 + a_2 + \dots + a_K \leq N,
```

there are two ways to approach it:

- **Garbage Partition Method:** Introduce an extra partition to handle the inequality. This transforms the equation into:

```math
a_1 + a_2 + \dots + a_K + a_{K+1} = N,
```

where

```math
 a_{K+1}
```

is the "garbage" partition. The number of solutions is:

```math
\binom{N + K}{K}.
```

- **Vertical Sum of Pascal's Triangle:** Another method involves summing the results of the equation for each possible sum from \( 0 \) to \( N \), leading to:

```math
\sum_{i=0}^{N} \binom{N + K - i - 1}{K - 1}.
```

This is equivalent to the vertical sum of a column in Pascal's Triangle, which simplifies to:

```math
\binom{N + K}{K}.
```

4. **Upper Bound with Each Partition:**

   When there is an upper bound on each partition, Dynamic Programming (DP) is a potential solution. The idea is to iterate through each partition, keeping track of the remaining stars, and explore all possible placements for the stars. This method may work for small constraints but can become complex for large inputs.

   The basic idea is to define a DP function like:

```cpp
int dp(int partition, int stars) {
    int res = 0;
    for (int i = 0; i < upperLimit[partition]; i++) {
        res += dp(partition + 1, stars - i);
    }
    return res;
}
```

---

### **Conclusion:**

The Stars and Bars Theorem is a powerful combinatorial tool for distributing indistinguishable objects into distinguishable bins. The theorem, along with its extensions and variations, provides solutions to a wide range of problems in combinatorics.

---

https://discrete.openmathbooks.org/dmoi2/sec_stars-and-bars.html

## 🍪 **Distributing Identical Cookies to Distinct Kids**

We want to distribute **7 identical cookies** to **4 distinct kids** (let’s name them A, B, C, D). The key question is:

> **How many ways can we do this?**

The answer depends on whether:

1. **Kids can receive zero cookies** (some may get none).
2. **Every kid must get at least one cookie**.

We'll analyze **both cases** carefully.

---

## ✨ Motivating Example

You have **7 cookies** to give to **4 kids**.  
How many ways can you do this?

Take a moment to think about how you might solve this problem. You may assume that it is acceptable to give a kid **no cookies**. Also, the cookies are **all identical** and the order in which you give out the cookies **does not matter**.

---

### ❌ A Wrong Way to Think

You might guess:

```math
4^7 = 16384
```

Why? Because each cookie can go to any of the 4 kids.  
But this **overcounts**—it treats order as important. For instance:

- Giving 6 cookies to A and 1 to B is the same as giving 1 to B and 6 to A.

So this method counts multiple arrangements that result in the **same distribution**.

---

### ✅ What Do Valid Outcomes Look Like?

One approach is to represent outcomes as:

- A **tuple of integers**:  
  Example: `3 1 1 2` means A gets 3, B and C get 1 each, D gets 2.

- A **string of letters**:  
  Example: `AAABCDD` – 3 for A, 1 for B, 1 for C, 2 for D.

But since cookies are identical, the **order doesn’t matter**, so we consider all strings like `AAABCDD`, `ABAADCD`, etc., as the **same**.

---

### 🌟 Stars and Bars Representation

Represent cookies with `*` and divide among kids using bars (`|`).  
We need:

- 7 stars (cookies)
- 3 bars (dividers between 4 kids)

#### Example:

```text
***|*|*|**
```

Means:

- A gets 3
- B gets 1
- C gets 1
- D gets 2

#### Another Example:

```text
|***||****
```

Means:

- A gets 0
- B gets 3
- C gets 0
- D gets 4

✅ Any arrangement of 7 stars and 3 bars represents a valid distribution.

---

## ✅ Case 1: Kids **Can Receive Zero Cookies**

We are choosing positions for 3 bars among 10 spots (7 stars + 3 bars):

```math
\binom{10}{3} = \boxed{120}
```

### ✅ General Formula

```math
\binom{n + k - 1}{k - 1}
```

Where:

- \( n = 7 \): cookies
- \( k = 4 \): kids

So:

```math
\binom{7 + 4 - 1}{4 - 1} = \binom{10}{3} = \boxed{120}
```

- https://lightoj.com/problem/problem-makes-problem

---

## ✅ Case 2: Every Kid **Must Get ≥ 1 Cookie**

First, give 1 cookie to each kid.  
Remaining cookies: \( 7 - 4 = 3 \)

Now distribute 3 identical cookies to 4 kids, allowing zeros:

```math
\binom{6}{3} = \boxed{20}
```

### ✅ Alternate View (Stars and Bars Restriction)

To ensure each kid gets at least one:

- Bars cannot be adjacent (would skip a kid)
- Bars must go **between** stars

There are 6 gaps between 7 stars. Choose 3:

```math
\binom{6}{3} = \boxed{20}
```

### ✅ General Formula

```math
\binom{n - 1}{k - 1}
```

Where:

- \( n = 7 \): cookies
- \( k = 4 \): kids

So:

```math
\binom{6}{3} = \boxed{20}
```

- https://atcoder.jp/contests/abc179/tasks/abc179_c

We are given a positive integer $N$ and asked to find the number of **tuples $(A, B, C)$ of positive integers** such that:

$$
A \times B + C = N
$$

We want to count how many such triples $(A, B, C)$ exist with **positive integers** $A, B, C$ satisfying this equation.

### Step-by-step Analysis

Rewriting the equation:

$$
A \times B + C = N \Rightarrow C = N - A \times B
$$

Now, for the tuple $(A, B, C)$ to be valid:

- $A \ge 1$
- $B \ge 1$
- $C = N - A \times B \ge 1$

So we need:

$$
A \times B \le N - 1
$$

Now iterate over all pairs $(A, B)$ such that $A \times B \le N - 1$, and for each such pair, $C = N - A \times B$ will be a positive integer, giving one valid tuple.

### Total number of such tuples

We need to compute:

$$
\text{Total } = \sum_{A=1}^{N-1} \left\lfloor \frac{N-1}{A} \right\rfloor
$$

Because for each $A$, the maximum $B$ such that $A \times B \le N-1$ is $\left\lfloor \frac{N-1}{A} \right\rfloor$. All $B$ from 1 to that value are valid, and $C = N - A \times B$ will be positive.

### Example:

Let’s take $N = 10$

We find all $(A, B)$ such that $A \times B \le 9$:

- $A = 1$: $B = 1$ to 9 → 9 values
- $A = 2$: $B = 1$ to 4 → 4 values
- $A = 3$: $B = 1$ to 3 → 3 values
- $A = 4$: $B = 1$ to 2 → 2 values
- $A = 5$: $B = 1$ → 1
- $A = 6$: $B = 1$ → 1
- $A = 7$: $B = 1$ → 1
- $A = 8$: $B = 1$ → 1
- $A = 9$: $B = 1$ → 1

Total:

$$
9 + 4 + 3 + 2 + 1 + 1 + 1 + 1 + 1 = \boxed{23}
$$

So, **the total number of positive integer tuples $(A, B, C)$ satisfying $A \times B + C = N$** is:

$$
\boxed{\sum_{A=1}^{N-1} \left\lfloor \frac{N-1}{A} \right\rfloor}
$$

---

## 🧠 Summary Table

$$
\begin{array}{|c|c|c|}
\hline
\textbf{Scenario} & \textbf{Formula} & \textbf{Example} \\
\hline\\
\text{Indist. cookies to dist. kids (zero allowed)} & \binom{n + k - 1}{k - 1} & \binom{10}{3} = 120 \\\\
\hline\\
\text{Indist. cookies to dist. kids (≥1 each)} & \binom{n - 1}{k - 1} & \binom{6}{3} = 20 \\\\
\hline
\end{array}
$$

---

### ⚠️ Common Confusion

If you answered **20**, you probably assumed each kid must get at least one cookie.  
But unless specified, **zero is allowed**, so the correct answer is:

### 🎯 Final Answer:

```math
\boxed{120}
```

---

https://artofproblemsolving.com/wiki/index.php/Ball-and-urn

## 🍪 Ball-and-Urn (Stars and Bars)

The **Ball-and-Urn** technique (also called **Stars and Bars**, **Sticks and Stones**, or **Dots and Dividers**) is a classic method in combinatorics for distributing **indistinguishable objects** into **distinguishable boxes** under various constraints.

---

### 🎯 Stars and Bars — Summary Table

$$
\begin{array}{|c|c|c|}
\hline
\textbf{Scenario} & \textbf{Formula} & \textbf{Example} \\
\hline\\
\text{No restrictions} & \dbinom{n + k - 1}{k - 1} & \text{7 cookies, 4 kids: } \dbinom{10}{3} = 120 \\\\
\hline\\
\text{Each gets at least 1} & \dbinom{n - 1}{k - 1} & \text{7 cookies, 4 kids (≥1 each): } \dbinom{6}{3} = 20 \\\\
\hline\\
\text{Each gets at least } r & \dbinom{n - kr + k - 1}{k - 1} & \text{20 balls, 5 bins (≥2 each): } \dbinom{14}{4} = 1001 \\\\
\hline\\
\text{Each gets at most } r &
\sum\limits_{m=0}^{\left\lfloor \frac{n}{r+1} \right\rfloor}
(-1)^m \dbinom{k}{m} \dbinom{n - m(r+1) + k - 1}{k - 1}
& \text{Inclusion-Exclusion Method} \\\\
\hline\\
\text{Sum } \leq n &
\dbinom{n + k}{k}
& \text{At most 7 cookies, 4 kids: } \dbinom{11}{4} = 330 \\\\
\hline
\end{array}
$$

### 📌 Legend:

- \( n \): total items (cookies, balls, etc.)
- \( k \): number of bins/people/variables
- \( r \): minimum or maximum bound for each \( a_i \)

---

- https://codeforces.com/problemset/problem/617/B

You’re not distributing `0`s arbitrarily — rather, you are **counting the number of ways to split the array so that each segment has exactly one `1`** and possibly some `0`s attached to it.

Key point:

- Suppose the positions of `1`s are:
  $p_1, p_2, \dots, p_k$
- The number of `0`s between `p_i` and `p_{i+1}` is:

  $$
  z_i = p_{i+1} - p_i - 1
  $$

- Now, **in how many ways can you form a segment that includes `1`, all zeros to the left or right of it, and ends just before the next `1`**?

Answer:
For each pair of 1s, say at position `p` and `q`, you can place the break anywhere between them. That gives you exactly:

$$
q - p \quad \text{ways}
$$

So total number of segmentations = product over all gaps:

$$
\prod_{i=1}^{k-1} (p_{i+1} - p_i)
$$

This is **not traditional stars and bars**, but closely resembles it:

- The **bars** are fixed between the 1s.
- The **stars** (zeros) are being placed into the gaps.
- And you're **multiplying choices** for placing the break around these stars.

---

### 🔚 Conclusion

While the problem isn't a **direct stars and bars** (because we’re not selecting compositions or integer partitions), the multiplication of choices across gaps between the 1s is **analogous** to stars and bars logic: you're computing how the zeros (stars) can be grouped between the 1s (bars fixed at 1s), and counting all valid segmentations.

So, in summary:

> Each segment must contain **exactly one `1`**, and the **zeros between 1s** can be associated either with the left `1` or the right `1` — that’s why you get `(gap + 1)` choices → this is _multiplicative_, much like stars and bars in combinatorics.

## 🧠 Full Reasoning and Derivations

### 🔵 **Scenario 1: No Restriction (Each gets ≥0)**

**Goal:** Distribute \( k \) indistinguishable balls into \( n \) distinguishable bins.

**Formula:**

```math
\binom{n + k - 1}{k} = \binom{n + k - 1}{n - 1}
```

**Reasoning:**

- Use \( k \) stars (\(\*\)) and \( n - 1 \) bars (\(|\)) to separate the bins.
- Total symbols = \( k + n - 1 \). Choose positions for the bars:

```math
\text{Ways} = \binom{k + n - 1}{n - 1}
```

**Example:**
Distribute 7 cookies to 4 kids:

```math
\binom{7 + 4 - 1}{3} = \binom{10}{3} = 120
```

---

### 🟡 **Scenario 2: Each Gets At Least 1**

**Goal:** Distribute \( k \) indistinguishable balls into \( n \) bins, each with ≥1.

**Formula:**

```math
\binom{k - 1}{n - 1}
```

**Reasoning:**

- Give 1 ball to each bin → \( k - n \) balls left.
- Now it's Scenario 1 on \( k' = k - n \) and \( n \) bins:

```math
\binom{(k - n) + n - 1}{n - 1} = \binom{k - 1}{n - 1}
```

**Example:**
7 cookies, 4 kids each gets ≥1:

```math
\binom{6}{3} = 20
```

- https://lightoj.com/problem/one-unit-machine

### 1. Understanding the Problem

The key observation here is that for each job, all its units must be completed before any units of the next job start. This means that in the sequence of all units processed, the last unit of Jobᵢ must appear before the first unit of Jobᵢ₊₁.

### 2. Combinatorial Insight

The problem reduces to finding the number of ways to interleave the units of jobs such that all units of Job₁ come before any units of Job₂, all units of Job₂ come before any units of Job₃, and so on. However, this is not directly a multinomial coefficient because of the constraints between jobs.

### 3. Step-by-Step Calculation

- **Total Units**: The total number of units across all jobs is
  $S = k_1 + k_2 + \ldots + k_n$.
  The total number of ways to arrange these units without any constraints is the multinomial coefficient:

  $$
  \frac{S!}{k_1! \cdot k_2! \cdot \ldots \cdot k_n!}
  $$

  However, we have constraints that all units of Jobᵢ must precede any units of Jobᵢ₊₁.

- **Valid Sequences**: The valid sequences are those where the sequence is divided into segments: first all $k_1$ units of Job₁, then all $k_2$ units of Job₂, etc. The number of such sequences is exactly 1, but this is only if we strictly enforce the order. However, the problem allows interleaving as long as the relative order of jobs is maintained. Specifically, the solution involves calculating the product of multinomial coefficients in a specific manner.

### 4. Dynamic Product Calculation

The solution can be derived by considering the sequence construction step by step:

- Start with the units of Job₁. There's only 1 way to arrange them.
- For each subsequent job `i`, the units must all come after the last unit of the previous jobs. The new units can be placed in the remaining slots. The number of ways to do this is the combination of remaining slots after placing previous jobs' units.

Specifically, after processing the first (i-1) jobs, the total units processed are
$S_{i-1} = k_1 + k_2 + \ldots + k_{i-1}$.
The new $k_i$ units must all be placed in the remaining slots, but they must all come after the last unit of the previous jobs.
The number of valid ways is

$$
\binom{S_{i-1} + k_i - 1}{k_i - 1}
$$

This forms a multiplicative product over all jobs from 2 to n.

### 5. Modular Arithmetic

Since the results can be very large, all calculations should be done modulo

$$
10^9 + 7
$$

## Explanation

- **Precomputation**: The code precomputes factorials and their modular inverses up to the maximum possible value (1e6) using Fermat's Little Theorem for efficient combination calculations.
- **Combination Calculation**: For each test case, the solution processes each job in sequence. The key insight is that after placing the first $i-1$ jobs' units, the $i$-th job's units must all be placed after the last unit of the previous jobs. The number of ways to place these units is given by the combination

  $$
  \binom{S_{i-1} + k_i - 1}{k_i - 1}
  $$

  where $S_{i-1}$ is the sum of units of the first $i-1$ jobs.

- **Modulo Handling**: All operations are performed under modulo $10^9 + 7$ to prevent integer overflow and adhere to the problem constraints.

This approach efficiently calculates the number of valid sequences by leveraging combinatorial mathematics and dynamic multiplicative product accumulation, ensuring optimal performance even for large input sizes.

---

## Multinomial Coefficient vs. This Problem’s Approach

The key difference between the **multinomial coefficient** and the approach used in this problem lies in the **constraints** applied to the sequences being counted.

### **Multinomial Coefficient**

- **Definition**: Counts the number of ways to arrange a sequence of items where there are multiple types (categories) of items, and the order within each type doesn't matter.

- **Formula**:
  If you have a total of `S` items divided into `n` categories with counts `k₁, k₂, ..., kₙ` (where `S = k₁ + k₂ + ... + kₙ`), the number of distinct sequences is:

  $$
  \frac{S!}{k₁! \cdot k₂! \cdots kₙ!}
  $$

- **Example**:
  Suppose you have 2 apples (`A`) and 2 bananas (`B`). The multinomial coefficient counts all possible sequences (without constraints):

  $$
  \frac{4!}{2! \cdot 2!} = 6 \text{ sequences: } AABB, ABAB, ABBA, BAAB, BABA, BBAA
  $$

- **No Order Constraints**:
  The multinomial coefficient does **not** enforce any order between categories (e.g., all `A`s before `B`s). It counts all possible interleavings.

---

### **This Problem’s Approach**

- **Constraint**:
  All units of `Jobᵢ` must finish before any unit of `Jobᵢ₊₁` starts. This imposes a **strict ordering** between jobs.

- **Key Insight**:
  Instead of allowing all interleavings (like the multinomial coefficient), we only allow sequences where the last unit of `Jobᵢ` appears before the first unit of `Jobᵢ₊₁`.

- **Formula**:
  The number of valid sequences is computed as:

  $$
  \prod_{i=2}^{n} \binom{(k_1 + k_2 + \dots + k_i) - 1}{k_i - 1}
  $$

  This formula ensures that the `kᵢ` units of `Jobᵢ` are placed **after** all previous jobs' units.

- **Example**:
  For `Job₁ = 2 units` and `Job₂ = 2 units`, the valid sequences are:

  $$
  \binom{3}{1} = 3 \text{ sequences: } J_1 J_1 J_2 J_2,\; J_1 J_2 J_1 J_2,\; J_2 J_1 J_1 J_2
  $$

  (The multinomial coefficient would give 6 sequences, but only 3 satisfy the constraint.)

---

### **Comparison Summary**

| Feature               | Multinomial Coefficient                    | This Problem’s Approach                                  |
| --------------------- | ------------------------------------------ | -------------------------------------------------------- |
| **Order Constraints** | No constraints (all interleavings allowed) | Strict ordering (`Jobᵢ` before `Jobᵢ₊₁`)                 |
| **Formula**           | $\frac{S!}{k₁! k₂! \cdots kₙ!}$            | $\prod_{i=2}^n \binom{(k_1 + \dots + k_i) - 1}{k_i - 1}$ |
| **Example (2, 2)**    | 6 sequences                                | 3 sequences                                              |
| **Use Case**          | Counting all possible arrangements         | Counting arrangements with precedence constraints        |

---

### **Why Not Just Use Multinomial?**

The multinomial coefficient counts **all possible interleavings**, but this problem requires **only those where jobs finish in order**. Thus, we need a more restrictive combinatorial approach.

---

### **Final Takeaway**

- **Multinomial**: Counts all possible sequences (no constraints).
- **This Problem’s Method**: Counts only sequences where jobs finish in a specified order (constraints applied).

This is done by **breaking the problem into stages** and using combinations to enforce the constraints at each step.

---

Here is your detailed step-by-step explanation, formatted neatly for a README or documentation page:

---

## Derivation of the Formula for Counting Valid Job Sequences with Precedence Constraints

---

### Problem Restatement

- We have `n` jobs, where `Job_i` has `k_i` units.
- We must process **all** units of `Job_i` **before** processing any unit of `Job_{i+1}`.
- **Goal:** Count the number of valid sequences that satisfy this strict ordering constraint.

---

### Key Observations

1. Let

   $$
   S = k_1 + k_2 + \cdots + k_n
   $$

   be the total number of units.

2. The precedence constraints require:

   - All units of `Job₁` appear before any unit of `Job₂`.
   - All units of `Job₂` appear before any unit of `Job₃`.
   - … and so on.

---

### Step-by-Step Derivation

#### 1. Base Case: `Job₁`

- Since `Job₁` has no preceding jobs, all `k_1` units appear consecutively.
- Number of ways to arrange `Job₁` units respecting constraints:

  $$
  1
  $$

---

#### 2. Adding `Job₂`

- Units placed so far: $k_1$.
- New units to place: $k_2$.
- Constraint: All `Job₂` units must come **after** the last `Job₁` unit.
- Total slots: $k_1 + k_2$.
- The number of ways to place `k_2` units so that they follow `Job₁` units is:

$$
\binom{(k_1 + k_2) - 1}{k_2 - 1}
$$

**Intuition:** Choosing the starting position of the `Job₂` units in the sequence such that they all come after `Job₁`.

---

#### 3. General Case: `Job_i` (for $i \geq 2$)

- Units placed so far:

  $$
  S_{i-1} = k_1 + k_2 + \cdots + k_{i-1}
  $$

- New units to place: $k_i$.
- Constraint: All `Job_i` units must come **after** the last unit of `Job_{i-1}`.
- Total slots after adding `Job_i`:

  $$
  S_i = S_{i-1} + k_i
  $$

- Number of ways to insert `Job_i` units is:

$$
\binom{S_i - 1}{k_i - 1}
$$

---

#### 4. Final Formula

Multiply the valid placements for all jobs from 2 to $n$:

$$
\boxed{
\text{Total Ways} = \prod_{i=2}^n \binom{(k_1 + k_2 + \cdots + k_i) - 1}{k_i - 1}
}
$$

Note: For `Job₁`, the count is 1.

---

### Example: Jobs with 2 and 2 Units

- $k_1 = 2, k_2 = 2$
- Compute:

$$
\binom{(2 + 2) - 1}{2 - 1} = \binom{3}{1} = 3
$$

These 3 sequences are the only valid ones where `Job₂` units come after all `Job₁` units:

1. $J_1 J_1 J_2 J_2$
2. $J_1 J_2 J_1 J_2$
3. $J_2 J_1 J_1 J_2$

The multinomial coefficient $\frac{4!}{2! 2!} = 6$ counts all interleavings (including invalid ones).

---

### Why Not Just Use the Multinomial Coefficient?

- The multinomial coefficient counts **all possible interleavings** without ordering constraints.
- This problem **requires** that jobs finish in order.
- Thus, the multinomial count includes invalid sequences where later jobs start before earlier jobs finish.
- Our formula **enforces precedence constraints** via the combination products.

---

### Key Takeaways

- The formula is derived by **sequentially enforcing precedence constraints** job-by-job.
- Uses combinations to count valid placements of each job’s units **after** previous jobs.
- The product of these counts yields the total number of valid sequences.
- This method is more restrictive than multinomial coefficients and respects job ordering constraints.

---

This approach efficiently and correctly counts valid job processing sequences respecting the given ordering constraints.

### 🟠 **Scenario 3: Each Gets At Least \( r \)**

**Goal:** Distribute \( N \) indistinguishable balls into \( n \) bins, each getting ≥\( r \).

**Formula:**

```math
\binom{N - nr + n - 1}{n - 1}
```

**Reasoning:**

- Give \( r \) balls to each bin → \( N - nr \) left.
- Now distribute those freely (Scenario 1):

```math
\binom{(N - nr) + n - 1}{n - 1}
```

**Example:**
20 balls, 5 bins, each gets ≥2:

- Give 2 each → 10 used, 10 left.

```math
\binom{10 + 5 - 1}{4} = \binom{14}{4}
```

---

### 🔴 **Scenario 4: Each Gets At Most \( r \)**

**Goal:** Distribute \( N \) indistinguishable balls into \( n \) bins, each getting ≤\( r \).

**Formula (Inclusion-Exclusion):**

```math
\sum_{m=0}^{\left\lfloor \frac{N}{r+1} \right\rfloor} (-1)^m \binom{n}{m} \binom{N - m(r+1) + n - 1}{n - 1}
```

**Reasoning:**

- Start with total ways without restriction.
- Subtract "bad" cases where ≥1 bin exceeds \( r \).
- Use PIE (Principle of Inclusion-Exclusion):
  - For each subset of \( m \) bins, remove cases where each of them has ≥ \( r + 1 \).

---

### ✨ Visual Representation

Each distribution corresponds to a stars-and-bars string.  
Example with 7 cookies, 4 kids:

- `***|*|*|**` → [3, 1, 1, 2]
- `|***||****` → [0, 3, 0, 4]
- `****|*|*|` → [4, 1, 1, 1]

Each arrangement of \( k \) stars and \( n - 1 \) bars uniquely represents one valid distribution.

---

### **Reasoning 1: Stars and Bars**

Arranging \( k \) stars (\(\ast\)) and \( n - 1 \) bars (\(|\)) is the same as saying there are \( k + n - 1 \) positions:

```math
\underbrace{\_ \_ \_ \_ \_ \_ \_}_{k + n - 1}
```

You want to fill \( k \) of them with stars and the remaining with bars. Thus, you are choosing \( k \) positions out of \( k + n - 1 \) total positions, or equivalently, choosing \( n - 1 \) positions for the dividers out of \( n + k - 1 \) total spots, resulting in a total of:

```math
\binom{k + n - 1}{n - 1}
```

ways.

---

### **Reasoning 2: Repeated Urns Interpretation**

If you could only put one ball in each urn, there would be \( \binom{n}{k} \) possibilities. However, since repetition of balls is allowed, this formula does not apply directly.

Think of the problem as having \( n \) "urns" and \( k \) additional "repeat" urns labeled "repeat 1st", "repeat 2nd", ..., "repeat \( k-1 \)-th". After placing balls in the urns, imagine that any balls in the "repeat" urns are stacked on top of the correct balls in the first \( n \) urns, moving from left to right. This gives a one-to-one correspondence between the non-repeating arrangements in the new urns and the repeat-allowed arrangements in the original urns.

For example, consider distributing 4 balls into 5 urns:

- **No repeats:** \( 1, 2, 3, 4 \)
- **One repeat:** \( 1, 1, 2, 4 \rightarrow 1, 2, 4, r_1 \)
- **Two repeats:** \( 1, 2, 2, 2 \rightarrow 1, 2, r_2, r_3 \)
- **Two urns with multiple balls:** \( 4, 4, 5, 5 \rightarrow 4, 5, r_1, r_2 \)

Since there are \( n + k - 1 \) total urns, and \( k \) balls, the number of possible scenarios is simply:

```math
\binom{n + k - 1}{k}
```

By the symmetry property of binomial coefficients, we can also express this as:

```math
\binom{n + k - 1}{k} = \binom{n + k - 1}{n - 1}
```

---

### ✅ Final Takeaway

Use **Stars and Bars** when:

- Objects are **indistinguishable**
- Bins are **distinguishable**
- You're counting valid **distributions** of total objects

#### Quick Reference:

- No restriction:

```math
 \binom{n + k - 1}{k}
```

- At least 1 per bin:

```math
\binom{k - 1}{n - 1}
```

- At least \( r \) per bin:

```math
\binom{N - nr + n - 1}{n - 1}
```

- At most \( r \) per bin:   PIE formula

---

example:

- [lightoj\_ Problem Makes Problem](https://lightoj.com/problem/problem-makes-problem)

<pre>
how can you make n by adding k non-negative integers?

-> be careful for constant (n -> n+k-1)
</pre>

- [spoj_marbles](spoj_marbles.cpp)

<pre>
To determine the number of ways Hänschen can select n marbles from k different colors, ensuring he has at least one marble of each color
</pre>

- [57C_Array](./57C_Array.cpp)

<pre>
he is researching arrays with the length of n, containing only integers from 1 to n. he thinks that an array is beautiful if it meets one of the two conditions:
- each elements, starting from the second one, is no more than the preceding one
- each element, starting from the second one, is no less than the preceding one 

Total beautiful arrays = (Number of non-decreasing) + (Number of non-increasing) - (Number of constant)
</pre>

- https://codeforces.com/problemset/problem/553/A

<pre>
Kyoya Ootori has a bag with n colored balls that are colored with k different colors. The colors are labeled from 1 to k. Balls of the same color are indistinguishable. He draws balls from the bag one by one until the bag is empty. He noticed that he drew the last ball of color i before drawing the last ball of color i + 1 for all i from 1 to k - 1. Now he wonders how many different ways this can happen. 
</pre>

- https://atcoder.jp/contests/abc110/tasks/abc110_d

🧩 **What’s the problem asking?**

You're given a number $M$, and you want to know:

> **How many ordered tuples** $(a_1, a_2, \ldots, a_N)$ **of positive integers** multiply to exactly $M$?

Example: If $M = 12$ and $N = 2$, some valid tuples are $(2,6), (3,4), (1,12)$, etc.

📌 **Core Concept**

We break this down by using **prime factorization**.

If:

$$
M = p_1^{b_1} \cdot p_2^{b_2} \cdots p_k^{b_k}
$$

Then, each $a_i$ can be written using the same primes:

$$
a_i = p_1^{c_{i1}} \cdot p_2^{c_{i2}} \cdots p_k^{c_{ik}}
$$

Now, when you multiply all the $a_i$'s together:

$$
a_1 a_2 \cdots a_N = p_1^{c_{11} + c_{21} + \cdots + c_{N1}} \cdots p_k^{c_{1k} + c_{2k} + \cdots + c_{Nk}}
$$

To satisfy $a_1 \cdots a_N = M$, this means for each prime $p_j$:

$$
c_{1j} + c_{2j} + \cdots + c_{Nj} = b_j
$$

This is where **combinatorics** comes in.

🎯 **Counting the Number of Solutions**

Each equation like:

$$
c_{1j} + c_{2j} + \cdots + c_{Nj} = b_j \quad \text{with } c_{ij} \geq 0
$$

is a classical "**stars and bars**" problem. The number of non-negative integer solutions is:

$$
\binom{b_j + N - 1}{b_j}
$$

And since there are $k$ such independent equations (one for each prime), the total number of solutions is the product:

$$
\prod_{j=1}^k \binom{b_j + N - 1}{b_j}
$$

Example: $M = 12, N = 2$\*\*

- $12 = 2^2 \cdot 3^1$
- For prime 2 ($b = 2$): Distribute 2 among 2 slots → $\binom{2 + 2 - 1}{2} = \binom{3}{2} = 3$
- For prime 3 ($b = 1$): Distribute 1 among 2 slots → $\binom{2}{1} = 2$
- Total ordered tuples: $3 \times 2 = 6$

✅ These correspond to tuples:

- $(1,12), (2,6), (3,4), (4,3), (6,2), (12,1)$

🔁 **Why this works (Core Idea):**

We’re distributing the **prime powers** of $M$ to $N$ different numbers $a_i$.

- Multiplying numbers is like **adding exponents**.
- So, to get the product equal to $M$, the **total exponents must add up correctly**.
- For each prime, we **count how many ways we can distribute its exponent** across $N$ numbers.
- Then, we multiply all those counts together.

🧠 Final Insight

Every number can be broken into primes. You're just figuring out how to **split the exponents of those primes** into $N$ pieces. The number of ways to do this gives the number of tuples whose product is $M$.

- https://atcoder.jp/contests/abc156/tasks/abc156_e

You want to find:

> After exactly **k moves** between **n initially occupied rooms**, how many **distinct combinations** of people in the rooms are possible?

Each move transfers a person from one room to another, so:

- Total number of people remains **n**
- Each move shifts one person from room `i → j`
- You want to count the number of possible **final distributions of people** across the rooms after **exactly k moves**

✅ What This Code Really Does

It computes:

$$
\text{Answer} = \sum_{i=0}^{\min(n, k)} \binom{n}{i} \cdot \binom{n - 1}{n - i - 1} \pmod{10^9 + 7}
$$

🔹 Meaning of Each Term:

- $i$: number of **rooms that are empty** at the end.
- $\binom{n}{i}$: number of ways to choose `i` empty rooms
- $\binom{n - 1}{n - i - 1}$: number of ways to **distribute `k` moves** so that each of the remaining `n - i` rooms has **at least one person** (ensuring none of them become empty)

The sum is over all possible valid numbers of empty rooms, constrained by `k` (you can’t have more than `k` empty rooms because you can't "vacuum" a room unless someone leaves it via a move).

🔁 In Short:

You are using **inclusion-exclusion + constrained composition** to count how many **ways `k` people can move** so that **final room counts are valid**.

---

### Recap of stars and bars

![pr2](pr2.png)
![pr3](pr3.png)

> upto now only given lower limits

## Advanced (Stars & Bars) using PIE

https://cp-algorithms.com/combinatorics/inclusion-exclusion.html#number-of-upper-bound-integer-sums

![pr4](pr4.png)

> satisfy three conditions means (total - at least 1 condition not satisfy)

n+k-1
![pr5](pr5.png)

> make simpler solution for all of those equations

![pr6](pr6.png)

another examples

![pr7](pr7.png)

conditions which are not satisfy

![pr8](pr8.png)

![pr9](pr9.png)
