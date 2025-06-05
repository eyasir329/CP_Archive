### Basic Maths

- (num>0) positive number
- (num>=0) non-negative number

https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf
![notation](https://i.ibb.co.com/3ND4tTj/IMG-0043.jpg)

#### floor, ceil and round

    floor-> floor((double)a/b) ~ a/b... ex. floor(7.3)=7
    ceil-> ceil((double)a/b) ~ (a+b-1)/b... ex. ceil(7.3)=8 [(a-1)/b +1]
    round-> round(double(a)/b)... ex. round(7.3)=7, round(7.5)=8

    ceil(n/x) = (n+x-1)/x;

- if num is divisible by 2, then ceil(num)==floor(num), because it has not any fraction.

#### Series and Progression

https://www.cuemath.com/summation-formulas/
![formula](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/correction-1718966351.jpg)

- arithmetic progression - difference beteen adjacent two numbers are same.

formula can generate by: n\*(first+last)/2;

- geometric progression - ratio between two consecutive numbers is constant.

r > 1 => s = a*(r<sup>n</sup>-1)/(r-1) <br>
r = 1 => s = na #ar<sup>n-1</sup> formula <br>
0 < r < 1 => s = a*(1-r<sup>n</sup>)/(1-r) <br>

<code>Notes : check overflow(if then apply as long long(1LL)), oterwise give wrong answer.
</code>

![useful math functions](https://miro.medium.com/v2/resize:fit:1023/1*gQ6RMxhKkPauq92rqFv9-Q.jpeg)

#### Harmonic Series

https://scipp.ucsc.edu/~haber/archives/physics116A10/harmapa.pdf
https://www.math.drexel.edu/~tolya/123_harmonic.pdf

<img src="https://steemitimages.com/640x0/http://i.imgur.com/vifeHmZ.png" alt="harmonic series" style="height: 60px;">

sum <= floor(log2(n)) + 1

```cpp
int n = 1e6;
ll sum = 0; //O(N*N) not //O(NlogN) //because of j+=i
for (int i = 1; i <= n; i++) {
  for (int j = i; j <= n; j += i) { //look like -> n*harmonic
    sum += j;
  }
}
//also same for this
for (int i = 1; i <= n; i++) {
  for (int j = 1; i * j <= n; j++) { // j = n/i
    sum += j;
  }
}
```

example:

- [kuet_iupc_K-Beast](https://drive.google.com/file/d/1grOQsUBx4PWC9-tIAFXF62PmEvckOji0/view)

<pre>
A terrifying beast is attacking the land. To defeat it, the king has deployed N shooters, each firing bullets at their own steady pace. The ith shooter fires a bullet every ith minute.

The beast requires exactly K bullets to be destroyed. If multiple shooters fire at the same minute, all bullets count toward the total. Your task is to determine the exact minute when the beast is destroyed.
</pre>

https://codeforces.com/blog/entry/118001

#### Some formulas

<img src="https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/perimeter-formulas-1622782913.png" alt="Perimeter Formulas" height="839">

- [Triangles](https://www.cuemath.com/geometry/triangles/)
- [Median & Centroid](https://www.khanacademy.org/math/geometry-home/triangle-properties/medians-centroids/v/triangle-medians-and-centroids)

      sum of natural numbers = (n * (n + 1)) / 2;
      sum of square of natural numbers = (n * (n + 1) * ((2 * n) + 1)) / 6;
      sum of cubes of natural numbers = ((n * n) * (n + 1) * (n + 1)) / 4;
      nth term of an arithmetic sequence = a + ((n - 1) * d);
      sum of arithmetic series (number of terms * average of first and last item) = (n * ((2 * a) + ((n - 1) * d))) / 2;
      nth term of geometric sequence = a * pow(r, n - 1);[a = first_term, r = common ration];
      sum of geometric sequence = (a * (pow(r, n) - 1)) / (r - 1);[r != 1];
      sum of an infinite geometric sequence = a / (1 - r);[r < 1];

      area:

      semi perimeter (triangle)s = 1/2 * (a + b + c);
      area(triangle) = (1/2 * base * height) = (1/2*a*b*sin(C)) = sqrt(s * (s - a) * (s - b) * (s - c));
      area(right triangle) = (1/2 * a * b);
      area(equilateral triangle) = (a^2 * sqrt(3)) / 4; [a = side_length]
      area(equilateral triangle) = (h^2 * sqrt(3)) / 3; [h = altitude, height]
      area(rectangle) = base  * height;
      area(square) = base^2 = (1/2 * diagonal^2);
      area(parallelogram) = (base * height) = a*b*sin(C);
      area(rhombus) = (1/2 * d1 * d2); [d1 = diagonal1, d2 = diagonal2]
      area(trapezoid) = (1/2 * h * (b1 + b2)); [b1 and b2 are two parallel side, h = distance between d1 and d2]
      area(regular polygon) = (1/2 * a * p) [a (apothem)= the distance from the center to the midpoint of one of its side, p = perimeter]
      area(circle) = (pi * r^2) = (pi * d^2) / 4; [d = diameter = 2 * r];
      area(sector of circle) = ((n/360) * pi * r^2);[n = measure of the central angle]

      circumference / perimeter
      circumference(circle) = (2 * pi * r);
      length of an arc of a circle = ((n/360) * 2 * pi * r);

---

example:

- https://bapsoj.org/contests/icpc-preliminary-dhaka-site-2024/problems/F
- https://codeforces.com/contest/1463/problem/A
- https://codeforces.com/problemset/problem/1478/B

<pre>
a<sub>i</sub> can be equal to a sum of several (one or more) lucky numbers.

For any number a, if you can find a number c (where c = a - k*d for some k) such that c is non-negative and contains the digit d, then a can be written as c + k*d (where k*d is part of the sum and c contains the digit d). Thus, the solution checks all possible c values by repeatedly subtracting d from a until c becomes non-positive, and for each c, it checks if any of its digits is d.

If a is large enough (specifically, a >= 10*d), then it's always possible to express a as the sum of numbers where at least one contains the digit d. This is because for a >= 10*d, we can always find a number between a - 10*d and a that contains the digit d in its tens or units place.
</pre>

### SQRT

- https://codeforces.com/problemset/problem/1426/C

### Miscllaneous
