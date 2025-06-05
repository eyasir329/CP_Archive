### Primes

<pre>
- prime has exactly two divisors (1 & that number)
- other number can be represented by multiple of different prime numbers
- if p divide a*b then -> p (divide a) or (divide b) or (both)
- 1 neither prime nor composite
- after 2 all prime is odd
- primes<sup>2</sup> has exactly three divisors (4 -> 1,2,4)
</pre>

- <u>Prime-Counting Function π(N) / Prime number theorem</u>
<pre>
The prime-counting function π(N) gives the exact number of primes less than or equal to N.

For:
N = 2^64 = 18,446,744,073,709,551,616

A rough estimate of π(2^64) using the logarithmic integral approximation is:

π(2^64) ≈ 2^64 / ln(2^64)
= 2^64 / (64 . ln(2))
≈ 4.2 × 10^17

However, modern number theory research and computational results provide a more precise estimate:

π(2^64) ≈ 416,971,064,282,000

That’s approximately 417 trillion prime numbers less than or equal to 2^64.

</pre>

    not exact ~ approx

```math
\pi(n) \sim \frac{n}{\ln n}
```

---

- <u>Trial Division (Naive)</u> -> best for single number
<pre>
- Complexity -> O(sqrt(n), Space: O(1)
- Suitable for n <= 1e6
- for 1 test case it can go upto 1e14 (1e7 instruction need)

n = a.b => a < sqrt(n)
for whose prime number square (25->5.5) it fails because it runs upto 1,2,3,4 not 5 that's why we need a <= sqrt(n)

</pre>

```cpp
//check n is prime or not -> O(sqrt(n)
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

```cpp
// more optimized

// O(√n / 3) Time Complexity: Much faster than a naive O(√n) approach.
// Use this function when you need a fast, deterministic primality test for integers.

bool isPrime(int n) {
  if (n <= 1)  // 1 and below are not prime
    return false;
  if (n == 2 || n == 3)  // 2 and 3 are prime
    return true;
  if (n % 2 == 0 || n % 3 == 0)  // Eliminate multiples of 2 and 3
    return false;
  // Check divisibility for numbers of form 6k ± 1 up to √n
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
```

```cpp
// Function to return the smallest
// prime number greater than N
int nextPrime(int N){
  // Base case
  if (N <= 1) return 2;
  int prime = N;
  bool found = false;
  // Loop continuously until isPrime returns
  // true for a number greater than n
  while (!found){
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
```

example:

- Prove that, for all primes p, the smallest positive integer whose factorial is divisible by p is p itself.

<pre>It is trivial by inspection that p satisfies this condition. Let the smallest positive such integer be k. For the sake of contradiction, assume that k < p and p|k!. Then, k! is the product of all positive integers less than p and p is present in the prime factorization of k!. Some of the positive integers in this product are themselves primes less than p, while others are less than p and have unique prime factorizations involving only primes less than p by the fundamental theorem of arithmetic. Thus, p cannot be present in prime factorization of k!, establishing contradiction. This means that k = p. 
</pre>

- [1562B - Scenes From a Memory](./1562B_Scenes_From_a_Memory.cpp)
<pre>
find the smallest non-prime number that can be formed by digits from a given string (as a subsequence)
</pre>

- https://codeforces.com/contest/2093/problem/C

---

- <u>Sieve of Eratosthenes (Precompute Primes)</u>

<pre>
- Generate all primes up to N using a boolean sieve.
- Time: O(NloglogN) Space: O(N)
- Best for precomputing primes up to 1e7(memory limits apply).
</pre>

![seive](https://texample.net/files/eratosthenes-sieve.png)

- https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)

- <u>General Seive</u>

```cpp
/*loop goes upto : n/2+n/3+n/5+n/7+...
-> n(1/2+1/3+1/5+...)
-> harmonic series -> 0(nloglogn)*/

//basic seive (no optimization)
//work upto 5e7
bool mark[50000000 + 5];
void seive(int n) {
    mark[1] = true;
    for (int i = 2; i <= n; i++) {
        if (mark[i]) continue;
        for (int m = 2 * i; m <= n; m += i) {//only go when i is prime
            mark[m] = true;
        }
    }
}
```

- <u>Optimized Seive 1</u>

```cpp
//complexity same as general seive
void seive(int n) {
    mark[0] = mark[1] = true;
    for(int i=4;i<=n;i+=2){//even handle fast
      mark[i] = true;
    }
    for (int i = 3; i <= n; i+=2) {
        if (mark[i]) continue;
        for (int m = 3 * i; m <= n; m += i+i) {//only go when i is prime
            mark[m] = true;
        }
    }
}
```

- <u>Optimized Seive 2 (Time Efficient)</u>

```cpp
//more prefer than previous version
bool mark[50000000 + 5];
void seive(int n) {
  mark[0] = mark[1] = true;
    for (int i = 4; i <= n; i += 2) { //even handle fast
        mark[i] = true;
    }
    for (int i = 3; 1LL * i * i <= n; i += 2) {
      if (mark[i]) continue;
        for (int m = i * i; m <= n; m += i + i) {
          mark[m] = true;
        }
    }
}
```

- <u>Optimized Seive 3 (Time and Memory Efficient)</u>

```cpp
//using array instead of vector

const int MAX = 1e8; // Main sieve limit
bitset<MAX + 1> is_prime;
int primes[50000000 + 5]; // Stores primes up to MAX
int primecnt = 0;

// Optimized sieve that populates both is_prime and primes[]
void optimized_sieve(int n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;

    // Handle evens
    for (int i = 4; i <= n; i += 2)
        is_prime[i] = false;
    primes[primecnt++] = 2;

    // Sieve odd numbers
    for (int64_t i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            primes[primecnt++] = i;
            for (int64_t j = i * i; j <= n; j += 2 * i)
                is_prime[j] = false;
        }
    }
}
```

example:

- Task 1: https://codeforces.com/problemset/problem/154/B
- Task 2: https://codeforces.com/problemset/problem/284/A
- Task 3: https://codeforces.com/problemset/problem/343/A
- Task 4: https://codeforces.com/problemset/problem/375/A
- Task 5: https://codeforces.com/problemset/problem/495/B
- Task 6: https://codeforces.com/problemset/problem/576/A
- Task 7: https://codeforces.com/problemset/problem/735/D
- Task 8: https://codeforces.com/problemset/problem/1349/A
- Task 9: https://codeforces.com/problemset/problem/1458/A
- https://www.spoj.com/problems/VECTAR8/
- https://www.spoj.com/problems/HS08PAUL/

- [spoj_TDKPRIME - Finding the Kth Prime](spoj_TDKPRIME_Finding_the_Kth_Prime.cpp)
<pre>
An integer stating the number of queries Q (equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

Q lines with the answer of each query: the Kth prime number.

n = 86028122 ~ 1e8 for 5e6
</pre>

- [uva_543 - Goldbach's Conjecture](uva_543Goldbachs_Conjecture.cpp)

<pre>
Euler re-expressed the conjecture as:

Every even number greater than or equal to 4 can be expressed as the sum of two prime numbers.

Each test case consists of one even integer n with 6 ≤ n < 1000000.
</pre>

- https://lightoj.com/problem/lucky-number

<pre>
seive + segment tree
</pre>

---

### Factorization

<pre>
- 1 number does not have more than log(N) prime
</pre>

- <u>General Factorization</u>

```cpp
//complexity -> O(sqrt(n))
vector<ll>factorize(ll n) {
    vector<ll>ret;
    if (n == 1) {
        return ret;
    }
    for (ll i = 2; i * i <= n; i++) {//can go upto prime list
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                ret.push_back(i);
            }
        }
    }
    if(n != 1){//>1
      ret.push_back(n);
    }
    return ret;
}
```

- <u>Factorization from primes</u>

```cpp
using ll = long long;
const ll MAX_SIEVE = 1e7;
std::vector<ll> spf(MAX_SIEVE + 1);
std::vector<ll> primes;

// Precompute smallest prime factors and primes list
void precompute_primes() {
    spf[0] = spf[1] = 1;
    for (ll i = 2; i <= MAX_SIEVE; i++) {
        if (spf[i] == 0) {  // i is prime
            spf[i] = i;
            primes.push_back(i);
            for (ll j = i * i; j <= MAX_SIEVE; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

// Optimized factorization using precomputed primes
std::vector<ll> factorize_with_primes(ll n) {
    std::vector<ll> factors;
    if (n == 1) return factors;

    // Check against precomputed primes
    for (ll p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }

    if (n > 1) factors.push_back(n);
    return factors;
}
```

- <u>Factorization From Seive</u>

```cpp
int mark[50000000 + 5];
void seive(int n) {
    mark[0] = mark[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (mark[i] > 0) continue;
        for (int m = 2 * i; m <= n; m += i) {
            mark[m] = i;
        }
    }
}
//vector return makes vector copy to another
vector<int>factorize(int n) {//O(logn)
    vector<int>ret;
    if(n == 1) return ret;
    while (mark[n] != 0) {//no wasted
        ret.push_back(mark[n]);
        n /= mark[n];
    }
    ret.push_back(n);
    return ret;
}
```

example:

- [576A_Vasya and Petya's Game](./2.divisors/576A_Vasya%20and%20Petya's%20Game.cpp)

<pre>
# thought of number x between 1 and n, another tries to guess the number
# another can ask, is the unknown number divisible by number y?
# find the minimum number of questions he should ask to make a guaranteed guess number.

n factorize = (2,2,2,3,5...y)
if(n is divisible y) y*y until find n.. then next y

</pre>

- [230B_T-primes](230B_T-primes.cpp)
<pre>
A number is called a T-prime if it has exactly three distinct positive divisors. Given n numbers, determine if each is a T-prime.
</pre>

- [spoj_FACT0 - Integer Factorization (15 digits)](spoj_FACT0.cpp)

<pre>
Given some integers, you need to factor them into product of prime numbers. 
</pre>

- [1366D. Two Divisors](1366D_Two_Divisors.cpp)

<pre>
You are given n integers a1,a2,…,an
For each ai, find its two divisors d1>1 and d2>1 such that gcd(d1+d2,ai)=1 (where gcd(a,b) is the greatest common divisor of a and b) or say that there is no such pair.

2 <= ai <= 1e7

not possible when n = p^x 
d1 = p
d2 = q.r...
</pre>

---

### Legendre's Formula

- https://artofproblemsolving.com/wiki/index.php/Legendre's_Formula

Legendre's formula gives the exponent of a prime number \( p \) in the factorization of \( n! \). It is expressed as:

```math
e_p(n!) = \sum_{i=1}^{\infty} \left\lfloor \dfrac{n}{p^i} \right\rfloor = \frac{n - S_p(n)}{p - 1} = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \cdots
```

Where:

- e_p(n!) is the exponent of prime p in n!
- S_p(n) is the sum of digits of n in base p
- floor(x) denotes the floor function ⎣x⎦ (greatest integer less than or equal to x)

This formula is especially useful in number theory and combinatorics for evaluating factorial prime powers efficiently.

```cpp
int legendre(int n, int p) {
    int exponent = 0;
    while (n > 0) {
        n /= p;
        exponent += n;
    }
    return exponent;
}

//Count trailing zeros in n! (exponent of 5 in n!)
int countTrailingZeros(int n) {
    return legendre(n, 5);
}
```

example:

- To determine how many times the prime number **2** appears in the factorization of **10!** (10 factorial), we can use **Legendre's Formula**.

**Calculation for \( p = 2 \) in \( 10! \)**

```math
e_2(10!) = \left\lfloor \frac{10}{2} \right\rfloor + \left\lfloor \frac{10}{4} \right\rfloor + \left\lfloor \frac{10}{8} \right\rfloor + \left\lfloor \frac{10}{16} \right\rfloor + \cdots
\\
= 5 + 2 + 1 + 0 + \cdots= 8
```

- [lightoj\_ Trailing Zeroes (II)](lightoj_Trailing_Zeroes2.cpp)

<pre>
Find the number of trailing zeroes for the following function:

(nCr)×p<sup>q</sup>

where n, r, p, q are given as Input.
Input starts with an integer T (≤ 10000), denoting the number of test cases.
Each case contains four integers: n, r, p, q (1 ≤ n, r, p, q ≤ 1e6, r ≤ n).

=>
2^x, 5^y -> min(x,y)

n! -> cnt 2,5
r! -> cnt 2,5
(n-r)! -> cnt 2,5

total = (n! -> cnt 2,5)-((r! -> cnt 2,5) + ((n-r)! -> cnt 2,5))
</pre>

---
