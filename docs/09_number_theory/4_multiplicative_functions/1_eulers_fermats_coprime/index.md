---
title: "1 eulers fermats coprime"
nav_order: 1
---


<pre>
- no common factors other than one
</pre>

<img src="https://st.adda247.com/https://www.adda247.com/jobs/wp-content/uploads/sites/2/2022/11/15181619/Co-prime-numbers.png" alt="coprime" style="height:230px;">

- [ How Many Primes are There? ](https://t5k.org/howmany.html)

example:

- [spoj_VECTAR8 - Primal Fear](./spoj_VECTAR8_Primal%20Fear.cpp)

<pre>
They are afraid of the prime numbers (without the digit zero), that remain prime no matter how many of the leading digits are omitted.

For example, they are afraid of 4632647 because it doesn't have the digit 0 and each of its truncations (632647, 32647, 2647, 647, 47, and 7) are primes. 

#given a number of N, find out the number of primes not greater that N, that changu and mangu are afraid of.

T ≤ 10^5, 1 ≤ N < 10^6

if(num has digit 0)return false;
if(it's truncations not prime)return false;
otherwise true;
</pre>

- [spoj_HS08PAUL_A conjecture of Paul Erdős](./spoj_HS08PAUL_A%20conjecture%20of%20Paul%20Erdős.cpp)

<pre>
#find the number of (positive) primes not larger than n which are of the form x2+y4 (where x and y are integers).
</pre>

---

### Fermat's Little Theorem

https://en.wikipedia.org/wiki/Fermat's_little_theorem

<pre>
In number theory, Fermat's little theorem states that if p is a prime number, then <b>for any integer a, the number a<sup>p</sup> − a is an integer multiple of p</b>. In the notation of modular arithmetic, this is expressed as a^p ≡ a (mod p)
For example, if a = 2 and p = 7, then 2^7 = 128, and 128 − 2 = 126 = 7 × 18 is an integer multiple of 7. 

- Let p be a prime which does not divide the integer a(a is coprime to p), then <b>a<sup>p-1</sup> ≡ 1 (mod p)</b>.
For example, if a = 2 and p = 7, then 2^6 = 64, and 64 − 1 = 63 = 7 × 9 is a multiple of 7. 

Fermat's(Pierre de Fermat) little theorem says that as long as the modulus m is a prime number (1e9+7 is prime, and so is 998 244 353, then a<sup>m</sup> mod m = a mod m. Working backwards, a<sup>m−1</sup> mod m = 1 = a⋅a<sup>m−2</sup>  mod m

Note that this only works for a mod m≠0, because there is no number x such that 0⋅x  mod m=1. In other words, you still can't divide by 0.

Fermat’s theorem states that, x<sup>m−1</sup> mod m = 1, when m is prime and x and m are coprime. This also yields x<sup>k</sup> mod m = x<sup>k mod (m−1)</sup> mod m.
</pre>

- [<u>Proof of Fermat's Little Theorem</u>](https://t5k.org/notes/proofs/FermatsLittleTheorem.html)

<pre>
x<sup>n</sup> ≡ x<sup>n mod (p-1)</sup> (mod p), if p is prime 
- because x^0, x^1, x^2 ... cycles after p-1 terms

More generally, Euler’s theorem states that, x<sup>ϕ(m)</sup> mod m = 1, when x and m are coprime. Fermat’s theorem follows from Euler’s theorem, because if m is a prime, then ϕ(m) = m − 1.
</pre>

- [<u>Fermat's theorem (more)</u>](https://en.wikipedia.org/wiki/Fermat%27s_theorem)
<pre>
- Fermat's Last Theorem, about integer solutions to a^n + b^n = c^n
- <b>Fermat's little theorem, a property of prime numbers</b>
- Fermat's theorem on sums of two squares, about <b>primes expressible</b> as a sum of squares
- Fermat's theorem (stationary points), about local maxima and minima of differentiable functions
- Fermat's principle, about the path taken by a ray of light
- Fermat polygonal number theorem, about <b>expressing integers as a sum of polygonal numbers</b>
- Fermat's right triangle theorem, about squares not being expressible as the difference of two fourth powers
</pre>

---

### Euler's Totient Theorem

<pre>
- Euler's theorem is a generalization of Fermat's little theorem

For m ∈ Z>1, Euler’s totient function φ(m) counts the number of positive integers not exceeding m relatively prime to m. It turns out this is a very useful function for us in modular arithmetic.

<b>Euler’s totient function ϕ(n) gives the number of coprime numbers to n between 1 and n.</b>

- φ(12) -> The prime factorization of 12 is 2^2 · 3, so φ(12) = 12 · 1/2 · 2/3 = 4. However, φ(12) also counts thenumber of positive integers not exceeding 12 relatively prime to 12. There are also four of these,1, 5, 7, and 11, as expected. <i>Because 1, 5, 7 and 11 are coprime to 12.</i>

- What is φ(p) for prime p? -> All positive integers less than p are relatively prime to p. Therefore, φ(p) = p − 1 .

- For m ∈ Z>1, prove that a<sup>φ(m)</sup> ≡ 1 (mod m) for all integers a such that gcd(a, m) = 1. This is known as Euler’s totient theorem.

- For m, b ∈ Z>1, show that a<sup>b</sup> ≡ a<sup>b mod φ(m)</sup> (mod m) for all integers a such that (a, m) = 1.
</pre>

<pre>
- φ(n) => how much (1 <= x <= n) such that x and n are coprime
- φ(p) = p − 1, where p is prime

- φ(8) = 8 - (2, 4, 6, 8) <- 2<sup>3</sup> => 8 - no. of multiple of 2
- φ(27~3^3) = 27 - no. of multiple of 3 = 18 <- (27 - 27/3)

- φ(10) = φ(2).φ(5) = (2-1).(5-1) = 4 (because 2, 5 are prime)
- φ(100) = φ(2^2).φ(5^2) = (2^2-2^1).(5^2-5^1) = 40
</pre>

- Formula1:

```math
\phi(n) = (p_1^{a_1} - p_1^{a_1 - 1}) \cdot (p_2^{a_2} - p_2^{a_2 - 1}) \cdot \dots \cdot (p_k^{a_k} - p_k^{a_k - 1})
```

- Formula2:
  (only weekness have to divide - it has difficult when mod is apply - but very easy to use)

```math
\phi(n) = n \cdot \left(1 - \frac{1}{p_1} \right) \cdot \left(1 - \frac{1}{p_2} \right) \cdots \left(1 - \frac{1}{p_k} \right)
```

```cpp
int eulerTotient(int m) {
    int ans = m;
    for (int p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            while (m % p == 0) {
                m /= p;
            }
            ans -= ans / p;//actual part
        }
    }
    if (m > 1) {
        ans -= ans / m;
    }
    return ans;
}
```

- <u>Phi from Factorization</u>

```cpp
int phi(int n) {
    vector<int> primes = factorize(n);//unique primes
    for (int p : primes) {
        n = n - n / p;
    }
    return n;
}
```

- <u>Seive Based Implementation of Phi</u>

```cpp
//no optimization allow
const int maxn = 1000000;
int phi[maxn + 5];
bool mark[maxn + 5];

void seive() {
    for (int i = 1; i <= maxn; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= maxn; i++) {
        if (mark[i]) continue;
        phi[i] = i - 1; //for i which is prime
        for (int j = i + i; j <= maxn; j += i) {
            mark[j] = true;
            phi[j] = phi[j] - phi[j] / i;
        }
    }
}
```

```math
\begin{array}{|c|c|}
\hline
\textbf{Fermat's Little Theorem} & \textbf{Euler's Theorem} \\
\hline
\text{If } p \text{ is prime, and } a \not\equiv 0 \pmod{p} & \text{If } \gcd(a, m) = 1 \\
a^{p-1} \equiv 1 \pmod{p} & a^{\phi(m)} \equiv 1 \pmod{m} \\
\hline
\end{array}
```

<pre>
Application:

# 0 < a/b <= 1, b <= 10, a/b has no common factor(completly reduced form means a,b are coprime)
how much fraction has possible?
=> b = 1 2 3 4 5 6 7 8 9 10
   φ(1) + φ(2) + φ(3) + ... + φ(10)

-> <b>reduced fraction</b> -> changes are use of phi

# n = 100, x<=100; how much x such that gcd(100,x) = 1 -> φ(100)
                   how much x such that gcd(100,x) = 5
        => x/5 <= 20, ... gcd(100/5,x/5) = 1 -> φ(20) (two are equivalent)

# 5<sup>100<sup>200</sup></sup> (mod 13) => 5<sup>100<sup>200</sup>(mod φ(13))</sup> (mod 13)  
-> if upper is too large (doesn't fit into any ds) than chage like that 
-> make to manageable form.

=> 5<sup>10</sup> = 5<sup>22</sup> (mod 13) ... same as 5<sup>34</sup> = 5<sup>46</sup> = ...
      = 5<sup>10</sup> . 5<sup>12</sup> (mod 13) ... = 5<sup>10</sup> . 5<sup>12 mod φ(13)</sup> (mod 13)
      = 5<sup>10</sup> . 1 (mod 13)

# a<sup>b<sup>c<sup>d</sup></sup></sup> (mod m)
</pre>

example:

- <u>Find the Last Two Digits of 7<sup>81</sup> - 3<sup>81</sup></u>
  <pre>
  Step 1: What are the last two digits?
  The last two digits of a number are the remainder when the number is divided by 100.
  We need to compute:
      7^81 - 3^81 (mod 100)
  
  Step 2: Apply Euler's Totient Theorem
  Euler's Totient Theorem states:
      a^φ(n) ≡ 1 (mod n), if gcd(a, n) = 1.
  Here:
      n = 100
      φ(100) = 40 (calculated as φ(100) = 100 × (1 - 1/2) × (1 - 1/5) = 40).
  
  Since both 7 and 3 are coprime to 100:
      7^40 ≡ 1 (mod 100)
      3^40 ≡ 1 (mod 100)
  
  Step 3: Reduce the exponents modulo φ(100)
  Since 81 mod 40 = 1:
      7^81 ≡ 7^1 (mod 100)
      3^81 ≡ 3^1 (mod 100)
  
  Step 4: Compute the difference
  Substitute the simplified results:
      7^81 - 3^81 ≡ 7 - 3 ≡ 4 (mod 100)
  
  Final Answer:
  The last two digits of 7^81 - 3^81 are 04.
  </pre>

- <u>What is the remainder when 69<sup>354</sup> is divided by 89?</u>
  <pre>
  89 is prime, so φ(89) = 88. Then,
  69^354 ≡ 69^354 mod 88 ≡ 69^2 ≡ (−20)^2 ≡ 400 ≡ 44 (mod 89).
  </pre>

- [2017 AMC 10B Problems/Problem 14](https://artofproblemsolving.com/wiki/index.php/2017_AMC_10B_Problems/Problem_14)

  <pre>
  An integer N is selected at random in the range 1 ≤ N ≤ 2020. What is the probability that the remainder when N<sup>16</sup> is divided by 5 is 1? 
  
  -> Step 1: Restate the Problem
  We want to determine the probability that N^16 ≡ 1 (mod 5) for integers N in the range 1 ≤ N ≤ 2020.
  
  Step 2: Apply Fermat’s Little Theorem
  Fermat’s Little Theorem states:
      N^(p-1) ≡ 1 (mod p),
  where p is a prime number and N ≢ 0 (mod p).
  
  Here, p = 5, so for N ≢ 0 (mod 5):
      N^4 ≡ 1 (mod 5).
  
  Step 3: Extend the Result to N^16
  Using the property of exponents:
      N^16 = (N^4)^4.
  Since N^4 ≡ 1 (mod 5), we have:
      N^16 ≡ 1^4 ≡ 1 (mod 5).
  
  Thus, for all N ≢ 0 (mod 5), N^16 ≡ 1 (mod 5).
  
  Step 4: Count N ≢ 0 (mod 5)
  Among the integers 1 ≤ N ≤ 2020, exactly 1/5 of them are divisible by 5.
  This is because the sequence of multiples of 5 is 5, 10, 15, ..., 2020, and there are:
      2020 ÷ 5 = 404
  multiples of 5.
  
  Thus, the remaining 2020 - 404 = 1616 values of N satisfy N ≢ 0 (mod 5),
  for which N^16 ≡ 1 (mod 5).
  
  Step 5: Compute the Probability
  The probability that N^16 ≡ 1 (mod 5) is the fraction of N values
  for which N ≢ 0 (mod 5):
      Probability = (Count of N ≢ 0 (mod 5)) / (Total Count of N)
                = 1616 / 2020
                = 1 - (404 / 2020)
                = 1 - 1/5
                = 4/5.
  
  Final Answer: The probability is: 4/5
  </pre>

- <u>What are the last two digits in the decimal representation of 2011<sup>2012<sup>2013</sup></sup>?</u>

  <pre>
  1. Simplify Base Modulo 100:
    2011 ≡ 11 (mod 100), so the problem becomes 11<sup>2012<sup>2013</sup></sup> mod 100.
  
  2. Apply Euler's Totient Theorem:
    φ(100) = 40, so 11<sup>40</sup> ≡ 1 (mod 100). Reduce the exponent 2012<sup>2013</sup> mod 40.
  
  3. Simplify Exponent Modulo 40:
    2012 ≡ 12 (mod 40), and 12<sup>k</sup> mod 40 cycles with length 4. 
    Since 2013 ≡ 1 (mod 4), 2012<sup>2013</sup> ≡ 12 (mod 40).
  
  4. Compute 11<sup>12</sup> mod 100:
    - 11<sup>2</sup> ≡ 21 (mod 100),
    - 11<sup>4</sup> ≡ 41 (mod 100),
    - 11<sup>8</sup> ≡ 81 (mod 100),
    - 11<sup>12</sup> ≡ 81 * 41 ≡ 21 (mod 100).
  
  Final Answer: 21.
  </pre>

- [CSES-1712_Exponentiation II](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/cses1712_Exponentiation2.cpp)

<pre>
we have to find a<sup>b<sup>c</sup></sup> modulo 1e9+7
- not working in normal way, we have to use euler's totient theorem
  
- To find the multiplicative order of a modulo m, first find φ(m), i.e. Euler's totient of m. Then brute force over the divisors of the totient; the multiplicative order must be one of the divisors.
</pre>

- [spojPOWERUP - Power the Power Up](https://www.spoj.com/problems/POWERUP/)

<pre>
(a^b)^c mod 1e9+7 where a, b and c (0 <= a, b, c <= 2^31 - 1). 
</pre>

- [uva10990 Another New Function](uva10990_Another_New_Function.cpp)

<pre>
The depth of phi value of a number is denoted by the number of steps required before it reaches 1(repeateadly apply)

Given the value of m and n your job is to find the value of SODF(m; n).

Sum of depthphi function
</pre>

- [uva10179 Irreducible Basic Fractions](uva10179_Irreducible_Basic_Fractions.cpp)

<pre>
A fraction m/n is basic if 0 ≤ m < n and it is irreducible if gcd(m, n) = 1. Given a positive integer n, in this problem you are required to find out the number of irreducible basic fractions with denominator n(< 1000000000) 

4 irreducible basic fractions with denominator 12
0/12 , 5/12 , 7/12 , 11/12
</pre>

- [spoj_GCDEX - GCD Extreme](./spoj_GCDEX_GCD_Extreme.cpp)

<pre>
G = 0;
for (i = 1; i < N; i++)
  for (j = i+1; j <= N; j++) 
    G += gcd(i, j);

The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001).
</pre>

#### 🔢 Definitions of \( G(N) \)

##### 1. **Double Summation Form**:

```math
G(N) = \sum_{i=1}^{N} \sum_{j=i}^{N} \gcd(i, j)
```

This is the basic definition of GCD Extreme — sum of GCDs for all pairs \( (i, j) \) where \( i \leq j \).

##### 2. **Ellipsis Notation**:

```math
G(N) = \gcd(1, 1 \ldots N) + \gcd(2, 2 \ldots N) + \cdots + \gcd(N, N)
```

This informal form emphasizes the "extreme" pairwise GCDs — each number with all larger or equal numbers.

##### 3. **Optimized Formula (with Totient Function)**:

```math
G(N) = \sum_{d=1}^{N} d \cdot \varphi\left( \left\lfloor \frac{N}{d} \right\rfloor \right)
```

This is the high-performance version used to efficiently compute \( G(N) \) for large \( N \), using number theory and Euler's totient function.

above solution would be like,

```math
\begin{aligned}
F(1) &= 1 \cdot \varphi(1) \\
F(2) &= 1 \cdot \varphi(2) + 2 \cdot \varphi(1) \\
F(3) &= 1 \cdot \varphi(3) + 3 \cdot \varphi(1) \\
F(4) &= 1 \cdot \varphi(4) + 2 \cdot \varphi(2) + 4 \cdot \varphi(1) \\
F(5) &= 1 \cdot \varphi(5) + 5 \cdot \varphi(1) \\
F(6) &= 1 \cdot \varphi(6) + 2 \cdot \varphi(3) + 3 \cdot \varphi(2) + 6 \cdot \varphi(1) \\
\end{aligned}
```

---
