## Generalized Permutations and Combinations

### Introduction

<img src="https://gre.myprepclub.com/forum/download/file.php?mode=view&id=15320&sid=12a76328403e68df68076d41c5bf8c9d" alt="pc" width="650">

<pre>
When elements may be used repeatedly (e.g., repeated digits on license plates) or when dealing with indistinguishable elements (e.g., identical letters in a word), standard permutation/combination formulas don't apply. This section covers four key scenarios:

1. Permutations with repetition
2. Combinations with repetition
3. Permutations with indistinguishable objects
4. Distributing objects into boxes
</pre>

![db1](https://i.ibb.co.com/9b1Kwd8/IMG-0276.jpg)

---

### <u>Permutations with Repetition</u>

**Scenario**: Ordered arrangements where elements can repeat.

**Formula**:

```math
P(n, r) = n^r
```

**Example**:  
Number of 4-digit PINs with digits 0-9:

```math
10^4 = 10,000
```

**Theorem 1**:  
The number of r-permutations of a set with n objects with repetition allowed is:

```math
n^r
```

![pr1](https://i.ibb.co.com/QJ8rJWj/IMG-0271.jpg)

![pr2](https://i.ibb.co.com/8zP86Tk/IMG-0264.jpg)

---

### <u>Combinations with Repetition</u>

**Scenario**: Unordered selections where elements can repeat.

**Formula** (Stars and Bars):

```math
\binom{n + r - 1}{r} = \frac{(n + r - 1)!}{r!(n - 1)!}
```

**Example**:  
Select 5 fruits from apples, oranges, pears:

```math
\binom{3 + 5 - 1}{5} = 21 \text{ ways}
```

**Applications**:

- Counting solutions to

```math
(x_1 + x_2 + ... + x_k = r)
```

- Counting nested loop iterations

**Detailed Example from Rosen 6.5**:  
A cookie shop sells 4 types of cookies. How many ways can you buy 10 cookies?

```math
\binom{4 + 10 - 1}{10} = \binom{13}{10} = 286
```

Now suppose you want to buy at least 2 chocolate and 1 peanut butter cookie:  
Assign minimums: 2 chocolate, 1 peanut butter → 7 left to distribute

```math
\binom{4 + 7 - 1}{7} = \binom{10}{7} = 120
```

![cr2](https://i.ibb.co.com/9ZWL600/IMG-0265.jpg)
![cr3](https://i.ibb.co.com/TTBszc5/IMG-0266.jpg)
![cr4](https://i.ibb.co.com/KbFhDsL/IMG-0267.jpg)
![cr5](https://i.ibb.co.com/2F0dvWT/IMG-0268.jpg)
![cr6](https://i.ibb.co.com/SJY2cgJ/IMG-0269.jpg)
![cr7](https://i.ibb.co.com/b6gtzJg/IMG-0270.jpg)

example:

- https://codeforces.com/problemset/problem/1288/C

---

### <u>Permutations with Indistinguishable Objects</u>

**Scenario**: Arrangements with duplicate items.

**Formula**:

```math
\frac{n!}{n_1!n_2!...n_k!}
```

**Example**:  
Arrangements of "SUCCESS":

```math
\frac{7!}{3!2!1!1!} = 420
```

**Theorem 3**:  
For \(n\) objects with \(k\) types of duplicates, the number of distinct permutations is:

```math
\frac{n!}{n_1!n_2!...n_k!}
```

![pr2](https://i.ibb.co.com/NY61W8R/IMG-0272.jpg)

---

### <u>Multinomial Coefficients</u>

Generalization of binomial coefficients:

```math
\binom{n}{k_1,k_2,...,k_m} = \frac{n!}{k_1!k_2!...k_m!}
```

**Applications**:

- Polynomial expansions
- Counting anagrams

<pre>
- 10 people 3 room, a room have 2, b-2 c-6 seat, how much way they can divide? => C(10,2)*C(8,2)*C(6,6) 
</pre>

![pr3](https://i.ibb.co.com/KNHMm4w/IMG-0273.jpg)

![pr4](https://i.ibb.co.com/vDW25vF/IMG-0274.jpg)

![pr5](https://i.ibb.co.com/6YVbC4r/IMG-0275.jpg)

<pre>
# How much way to shuffle? 
- MISSISSIPPI -> (11!)/(4!4!2!)
- RRUURRUU -> (8!)/(4!4!)

</pre>

examples:

- [cese1715_Creating Strings II](./1_basic_counting/2_combination/cses1715_Creating%20Strings2.cpp)

> Given a string, your task is to calculate the number of different strings that can be created using its characters.
> Print the <b>number of different strings</b> modulo 1e9+7
> -> n!/(a!b!c!...)

- https://www.spoj.com/problems/UCV2013E/

---

### <u>Distributing Objects into Boxes</u>

https://usaco.guide/CPH.pdf#page=219

Four main cases exist based on object/box distinguishability:

#### Case 1: Distinguishable Objects → Distinguishable Boxes

**Formula**:

```math
\frac{n!}{n_1!n_2!...n_k!}
```

**Example**:  
Deal 5 cards each to 4 players from 52-card deck:

```math
\frac{52!}{5!5!5!5!32!}
```

![db2](https://i.ibb.co.com/nD3m73n/IMG-0277.jpg)

#### Case 2: Indistinguishable Objects → Distinguishable Boxes

**Formula**: Same as combinations with repetition

```math
\binom{n + k - 1}{n}
```

![db3](https://i.ibb.co.com/k6xYjkQ/IMG-0278.jpg)

#### Case 3: Distinguishable Objects → Indistinguishable Boxes

Uses **Stirling numbers of the second kind**:

```math
S(n,k) = \frac{1}{k!} \sum_{i=0}^{k} (-1)^i \binom{k}{i}(k-i)^n
```

![db4](https://i.ibb.co.com/BBrPcLN/IMG-0279.jpg)

#### Case 4: Indistinguishable Objects → Indistinguishable Boxes

Counts **integer partitions** of \(n\) into \(\leq k\) parts. No closed formula.

![db5](https://i.ibb.co.com/M14Zp0t/IMG-0280.jpg)
![db6](https://i.ibb.co.com/BNBd8Mm/IMG-0282.jpg)

<pre>
- Scenario 1: Each box can contain at most one ball. For example, when n = 5 and k = 2, there are 10 solutions-> the answer is directly the binomial coefficient C(n,k).

- Scenario 2: A box can contain multiple balls. For example, when n = 5 and k = 2, there are 15 solutions -> the number of solutions is C(n+k−1,k)

- Scenario 3: Each box may contain at most one ball, and in addition, no two
adjacent boxes may both contain a ball. For example, when n = 5 and k = 2, there
are 6 solutions -> There are n − 2k + 1 such boxes and k + 1 positions for them. Thus, using the formula of scenario 2, the number of solutions is C(n−k+1,n−2k+1).
</pre>

---

#### Summary

$$
\begin{array}{|c|c|c|}
\hline
\textbf{Scenario} & \textbf{Formula} & \textbf{Example} \\
\hline\\
\text{Permutations with repetition} & n^r & \text{License plates} \\\\
\hline\\
\text{Combinations with repetition} & \binom{n+r-1}{r} & \text{Fruit selection} \\\\
\hline\\
\text{Indistinguishable permutations} & \frac{n!}{\Pi \text{duplicates}!} & \text{Anagram counting} \\\\
\hline\\
\text{Dist. objects → dist. boxes} & \frac{n!}{\Pi \text{box sizes}!} & \text{Card dealing} \\\\
\hline\\
\text{Indist. objects → dist. boxes} & \binom{n+k-1}{n} & \text{Ball-bin problems} \\\\
\hline
\end{array}
$$

##### References

1. Rosen, K. H. _Discrete Mathematics and Its Applications_
2. [USACO Guide](https://usaco.guide/CPH.pdf#page=219)
3. Bóna, M. _A Walk Through Combinatorics_
