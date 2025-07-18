## Euclidean Algorithms

- <u>GCD</u>

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

- <u>LCM</u>

<pre>
lcm(a,b) = (a*b)/gcd(a,b)
</pre>
<pre>
LCM and GCD Relationships:

- For any prime k, the exponent in LCM(p, q) is the maximum of the exponents of k in p and q.

- For any prime k, the exponent in GCD(p, q) is the minimum of the exponents of k in p and q.
</pre>

- https://codeforces.com/blog/entry/95694

$$
  \begin{array}{|c|l|}
  \hline
  \textbf{Property} & \textbf{Description} \\
  \hline\\
  \text{Linear Combination} & \gcd(a, b) = d = ap + bq \\\\
  \hline\\
  \text{Divisor of GCD} & \text{Every common divisor of } a \text{ and } b \text{ divides } \gcd(a, b) \\\\
  \hline\\
  \text{GCD of Zero} & \gcd(a, 0) = |a| \text{ for } a \ne 0 \\\\
  \hline\\
  \text{Division Lemma} & a \mid bc \text{ and } \gcd(a, b) = d \Rightarrow \frac{a}{d} \mid c \\\\
  \hline\\
  \text{Scaling Rule} & \gcd(ma, mb) = m \cdot \gcd(a, b) \\\\
  \hline\\
  \text{Coprime Reduction} & \text{If } \gcd(a, b) = g, \text{ then } \frac{a}{g} \perp \frac{b}{g} \\\\
  \hline\\
  \text{Additive Property} & \gcd(a, b) = \gcd(a + mb, b) \\\\
  \hline\\
  \text{Euclidean Algorithm} & \gcd(a, b) = \gcd(b, a \bmod b) \\\\
  \hline\\
  \text{Factor Reduction} & \gcd\left(\frac{a}{m}, \frac{b}{m}\right) = \frac{\gcd(a, b)}{m} \text{ if } m \mid a, m \mid b \\\\
  \hline\\
  \text{Multiplicative GCD} & a_1 \perp a_2 \Rightarrow \gcd(a_1 a_2, b) = \gcd(a_1, b)\gcd(a_2, b) \\\\
  \hline\\
  \text{GCD 1 Case} & \gcd(a, bc) = 1 \Leftrightarrow \gcd(a, b) = \gcd(a, c) = 1 \\\\
  \hline\\
  \text{Commutativity} & \gcd(a, b) = \gcd(b, a) \\\\
  \hline\\
  \text{Associativity} & \gcd(a, \gcd(b, c)) = \gcd(\gcd(a, b), c) \\\\
  \hline\\
  \text{GCD \& LCM} & \gcd(a, b) \cdot \text{lcm}(a, b) = |ab| \\\\
  \hline\\
  \text{Distributive 1} & \gcd(a, \text{lcm}(b, c)) = \text{lcm}(\gcd(a, b), \gcd(a, c)) \\\\
  \hline\\
  \text{Distributive 2} & \text{lcm}(a, \gcd(b, c)) = \gcd(\text{lcm}(a, b), \text{lcm}(a, c)) \\\\
  \hline\\
  \text{Prime Factor Form} & \gcd(a, b) = \prod p_i^{\min(e_i, f_i)} \text{ for } a = \prod p_i^{e_i}, b = \prod p_i^{f_i} \\\\
  \hline\\
  \text{Lattice Points} & \gcd(a, b) = \text{number of lattice points on the segment from } (0,0) \text{ to } (a,b) \\\\
  \hline\\
  \text{Power Mod Formula} & \gcd(n^a - 1, n^b - 1) = n^{\gcd(a, b)} - 1 \\\\
  \hline\\
  \text{Totient Identity} & \gcd(a, b) = \sum_{k \mid a,\,k \mid b} \varphi(k) \\\\
  \hline
  \end{array}
$$
> gcd(a,a) = a; Where a can be prime number
- https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf p29_sol

---

#### Examples:

- What is the largest positive integer that divides 40 and 78(gcd(a,b))?
- What about the smallest positive integer divisible by 40 and 78(lcm(a,b))?

<pre>
- Greedily, if we want to find the largest positive integer that divides 40 an 78, we need to selectively multiply together the largest power of each prime divisor common to both.
- To find the smallest positive integer divisible by both 40 and 78, we again take a greedy approach: selectively multiply together the smallest power of each prime divisor that satisfies the divisibility requirement. 
</pre>

- [AOPS_1951 AHSME Problems/Problem 19](https://artofproblemsolving.com/wiki/index.php/1951_AHSME_Problems/Problem_19)

<pre>
A six place number is formed by repeating a three place number; for example, 256256 or 678678, etc. Any number of this form is always exactly divisible by(gcd of all numbers of this forms)?
  
-> The number abcabc can be rewritten as 1000abc + abc (constructively, think of shifting the second abc three places to the right to make room for the first abc). Therefore, it is just 1001abc, and since nothing more can be said about abc, the answer is 1001 .
</pre>

- [1325A EhAb AnD gCd](1325A_EhAb_AnD_gCd.cpp)

<pre>
Find any such 2 positive integers a and b such that 
gcd(a,b) + lcm(a,b) = x, 2 <= x <= 1e9 (1,x-1)
</pre>

- https://codeforces.com/problemset/problem/1370/B
- https://codeforces.com/problemset/problem/1497/C1
- https://codeforces.com/contest/1521/problem/B

- https://codeforces.com/contest/2126/problem/E (gcd of prefix and suffix used lcm)

---

#### Advanced Examples

- https://toph.co/arena?practice=682312ad79c777c71ed66cbf#!/p/681cf32075e9694df049b36d

- https://codeforces.com/problemset/problem/1866/B

<pre>
LCM and GCD Relationships:
For any prime k, the exponent in LCM(p, q) is the maximum of the exponents of k in p and q.
For any prime k, the exponent in GCD(p, q) is the minimum of the exponents of k in p and q.

Exponent Conditions:
For each prime k in X and Y, we must have:
max(fk(p), fk(q)) = fk(X)
min(fk(p), fk(q)) = fk(Y)
Here, fk(p) denotes the exponent of prime k in p.

Feasibility Check:
If for any prime k, fk(Y) > fk(X), it's impossible to satisfy both conditions, so the answer is 0.
If fk(Y) = fk(X), then fk(p) = fk(q) = fk(X).
If fk(Y) < fk(X), there are two choices:
fk(p) = fk(X) and fk(q) = fk(Y).
fk(p) = fk(Y) and fk(q) = fk(X).
The final result is 2 raised to the power of the number of primes where the exponent in X is greater than in Y,
</pre>

- [343A_Rational Resistance](./4.euclidean_algorithms/343A_Rational%20Resistance.cpp)

<pre>
# needs to assemble an element with a resistance(1 ohm) equal to the fraction of a/b.

# determine the smallest possible number of resistors needs to make such an element.

has lots of identical resistors with unit (1 ohm) resistance. our need resistance value can be constructed with these.

e = x/y (resistance of a element, can be fraction because of parallelism)
series: (x/y)+1 => (x+y)/y >1; (1<=a,b<=1e18)
parallel: 1/((1/(x/y))+1/1) => x/(x+y) <1; (1<=a,b<=1e18)

# If a fraction a/b can be obtained with k resistors, then it is simple to calculate that we can obtain fractions (a+b)/b and a/(a+b) with k + 1 resistors.

So adding one resistor means performing one operation backwards in Euclidean algorithm. That means that the answer is equal to the number of steps in standard Euclidean algorithm.

a/b = 1 + f(x/y)
a > b => ((x+y)/y ~ a/b) =>x/y = a-b/a
---a/b = 1 + f(b,a-b)
a < b => (x/(x+y) ~ a/b) =>x/y = a/b-a
---a/b = 1 + f(a,b-a)

TLE-if use gcd(a,b-a)//O(N)~1e18

1+gcd(a%b,b) return lower value, we need upper value like 1+gcd(a-b,b)
ex. 1+gcd(100%1,1)=2 , 1+gcd(100-1,1)=100 ~because we need num of resister(total num of time it called)
but a/b + gcd(a%b,b) = 1+gcd(a-b,b) => produce same result

</pre>

---

- <u>Extended GCD</u>
<pre>
gcd(15,51) = 3, Bezout's Lemma say, 15x + 51y = 3

=>
15|51|3
45
--
6|15|2
12
--
<b>3</b>|6|2
6
--
0

51 = 15(3)+6 --- I
15 = 6(2)+3 --- II
6 = 3(2)+0 --- III

II=> 6(2) = 15-3 => 6 = (15-3)/2 ---IV
then from eq. I => 51 = 15(3)+6 => 51 = 15(3)+(15-3)/2;
=> 51(2) = 15(6) + 15 - 3 = 15(7) - 3
=> 3 = 15(6) + 51(-2)

</pre>

<pre>
# Finding Bézout Coefficients for gcd(8, 5) = 1

We want integers `x` and `y` such that:
8x + 5y = 1

Step 1: Apply the Euclidean Algorithm
We apply the Euclidean algorithm to compute gcd(8, 5):

8 = 5 × 1 + 3        (I)
5 = 3 × 1 + 2        (II)
3 = 2 × 1 + 1        (III)
2 = 1 × 2 + 0        (IV)

Since the remainder becomes 0 in the last step, the GCD is the previous remainder, which is 1.

Step 2: Back-Substitute to Find x and y
From (III):
1 = 3 - 2 × 1        (A)

From (II):
2 = 5 - 3 × 1        (B)

Substitute (B) into (A):
1 = 3 - (5 - 3 × 1) × 1
  = 3 - 5 × 1 + 3 × 1
  = 3 × 2 + 5 × (-1)

From (I):
3 = 8 - 5 × 1        (C)

Substitute (C) into the previous expression:
1 = (8 - 5 × 1) × 2 + 5 × (-1)
  = 8 × 2 - 5 × 2 + 5 × (-1)
  = 8 × 2 + 5 × (-3)

Final Result: Bézout Coefficients
x = 2, y = -3

Verification
8 × 2 + 5 × (-3) = 16 - 15 = 1 ✓

Thus, the Bézout identity holds: 8×2 + 5×(−3) = 1
</pre>

#### General Solution Structure

If `(x₀, y₀)` is one solution, then all solutions are given by:

```
x = x₀ + k ⋅ (b / d)
y = y₀ - k ⋅ (a / d)
```

where:

- `d = gcd(a, b)`
- `k` is any integer.

This means there are infinitely many integer solutions to the equation `ax + by = gcd(a, b)` if at least one solution exists.

```cpp
//using recursion
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
```

```cpp
//***
int ext_gcd(int A, int B, int *X, int *Y) {
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}
```

example:

- [uva10104 - Euclid Problem](uva10104_Euclid%20Problem.cpp)
<pre>
From Euclid it is known that for any positive integers A and B there exist such integers X and Y that AX + BY = D, where D is the greatest common divisor of A and B. The problem is to find for given A and B corresponding X, Y and D.

For each input line the output line should consist of three integers X, Y and D, separated with space.
If there are several such X and Y , you should output that pair for which |X| + |Y | is the minimal. If
there are several X and Y satisfying the minimal criteria, output the pair for which X ≤ Y .

</pre>

---
