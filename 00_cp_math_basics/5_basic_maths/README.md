## Table of Contents

* [Introduction](#introduction)
* [Floor, Ceil, and Round](#floor-ceil-and-round)
* [Series and Progression](#series-and-progression)
* [Harmonic Series](#harmonic-series)
* [Important Formulas](#important-formulas)
* [Area Formulas](#area-formulas)
* [Example Problems](#example-problems)
* [Square Root Problems](#square-root-problems)
* [Miscellaneous](#miscellaneous)

---

## Introduction

* **$\text{num} > 0$** means a positive number
* **$\text{num} \geq 0$** means a non-negative number

Reference:
[The Art of Modular Arithmetic (PDF)](https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf)

![Notation](https://i.ibb.co/3ND4tTj/IMG-0043.jpg)

---

## Floor, Ceil, and Round 
>inside double only

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

* If $\text{num}$ is divisible by 2, then $\text{ceil}(\text{num}) = \text{floor}(\text{num})$, since no fractional part exists.

---

## Series and Progression

Summation formulas reference:
[Cuemath Summation Formulas](https://www.cuemath.com/summation-formulas/)

![Formulas](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/correction-1718966351.jpg)


### 📐 Progressions

#### **Arithmetic Progression (AP)**

A sequence with a **constant difference** between consecutive terms.

* **nth term:**

  $$
  a_n = a + (n-1)d
  $$

* **Sum of first *n* terms:**

  $$
  S_n = \frac{n}{2}(2a + (n-1)d) = n \times \frac{a_1 + a_n}{2}
  $$

#### **Geometric Progression (GP)**

A sequence with a **constant ratio** between consecutive terms.

* **nth term:**

  $$
  a_n = a \times r^{n-1}
  $$

* **Sum of first *n* terms:**

  $$
  S_n =
  \begin{cases}
  a \times \frac{r^n - 1}{r - 1}, & r \ne 1 \\
  n \times a, & r = 1
  \end{cases}
  $$

* **Sum of infinite terms (for** $|r| < 1$ **):**

  $$
  S_\infty = \frac{a}{1 - r}
  $$

> 🔺 **Note:** Watch for overflow in large values — use `long long` or `1LL *` as needed.

---

### ➕ Summation Formulas

* **Sum of first *n* natural numbers:**

  $$
  \sum_{k=1}^n k = \frac{n(n+1)}{2}
  $$

* **Sum of squares of first *n* natural numbers:**

  $$
  \sum_{k=1}^n k^2 = \frac{n(n+1)(2n+1)}{6}
  $$

* **Sum of cubes of first *n* natural numbers:**

  $$
  \sum_{k=1}^n k^3 = \left( \frac{n(n+1)}{2} \right)^2
  $$

---

![Useful Math Functions](https://miro.medium.com/v2/resize\:fit:1023/1*gQ6RMxhKkPauq92rqFv9-Q.jpeg)

Example problem: [Codeforces 2117D](https://codeforces.com/contest/2117/problem/D)

---

## Harmonic Series

References:

* [Physics116A Harmonic Series PDF](https://scipp.ucsc.edu/~haber/archives/physics116A10/harmapa.pdf)
* [Math Drexel Harmonic Series PDF](https://www.math.drexel.edu/~tolya/123_harmonic.pdf)

<img src="https://steemitimages.com/640x0/http://i.imgur.com/vifeHmZ.png" alt="Harmonic Series" style="height:60px;">

Inequality:

$$
\sum_{k=1}^n \frac{1}{k} \leq \lfloor \log_2(n) \rfloor + 1
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

Example: [kuet\_iupc\_K-Beast (Google Drive)](https://drive.google.com/file/d/1grOQsUBx4PWC9-tIAFXF62PmEvckOji0/view)

> A beast attacks the land. $N$ shooters fire bullets every $i$ th minute (shooter $i$).
> Beast requires $K$ bullets to die. Multiple bullets in the same minute all count.
> Find the exact minute beast is destroyed.

[CF Blog Reference](https://codeforces.com/blog/entry/118001)

---

## Important Formulas

![Perimeter Formulas](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/perimeter-formulas-1622782913.png)

* [Triangles - Cuemath](https://www.cuemath.com/geometry/triangles/)
* [Median & Centroid - Khan Academy](https://www.khanacademy.org/math/geometry-home/triangle-properties/medians-centroids/v/triangle-medians-and-centroids)

---

### Area Formulas

* Semi-perimeter of a triangle:
  $s = \frac{a + b + c}{2}$

* Area of triangle (various formulas):

  $$
  \frac{1}{2} \times \text{base} \times \text{height} = \frac{1}{2}ab \sin C = \sqrt{s(s - a)(s - b)(s - c)}
  $$

* Area of right triangle:
  $\frac{1}{2}ab$

* Area of equilateral triangle (side length $a$):
  $\frac{a^2 \sqrt{3}}{4}$

* Area of equilateral triangle (using altitude $h$):
  $\frac{h^2 \sqrt{3}}{3}$

* Area of rectangle:
  $\text{base} \times \text{height}$

* Area of square:
  $\text{base}^2 = \frac{1}{2} \times \text{diagonal}^2$

* Area of parallelogram:
  $\text{base} \times \text{height} = ab \sin C$

* Area of rhombus:
  $\frac{1}{2} d_1 d_2$

* Area of trapezoid:
  $\frac{1}{2} h (b_1 + b_2)$

* Area of regular polygon (with apothem $a$ and perimeter $p$):
  $\frac{1}{2} a p$

* Area of circle (radius $r$, diameter $d = 2r$):
  $\pi r^2 = \frac{\pi d^2}{4}$

* Area of sector of a circle (central angle $n$ degrees):
  $\frac{n}{360} \pi r^2$

* Circumference of a circle:
  $2 \pi r$

* Length of an arc (angle $n$):
  $\frac{n}{360} \times 2 \pi r$

---

## Example Problems

* [BAPSOJ ICPC Preliminary Dhaka Site 2024 - Problem F](https://bapsoj.org/contests/icpc-preliminary-dhaka-site-2024/problems/F)
* [Codeforces 1463A](https://codeforces.com/contest/1463/problem/A)
* [Codeforces 1478B](https://codeforces.com/problemset/problem/1478/B)

* [Codeforces 1455B](https://codeforces.com/problemset/problem/1455/B)
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

* [Codeforces 1426C](https://codeforces.com/problemset/problem/1426/C)

---

## Miscellaneous

### Precision

* [Codeforces 1598C](https://codeforces.com/problemset/problem/1598/C)
* [AtCoder ABC136 B](https://atcoder.jp/contests/abc136/tasks/abc136_b)

---