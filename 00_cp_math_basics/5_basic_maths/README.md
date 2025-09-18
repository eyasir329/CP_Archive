## Table of Contents

- [Introduction](#introduction)
- [Floor, Ceil, and Round](#floor-ceil-and-round)
- [C++ Math Functions in Standard Library](#c++_math_functions_in_standard_library)
- [Series and Progression](#series-and-progression)
- [Harmonic Series](#harmonic-series)
- [Important Perimeter Formulas for Geometry](#important-formulas)
- [Area Formulas](#area-formulas)
- [Square Root Problems](#square-root-problems)
- [Miscellaneous](#miscellaneous)

---

## Introduction

- **$\text{num} > 0$** means a positive number
- **$\text{num} \geq 0$** means a non-negative number
- x<sup>0</sup> = 0, even if x == 0

Reference:
[The Art of Modular Arithmetic (PDF)](https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf)

![Notation](https://i.ibb.co/3ND4tTj/IMG-0043.jpg)

---

## Floor, Ceil, and Round

> inside double only

$$
\begin{aligned}
&\text{floor} \to \left\lfloor \frac{a}{b} \right\rfloor \approx \frac{a}{b}, \quad \text{e.g. } \lfloor 7.3 \rfloor = 7 \\
&\text{ceil} \to \left\lceil \frac{a}{b} \right\rceil \approx \frac{a + b - 1}{b}, \quad \text{e.g. } \lceil 7.3 \rceil = 8 \\
&\text{round} \to \text{round}\left(\frac{a}{b}\right), \quad \text{e.g. } \text{round}(7.3) = 7, \quad \text{round}(7.5) = 8
\end{aligned}
$$

Also:

$$
\text{ceil}\left(\frac{n}{x}\right) = \frac{n + x - 1}{x}
$$

- If $\text{num}$ is divisible by 2, then $\text{ceil}(\text{num}) = \text{floor}(\text{num})$, since no fractional part exists.

---

## C++ Math Functions in Standard Library

Here's a comprehensive table of common math functions available in the C++ standard library (`<cmath>` header):

| Function Name   | Math Name           | Description                        | Example                        |
| --------------- | ------------------- | ---------------------------------- | ------------------------------ |
| abs(x)          | Absolute value      | Returns absolute value of integer  | abs(-5) returns 5              |
| fabs(x)         | Absolute value      | Returns absolute value of float    | fabs(-3.5) returns 3.5         |
| pow(x, y)       | Power               | Raises x to the power of y         | pow(2, 3) returns 8            |
| sqrt(x)         | Square root         | Returns square root of x           | sqrt(16) returns 4             |
| cbrt(x)         | Cube root           | Returns cube root of x             | cbrt(27) returns 3             |
| exp(x)          | Exponential         | Returns e raised to x              | exp(1) returns ~2.71828        |
| exp2(x)         | Binary exponent     | Returns 2 raised to x              | exp2(3) returns 8              |
| log(x)          | Natural log         | Returns natural log (base e)       | log(2.71828) returns ~1        |
| log10(x)        | Common log          | Returns log base 10                | log10(100) returns 2           |
| log2(x)         | Binary log          | Returns log base 2                 | log2(8) returns 3              |
| sin(x)          | Sine                | Returns sine of x (radians)        | sin(M_PI/2) returns ~1         |
| cos(x)          | Cosine              | Returns cosine of x (radians)      | cos(M_PI) returns ~-1          |
| tan(x)          | Tangent             | Returns tangent of x (radians)     | tan(M_PI/4) returns ~1         |
| asin(x)         | Arcsine             | Returns arcsine of x               | asin(1) returns M_PI/2         |
| acos(x)         | Arccosine           | Returns arccosine of x             | acos(0) returns M_PI/2         |
| atan(x)         | Arctangent          | Returns arctangent of x            | atan(1) returns M_PI/4         |
| atan2(y, x)     | Arctangent of y/x   | Returns angle from x-axis to point | atan2(1,1) returns M_PI/4      |
| sinh(x)         | Hyperbolic sine     | Returns hyperbolic sine of x       | sinh(0) returns 0              |
| cosh(x)         | Hyperbolic cosine   | Returns hyperbolic cosine of x     | cosh(0) returns 1              |
| tanh(x)         | Hyperbolic tangent  | Returns hyperbolic tangent of x    | tanh(0) returns 0              |
| ceil(x)         | Ceiling             | Rounds up to nearest integer       | ceil(2.3) returns 3            |
| floor(x)        | Floor               | Rounds down to nearest integer     | floor(2.9) returns 2           |
| round(x)        | Round               | Rounds to nearest integer          | round(2.5) returns 3           |
| trunc(x)        | Truncate            | Drops fractional part              | trunc(2.9) returns 2           |
| fmod(x, y)      | Modulo              | Returns remainder of x/y           | fmod(5.5, 2) returns 1.5       |
| remainder(x, y) | Remainder           | IEEE remainder of x/y              | remainder(5.5, 2) returns -0.5 |
| copysign(x, y)  | Copy sign           | Returns x with y's sign            | copysign(5.0, -1) returns -5.0 |
| fmax(x, y)      | Maximum             | Returns larger of two values       | fmax(2, 5) returns 5           |
| fmin(x, y)      | Minimum             | Returns smaller of two values      | fmin(2, 5) returns 2           |
| fdim(x, y)      | Positive difference | Returns x-y if x>y, else 0         | fdim(5, 3) returns 2           |
| hypot(x, y)     | Hypotenuse          | Returns sqrt(x² + y²)              | hypot(3, 4) returns 5          |

Note:

1. Most functions are in the `<cmath>` header (for floating-point) and `<cstdlib>` for integer math
2. For C++, consider using `std::` prefix (e.g., `std::sqrt()`)
3. Many functions have type-specific variants (e.g., `abs()` for int, `fabs()` for double)
4. Trigonometric functions use radians, not degrees

---

## Series and Progression

Summation formulas reference:
[Cuemath Summation Formulas](https://www.cuemath.com/summation-formulas/)

![Formulas](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/correction-1718966351.jpg)

### 📐 Progressions

#### **Arithmetic Progression (AP)**

A sequence with a **constant difference** between consecutive terms.

- **nth term:**

  $$
  a_n = a + (n-1)d
  $$

- **Sum of first _n_ terms:**

  $$
  S_n = \frac{n}{2}(2a + (n-1)d) = n \times \frac{a_1 + a_n}{2}
  $$

#### **Geometric Progression (GP)**

A sequence with a **constant ratio** between consecutive terms.

- **nth term:**

  $$
  a_n = a \times r^{n-1}
  $$

- **Sum of first _n_ terms:**

  $$
  S_n =
  \begin{cases}
  a \times \frac{r^n - 1}{r - 1}, & r \ne 1 \\
  n \times a, & r = 1
  \end{cases}
  $$

- **Sum of infinite terms (for** $|r| < 1$ **):**

  $$
  S_\infty = \frac{a}{1 - r}
  $$

> 🔺 **Note:** Watch for overflow in large values — use `long long` or `1LL *` as needed.

---

### ➕ Summation Formulas

- **Sum of first _n_ natural numbers:**

  $$
  \sum_{k=1}^n k = \frac{n(n+1)}{2}
  $$

- **Sum of squares of first _n_ natural numbers:**

  $$
  \sum_{k=1}^n k^2 = \frac{n(n+1)(2n+1)}{6}
  $$

- **Sum of cubes of first _n_ natural numbers:**

  $$
  \sum_{k=1}^n k^3 = \left( \frac{n(n+1)}{2} \right)^2
  $$

- sum of first n odd positive number -> n^2
- sum of first n even positive number -> n(n+1)

- https://vjudge.net/problem/codeforces-318a
---

Example problem: [Codeforces 2117D](https://codeforces.com/contest/2117/problem/D)

- https://codeforces.com/problemset/problem/1406/B
- https://codeforces.com/problemset/problem/598/A

### Ranges

- https://codeforces.com/problemset/problem/1409/C

---

## Harmonic Series

References:

- [Physics116A Harmonic Series PDF](https://scipp.ucsc.edu/~haber/archives/physics116A10/harmapa.pdf)
- [Math Drexel Harmonic Series PDF](https://www.math.drexel.edu/~tolya/123_harmonic.pdf)

# Upper Bound for the Harmonic Series

The **harmonic series** is defined as:

$$
H_n = \sum_{k=1}^n \frac{1}{k}.
$$

Although the harmonic series diverges as 𝑛 → ∞, we can establish a simple **upper bound** using a grouping argument:

---

## Result

$$
\sum_{k=1}^n \frac{1}{k} \;\leq\; \lfloor \log_2(n) \rfloor + 1
$$

---

## Proof (Sketch)

1. **Group terms by powers of two**

   For \(n = 2^m\):

   $$
   H_n = 1 +
   \left(\frac{1}{2} + \frac{1}{3}\right) +
   \left(\frac{1}{4} + \frac{1}{5} + \frac{1}{6} + \frac{1}{7}\right) +
   \cdots +
   \left(\frac{1}{2^{m-1}} + \cdots + \frac{1}{2^m - 1}\right).
   $$

2. **Bound each group**

   - Each group has \(2^{k-1}\) terms.
   - Each term is at most \(\tfrac{1}{2^{k-1}}\).
   - So the sum of the \(k\)-th group is:

   $$
   2^{k-1} \cdot \frac{1}{2^{k-1}} = 1.
   $$

3. **Count the groups**

   - There are \(m\) groups, so:

   $$
   H_n \leq m.
   $$

   - Since \(n = 2^m\), we have:

   $$
   m = \log_2(n).
   $$

   - For general \(n\):

   $$
   \sum_{k=1}^n \frac{1}{k} \;\leq\; \lfloor \log_2(n) \rfloor + 1.
   $$

---

## Key Takeaway

- The harmonic series **diverges slowly**.
- Its growth is approximately logarithmic:

$$
H_n \approx \ln n + \gamma,
$$

where \(\gamma \approx 0.577\) is the **Euler–Mascheroni constant**.

- A simple but useful bound is:

$$
H_n \leq \log_2(n) + 1.
$$

Example code snippet (Complexity \~ $O(n \log n)$):

```cpp
int n = 1e6;
ll sum = 0;
for (int i = 1; i <= n; i++) {
  for (int j = i; j <= n; j += i) {
    sum += j;
  }
}
```

Equivalent alternative:

```cpp
for (int i = 1; i <= n; i++) {
  for (int j = 1; i * j <= n; j++) {
    sum += j;
  }
}
```

Example: [kuet_iupc_K-Beast (Google Drive)](https://drive.google.com/file/d/1grOQsUBx4PWC9-tIAFXF62PmEvckOji0/view)

> A beast attacks the land. $N$ shooters fire bullets every $i$ th minute (shooter $i$).
> Beast requires $K$ bullets to die. Multiple bullets in the same minute all count.
> Find the exact minute beast is destroyed.

[CF Blog Reference](https://codeforces.com/blog/entry/118001)

---

## Important Formulas

![Perimeter Formulas](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/perimeter-formulas-1622782913.png)

- [Triangles - Cuemath](https://www.cuemath.com/geometry/triangles/)
- [Median & Centroid - Khan Academy](https://www.khanacademy.org/math/geometry-home/triangle-properties/medians-centroids/v/triangle-medians-and-centroids)

---

### Area Formulas

- Semi-perimeter of a triangle:
  $s = \frac{a + b + c}{2}$

- Area of triangle (various formulas):

  $$
  \frac{1}{2} \times \text{base} \times \text{height} = \frac{1}{2}ab \sin C = \sqrt{s(s - a)(s - b)(s - c)}
  $$

- Area of right triangle:
  $\frac{1}{2}ab$

- Area of equilateral triangle (side length $a$):
  $\frac{a^2 \sqrt{3}}{4}$

- Area of equilateral triangle (using altitude $h$):
  $\frac{h^2 \sqrt{3}}{3}$

- Area of rectangle:
  $\text{base} \times \text{height}$

- Area of square:
  $\text{base}^2 = \frac{1}{2} \times \text{diagonal}^2$

- Area of parallelogram:
  $\text{base} \times \text{height} = ab \sin C$

- Area of rhombus:
  $\frac{1}{2} d_1 d_2$

- Area of trapezoid:
  $\frac{1}{2} h (b_1 + b_2)$

- Area of regular polygon (with apothem $a$ and perimeter $p$):
  $\frac{1}{2} a p$

- Area of circle (radius $r$, diameter $d = 2r$):
  $\pi r^2 = \frac{\pi d^2}{4}$

- Area of sector of a circle (central angle $n$ degrees):
  $\frac{n}{360} \pi r^2$

- Circumference of a circle:
  $2 \pi r$

- Length of an arc (angle $n$):
  $\frac{n}{360} \times 2 \pi r$

---

## Example Problems

- [BAPSOJ ICPC Preliminary Dhaka Site 2024 - Problem F](https://bapsoj.org/contests/icpc-preliminary-dhaka-site-2024/problems/F)
- [Codeforces 1463A](https://codeforces.com/contest/1463/problem/A)
- [Codeforces 1478B](https://codeforces.com/problemset/problem/1478/B)

- [Codeforces 1455B](https://codeforces.com/problemset/problem/1455/B)
  > $$
  > \begin{aligned}
  > a_i &\text{ can be expressed as a sum of several lucky numbers.} \\
  > \text{If there exists } c &= a - k \times d, \quad c \geq 0, \text{ and } c \text{ contains the digit } d, \\
  > \text{then } a &= c + k \times d. \\
  > \text{We check all possible } c &\text{ by subtracting } d \text{ repeatedly from } a \text{ until } c \leq 0. \\
  > \text{If } a &\geq 10 \times d, \text{ it is always possible to write } a \text{ in this way}.
  > \end{aligned}
  > $$

---

## Square Root Problems

- https://www.cuemath.com/algebra/squares-and-square-roots/

> Examples

- https://acm.timus.ru/problem.aspx?num=1001&space=1

* [Codeforces 1426C](https://codeforces.com/problemset/problem/1426/C)

---

## Miscellaneous

> Problem with Precisions

- [Codeforces 1598C](https://codeforces.com/problemset/problem/1598/C)
- [AtCoder ABC136 B](https://atcoder.jp/contests/abc136/tasks/abc136_b)

### Sum of a Two Numbers

- https://codeforces.com/contest/2132/problem/B

---
