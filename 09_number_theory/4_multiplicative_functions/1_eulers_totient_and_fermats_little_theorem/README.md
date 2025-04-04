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

example:

- [CSES-1712_Exponentiation II](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/cses1712_Exponentiation2.cpp)

  <pre>
  we have to find a<sup>b<sup>c</sup></sup> modulo 1e9+7
  - not working in normal way, we have to use euler's totient theorem
  
  - To find the multiplicative order of a modulo m, first find φ(m), i.e. Euler's totient of m. Then brute force over the divisors of the totient; the multiplicative order must be one of the divisors.
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

```cpp
int eulerTotient(int m) {
    int ans = m;
    for (int p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            while (m % p == 0) {
                m /= p;
            }
            ans -= ans / p;
        }
    }
    if (m > 1) {
        ans -= ans / m;
    }
    return ans;
}
```

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240424121512/Euler's-Product-Formula.webp" alt="Euler's Product Formula" width="400">

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

---
