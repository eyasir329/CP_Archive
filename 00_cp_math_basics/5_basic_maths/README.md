### Basic Maths

- (num>0) positive number
- (num>=0) non-negative number

https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf
![notation](https://i.ibb.co.com/3ND4tTj/IMG-0043.jpg)

#### floor, ceil and round

    floor-> floor((double)a/b) ~ a/b... ex. floor(7.3)=7
    ceil-> ceil((double)a/b) ~ (a+b-1)/b... ex. ceil(7.3)=8 [(a-1)/b +1]
    round-> round(double(a)/b)... ex. round(7.3)=7, round(7.5)=8

- if num is divisible by 2, then ceil(num)==floor(num), because it has not any fraction.

#### Series

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

    int n = 1e6;
    ll sum = 0; //O(N*N) not //O(NlogN) //because of j+=i
    for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j+=i){//look like -> n*harmonic
        sum+=j;
      }
    }
    //also same for this
    for(int i=1;i<=n;i++){
      for(int j=1;i*j<=n;j++){ // j = n/i
        sum+=j;
      }
    }

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

#### Permutation

```
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).
```

example:

- https://codeforces.com/contest/2071/problem/B

---

##### Modulo

<pre>
- make sure after each operation, the result is between 0 and m-1
- keep eyes in overflow.
- do not work in division in general ways.
- bitwise operation do not work with modular arithmetic.
</pre>

<pre>
    (x + y) mod m = (x mod m+ y mod m) mod m
    (a - b) mod m = (a mod m - b mod m + m) mod m
    (x · y) mod m = (x mod m· y mod m) mod m
    x^n mod m = (x mod m)^(n mod m-1)
</pre>

example:

- Find a closed form for the remainder of a ÷ m, where a, m ∈ Z+

  <pre>
  Because finding the remainder directly does not seem like an easy task, we first look for the quotient q. Because the quotient is the greatest number of times m goes into a, it is the integer part of a/m . But how do we truncate the fractional part? Apply the floor function! 
  
  q =⌊a/m⌋
  Our remainder becomes a − mq = <b>a − m⌊a/m⌋</b> <-- a % m
  </pre>

---

#### Primes

<pre>
- prime has exactly two divisors (1 & that number)
- other number can be represented by multiple of different prime numbers
</pre>

```cpp
//check n is prime or not
bool is_prime(long long n){
  if(n==1) return false;
  for(int i=2;1LL*i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
```

example:

- Prove that, for all primes p, the smallest positive integer whose factorial is divisible by p is p itself.

  <pre>
  It is trivial by inspection that p satisfies this condition. Let the smallest positive such
  integer be k. For the sake of contradiction, assume that k < p and p|k!. Then, k! is the product of all positive integers less than p and p is present in the prime factorization of k!. Some of the positive integers in this product are themselves primes less than p, while others are less than p and have unique prime factorizations involving only primes less than p by the fundamental theorem of arithmetic. Thus, p cannot be present in prime factorization of k!, establishing contradiction. This means that k = p. 
  </pre>

###### Co-Prime Numbers

<pre>
- no common factors other than one
</pre>

<img src="https://st.adda247.com/https://www.adda247.com/jobs/wp-content/uploads/sites/2/2022/11/15181619/Co-prime-numbers.png" alt="coprime" style="height:230px;">

example:

- [spoj_VECTAR8 - Primal Fear](./1_primes_and_divisors/1_primes/spoj_VECTAR8_Primal%20Fear.cpp)

<pre>
They are afraid of the prime numbers (without the digit zero), that remain prime no matter how many of the leading digits are omitted.

For example, they are afraid of 4632647 because it doesn't have the digit 0 and each of its truncations (632647, 32647, 2647, 647, 47, and 7) are primes. 

#given a number of N, find out the number of primes not greater that N, that changu and mangu are afraid of.

T ≤ 10^5, 1 ≤ N < 10^6

if(num has digit 0)return false;
if(it's truncations not prime)return false;
otherwise true;
</pre>

- [spoj_HS08PAUL_A conjecture of Paul Erdős](./1.primes/spoj_HS08PAUL_A%20conjecture%20of%20Paul%20Erdős.cpp)

<pre>
#find the number of (positive) primes not larger than n which are of the form x2+y4 (where x and y are integers).
</pre>

---

##### Divisors

<pre>
- odd number of divisors are perfect square (i==n/i we eliminate one divisors because of unique divisors.) (ex. cf2020B)
- otherwise all other number has even number of divisors
</pre>

```cpp
//finding divisors using sqrt method O(sqrt(n))
//used to find single number
vector<int>divisors_of_n(int n) {
    vector<int>divisors;
    //we have to maintain (i*i) not go to overflow
    //if(overflow) then it go to infinite loop
    for (int i = 1; i * i <= n; i++) {//because of sqrt()-> may cause precision error
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {//because of unique divisors
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (auto x : divisors) {
        cout << x << " ";
    }
    return divisors;
}
```

- Number of Divisors from 1 to N (Each Number)

<pre>
  normal way O(nsqrt(n) causes TLE) (n upto 1e5)-> O(nlogn)
</pre>

```cpp
//complexity O(nlogn)
//used to find multiple number
const int N = 1e7+9;
int d[N];
for(int i=1;i<N;i++){
  for(int j=i;j<N;j+=i){//harmonic series
    d[j]++;
  }
}
// if(d[i]==2) -> they are prime
```

```cpp
for(int i=1;i<=n;i++){
  if(n%i==0){
    cout<<i<<" ";
  }
}
```

- (b | a) -> b divide a

example:

- [1485A_Add and Divide](https://codeforces.com/problemset/problem/1485/A)
  <pre>
  You can perform two kinds of operations:
  
      a=⌊a/b⌋ (replace a with the integer part of the division between a and b)
      b=b+1 (increase b by 1) 
  
  Find the minimum number of operations required to make a=0
  </pre>

  <pre>
  we can try to increase b to a certain value and then divide a by b until it is 0. Being careful as not to do this with b<2, the number of times we divide is going to be O(loga). In particular, if you reach b≥2 (this requires at most 1 move), you need at most ⌊log2(10^9)⌋=29 moves to finish.
  
  Let y be the number of moves of type 2; we can try all values of y (0≤y≤30) and, for each y, check how many moves of type 1 are necessary.
  
  Complexity: O(log^2 a)
  </pre>

- [2029A_Set]()
- One of the first 1234567 positive integers is chosen at random. Compute the
  probability that it is divisible by 3?

  <pre>
  -> Pattern Identification:
    Every third number in the sequence of positive integers is divisible by 3:
    - Example: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, ...
    - From this pattern, it's clear that every package of three numbers contains exactly **one** divisible by 3.
  
  -> Count Numbers Divisible by 3:
      To find how many numbers in the first 1234567 are divisible by 3: floor(1234567/3)
  
  -> Calculate Probability:
      The probability of selecting a number divisible by 3 is:
      P = Numbers Divisible by 3 / Total Numbers = 411522 / 1234567 ≈ 0.33333306
  
  -> Result:
      This matches the expected approximation of 1/3, derived from the pattern of divisibility.
  
  - The probability `P ≈ 1/3` arises naturally from the definition of divisibility.
  - The slight deviation from `1/3` comes from the truncation during integer division.
  
  This method demonstrates how understanding divisibility patterns simplifies complex calculations.
  </pre>

- Find all integers x for which it can be said that the positive integer 2x + 9 divides the positive integer 3x + 4?

  <pre>
  From the problem statement, we can extract the following requirements:
  x ∈ Z
  2x + 9 ∈ Z+ =⇒ x ∈ Z≥−4
  3x + 4 ∈ Z+ =⇒ x ∈ Z≥−1
  3x + 4 ≥ 2x + 9 =⇒ x ∈ Z≥5
  Additionally, we require
  (3x + 4)/(2x + 9) = 1 + (x − 5)/(2x + 9) =⇒ (x − 5)/(2x + 9) ∈ Z≥0.
  This secondary requirement means that either x = 5 or
  x − 5 ≥ 2x + 9 =⇒ x ∈ Z≤−14.
  The second case is clearly impossible due to the strict x ∈ Z≥5 requirement from earlier, so the only valid integer x is 5 .
  </pre>

#### Perfect Square

<pre>
- odd number of divisors are perfect square (i==n/i we eliminate one divisors because of unique divisors.)
- otherwise all other number has even number of divisors
</pre>

```cpp
bool isSquare(i64 n) {
    int x = std::sqrt(n);
    return 1LL * x * x == n;
}
```

example:

- https://codeforces.com/contest/2071/problem/B
- https://codeforces.com/contest/2020/problem/B
- https://codeforces.com/contest/2031/problem/C

## Factorization

- [576A_Vasya and Petya's Game](./2.divisors/576A_Vasya%20and%20Petya's%20Game.cpp)

<pre>
# thought of number x between 1 and n, another tries to guess the number
# another can ask, is the unknown number divisible by number y?
# find the minimum number of questions he should ask to make a guaranteed guess number.

n factorize = (2,2,2,3,5...y)
if(n is divisible y) y*y until find n.. then next y

</pre>

---

## Euclidean Algorithms

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

#### GCD, LCM

[Properties of GCD function](https://codeforces.com/blog/entry/95694)

<pre>
lcm(a,b) = (a*b)/gcd(a,b)
</pre>

example:

https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf p29_sol

- What is the largest positive integer that divides 40 and 78(gcd(a,b))? What about the smallest positive integer divisible by 40 and 78(lcm(a,b))?

  <pre>
  - Greedily, if we want to find the largest positive integer that divides 40 an 78, we need to selectively multiply together the largest power of each prime divisor common to both.
  - To find the smallest positive integer divisible by both 40 and 78, we again take a greedy approach: selectively multiply together the smallest power of each prime divisor that satisfies the divisibility requirement. 
  </pre>

- [AOPS_1951 AHSME Problems/Problem 19](https://artofproblemsolving.com/wiki/index.php/1951_AHSME_Problems/Problem_19)

  <pre>
  A six place number is formed by repeating a three place number; for example, 256256 or 678678, etc. Any number of this form is always exactly divisible by(gcd of all numbers of this forms)?
  
  -> The number abcabc can be rewritten as 1000abc + abc (constructively, think of shifting the second abc three places to the right to make room for the first abc). Therefore, it is just 1001abc, and since nothing more can be said about abc, the answer is 1001 .
  </pre>

---
