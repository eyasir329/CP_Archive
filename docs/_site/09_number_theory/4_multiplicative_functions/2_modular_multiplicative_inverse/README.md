### Modular Multiplicative Inverse

https://cp-algorithms.com/algebra/module-inverse.html<br>
https://forthright48.com/modular-multiplicative-inverse/

<pre>
First we have to determine whether Modular Inverse even exists for given A and M before we jump to finding the solution.
- <b>Modular Inverse of A with respect to M, that is, X=A<sup>−1</sup>(mod M) exists, if and only if A and M are coprime.</b>

- Division and fractions(more complicated) are different in modular arithmetic than other operator. It's requires a concept called "modular multiplicative inverse". 
- The modular multiplicative inverse of a number a is the number a<sup>−1</sup> such that a⋅a<sup>−1</sup> mod m = 1.

Bruteforcing all numbers to a prime number close to a billion will usually cause you to exceed the time limit. There are two faster ways to calculate the inverse: the extended GCD algorithm, and Fermat's little theorem. Though the extended GCD algorithm is more versatile and sometimes slightly faster, the Fermat's little theorem method is more popular, 

a.a<sup>m−1</sup> mod m = 1 = a⋅a<sup>m−2</sup>  mod m, therefore the number we need is a<sup>-1</sup> = a<sup>m−2</sup>  mod m (m!=0)

This also extends the  mod  operator to rational numbers (i.e. fractions), as long as the denominator is coprime to m. (Thus the reason for choosing a fairly large prime; that way puzzle writers can avoid denominators with m as a factor).

If a and m aren't coprime, there is no multiplicative inverse of a modulo m, i.e., there is no integer x where a⋅x  mod m=1. This is because all a⋅x  mod m is divisible by gcd(a,m)≠1.

- Z/pZ is just a fancy term meaning the set of integers from 0 to p−1 treated as residues modulo p.
</pre>

<pre>
# Something to know

- divisions through modular multiplicative inverse would be slower than the other operations (O(logm) instead of O(1)), so you may want to cache/memoize the inverses you use frequently in your program.
- comparisons are generally meaningless.
- exponentiation (when evaluating x<sup>n</sup> mod m, you can't store n as n mod m. If n turns out to be really huge, you need to calculate it modulo φ(m) instead, where φ stands for Euler's totient function. If m is prime, φ(m) = m−1. 

Do be careful about the special case 0<sup>0</sup>, which should typically be defined as 1, while 0<sup>φ(m)</sup> would still be 0.

- A modular multiplicative inverse a<sup>−1</sup> mod m is always unique within the range 0≤a<sup>−1</sup> mod m <=m if it exists (and it exists as long as gcd(a,m)=1, a and m are coprime)
</pre>

Properties:

###### 1. **Existence**

- Not all numbers have a modular multiplicative inverse.
- The modular inverse of `a mod m` exists **if and only if** `a` and `m` are **coprime**, i.e., `gcd(a, m) = 1`.
- If `gcd(a, m) ≠ 1`, `a` has no inverse modulo `m`.

###### 2. **Uniqueness**

- If `a` has an inverse modulo `m`, it is **unique modulo `m`**.
- There is only one `x` in the range `0 ≤ x < m`
  such that: a \* x ≡ 1 (mod m)
- if a has a modular multiplicative inverse modulo m, then all a\*i mod m are distinct for i [1,m]

###### 3. **Multiplicative Property**

- If `a` and `b` both have inverses modulo `m`,
  then: (a \* b)<sup>-1</sup> ≡ a<sup>-1</sup> \* b<sup>-1</sup> (mod m)

###### 4. **Inverse of 1**

- The modular inverse of `1` is always `1`:
  1 \* 1 ≡ 1 (mod m)

###### 5. **Inverse of -a**

- The modular inverse of `-a` is `-a<sup>-1</sup>` modulo `m`:
  (-a) \* (-a<sup>-1</sup>) ≡ 1 (mod m)

###### 6. **Relation with Modular Exponentiation**

- For prime `m`, the modular inverse of `a` can be computed using **Fermat's Little Theorem**:
  a<sup>-1</sup> ≡ a<sup>(m-2)</sup> (mod m)

---

- <u>**_Naive Method (modular inverse)_**</u>

<pre> - A number a has a modular multiplicative inverse modulo m if there exists a number b such that <b>a*b ≡ 1 (mod m)</b>...(b is a modular inverse of a) -> xx<sup>−1</sup> mod m = 1.
- If a has a modular multiplicative inverse modulo m, then we can write a<sup>-1</sup> for the modular multiplicative inverse of a modulo m.

<b>a modular inverse does not always exist, x<sup>−1</sup> mod m can be calculated
exactly when x and m are coprime.</b>
</pre>

```cpp
//naive O(mod)
int inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if (1LL * a * i % m == 1) {
            return i;
        }
    }
    return -1;//inverse doesn't exist
}
```

---

<u>**_M is Prime_** -> 1e9+7 or 998244353</u><br>

- <u>**_Fermat’s Little Theorem (fast exponentiation)_**</u>

<pre>
Fermat’s Little Theorem says-> if gcd(a,m)=1 then a<sup>p−1</sup>≡1 (mod p)

If a modular inverse exists, it can be calculated using the formula 
x<sup>−1</sup> = x<sup>ϕ(m)−1</sup>. If m is prime, the formula becomes x<sup>−1</sup> = x<sup>m−2</sup>.

Optimize Approach
  -> a<sup>p-1</sup> ≡ 1 (mod p). (from little fermat's theorem)
  -> a.y ≡ 1 (mod p)
  -> a.a<sup>p-2</sup> = a<sup>p-1</sup> ≡ 1 (mod p)
  -> a<sup>-1</sup> = a<sup>p-2</sup> (mod p)

- Except for 0<sup>-1</sup> ->valid range: (0 < a < mod) -> mod must be prime
</pre>

```cpp
//faster O(logm)
int power(int x, int n, int mod) {
    int ans = 1 % mod;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

// mod must be prime
int inverse(int a, int mod) {
    if (a % mod == 0) {
        cout << "Inverse doesn't exist (a is divisible by m)." << endl;
        return -1;
    }
    return power(a, mod - 2, mod);
}
```

---

<u>**_M is not Prime_**</u> (in general)

inverse(a)%mod only have, as long long as gcd(a,mod)=1(co-prime)

- <u>Using Euler’s Theorem</u> (general method)

<pre>
It is possible to use Euler’s Theorem to find the modular inverse. We know that:

      A<sup>ϕ(M)</sup> ≡ 1(mod M)
      A<sup>ϕ(M)−1</sup> ≡ A<sup>−1</sup>(mod M)

This process works for <b>any M as long as it’s coprime to A</b>, but it is rarely used since we have to calculate Euler Phi value of M which requires more processing.

Euler's theorem provides a general method to compute modular inverses, but for prime modulus, Fermat's Little Theorem (or the Extended Euclidean Algorithm) is usually faster.
</pre>

```cpp
// complexity -> O(sqrt(mod))

// Function to compute gcd (needed to check if inverse exists)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute Euler's totient function φ(m)
int euler_phi(int m) {
    int result = m;
    for (int p = 2; p * p <= m; p++) {
        if (m % p == 0) {
            while (m % p == 0) m /= p;
            result -= result / p;
        }
    }
    if (m > 1) result -= result / m;
    return result;
}

// Function to compute a^b mod m using fast exponentiation
int power(int x, int n, int mod) { //O(logn)
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

// Function to compute modular inverse using Euler's theorem
long long inverse_using_euler(long long a, long long m) {
    if (gcd(a, m) != 1) {
        cout << "Inverse doesn't exist (a and m are not coprime)." << endl;
        return -1;
    }
    long long phi_m = euler_phi(m);
    return power(a, phi_m - 1, m);
}

int main() {
    int a = 3, m = 7;
    long long inv = inverse_using_euler(a, m);
    if (inv != -1) {
        cout << "The modular inverse of " << a << " mod " << m << " is " << inv << endl;
    }
    return 0;
}
```

---

- <u>**_Using Bezout's Lemma (Extended Euclidean Algorithm)_**</u> (most efficient)
<pre>
Bézout's Lemma states that for any integers a and b and gcd(a,b) = g, there exist integers x and y such that: ax + by = g

We are trying to solve the congruence, AX ≡ 1(mod M). We can convert this to an equation.
AX ≡ 1(mod M)
AX + MY = 1 (mod M) => AX + (M%M)Y = AX + (0)Y = 1 (mod M)
Here, both X and Y are unknown. This is a linear equation and we want to find integer solution for it. Which means, this is a Linear Diophantine Equation.

</pre>

```cpp
// Returns gcd(a, b) and sets x and y such that a*x + b*y = gcd(a, b)
// int extended_gcd(int a, int b, int &x, int &y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int gcd = extended_gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - (a / b) * y1;
//     return gcd;
// }

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

int modInv(int a, int m) {
    int x, y;
    ext_gcd(a, m, &x, &y);

    // Process x so that it is between 0 and m-1
    //x can be large, can be (-ve)
    x %= m;
    if (x < 0) x += m;
    //a*x % m = 1 confirmed
    return x;
}
```

---

- <u>**_Dynamic Programming Approach_**</u> (when need many inverses)

### Efficient Computation of Modular Inverses

This is an efficient method to compute modular inverses for integers from **1 to N-1** using an **iterative approach** based on the **Extended Euclidean Algorithm**.

#### Modular Inverse Basics

The modular inverse of an integer `a` modulo `m` is an integer `x` such that:

```
a * x ≡ 1 (mod m)
```

For a prime modulus `mod`, every integer `a` not divisible by `mod` has a unique inverse.

#### Fermat's Little Theorem

For a prime `mod` and `a` not divisible by `mod`:

```
a^(mod-1) ≡ 1 (mod mod)
=> a * a^(mod-2) ≡ 1 (mod mod)
```

Thus, `a^(mod-2)` is the inverse of `a`. However, computing this for each number up to N using exponentiation would be O(N log mod), which is less efficient than the dynamic programming approach shown.

#### Dynamic Programming Approach

The given code uses a recurrence relation based on the following mathematical insight:

For a prime `mod` and `i < mod`, we can express the inverse of `i` as:

```
inv[i] ≡ - (mod / i) * inv[mod % i] (mod mod)
```

Here's why this works:

1. Let `mod = q*i + r`, where `q = mod // i` and `r = mod % i` (so `0 < r < i`).
2. Then, modulo `mod`:
   ```
   q*i + r ≡ 0 (mod mod)
   => r ≡ -q*i (mod mod)
   ```
3. Multiply both sides by `inv[i] * inv[r]`:
   ```
   r * inv[i] * inv[r] ≡ -q * i * inv[i] * inv[r] (mod mod)
   ```
4. Since `i * inv[i] ≡ 1 (mod mod)` and `r * inv[r] ≡ 1 (mod mod)`, this simplifies to:
   ```
   inv[i] ≡ -q * inv[r] (mod mod)
   ```
5. Substituting back `q = mod // i` and `r = mod % i`:
   ```
   inv[i] ≡ (mod - (mod // i)) * inv[mod % i] % mod
   ```

#### Code Explanation

```cpp
inv[1] = 1;  // Base case: 1*1 ≡ 1 mod any number
for (int i = 2; i < N; i++) {
  inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
}
```

- `inv[1] = 1`: The inverse of 1 is always 1.
- For each `i > 1`, the inverse is computed as `(mod - mod/i) * inv[mod % i] % mod`.
  - `mod - mod/i` is equivalent to `-mod/i` modulo `mod` (but ensures positivity).
  - `inv[mod % i]` is already computed because `mod % i < i`.

#### Complexity Analysis

- **Iterative approach:** O(N) time complexity.
- **Fermat’s theorem (for prime mod):** O(N log N) if computed separately.
- **Advantage:** This method is significantly faster for large **N**.

#### Example Computation (mod = 7)

For N = 7, the computed modular inverses are:

| i   | inv[i] |
| --- | ------ |
| 1   | 1      |
| 2   | 4      |
| 3   | 5      |
| 4   | 2      |
| 5   | 3      |
| 6   | 6      |

Each satisfies the modular inverse property:

```
1 * 1 ≡ 1,  2 * 4 ≡ 1,  3 * 5 ≡ 1,
4 * 2 ≡ 1,  5 * 3 ≡ 1,  6 * 6 ≡ 1 (mod 7)
```

This method is possible because:

1. The recurrence relation correctly expresses the inverse of `i` in terms of the inverse of `mod % i`.
2. The dynamic programming approach ensures we compute inverses in the correct order (smallest to largest).
3. The prime modulus guarantees the existence of inverses for all `i < mod`.

This is one of the most efficient ways to precompute modular inverses for a range of numbers when the modulus is prime. This approach is widely used in **competitive programming** and **number theory problems** to efficiently precompute modular inverses for multiple values.

---

<pre>
Best Choice?

- If is prime → Fermat’s Little Theorem (fast exponentiation).
- If is not prime → Extended Euclidean Algorithm (Bézout’s Lemma) (most efficient).
- If you need many inverses → Dynamic Programming approach.

Fermat’s Little Theorem is fine but not better than Bézout.
</pre>

---

example:

- [hackerearth_modular inverse](https://www.hackerearth.com/problem/algorithm/modulo-inverse-problem/)
  <pre>
  You have been a number A. You need to output the inverse of number A modulo 1e9+7
  </pre>

- [eolymp9606_modular division](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/eolymp9606_modular_division.cpp)
  <pre>
  Three positive integers a,b, and n are given. Compute the value of a / b mod n. In other words, find a value x such that b⋅x = a mod n.
  
  n<=2e9, 1 < a,b < n
  -> (a*inverse(b))%n
  </pre>

---
