### Exponentiation

<pre>
Many of the important problems modular arithmetic solves involve finding the remainders of notoriously large exponents that cannot be computed by hand. In many cases, you’ll find that it is enough to find the first few exponents of the base to see how the modular residues cycle. You can then induct the cycle to pin down the desired residue.

ex. What is the units digit of 2<sup>2021</sup>?
-> Our residues cycle as 2, 4, 8, 6(2<sup>4</sup> mod 10), 2, 4, 8, 6, . . . . Because each cycle has length 4 (four residues are contained inside the cycle) 2021 mod 4 = 1 (first resides, which is 2)

- The units digit of a number is the last digit in its decimal representation.
</pre>

- <u>Given two integer x and n, find x^n modulo m</u>

###### Naive ->O(N)

```cpp
//we can just multiply x, n times
int power(int x, int n, int mod) {
    int ans = 1 % mod;
    for (int i = 1; i <= n; i++) {
        ans = 1LL * ans * x % mod;
    }
    return ans;
}
```

###### Circular ->O(mod+period length)

<pre>
- work only mod<=1e7
- If we print out the value of x^0 ... x^n under modulo m, we will see that they are repeating after some point. So we can just find the period of the sequence and then we find the answer. Period is always <=m
</pre>

```cpp
int power(int x, int n, int mod) {
    if (mod == 1)return 0;
    vector<int> a;//upto 1e7
    vector<bool>vis(mod, false);
    a.push_back(1);//x^0
    vis[1] = true;
    int cur = 1, st = 0;
    while (true) {
        cur = 1LL * cur * x % mod;
        if (vis[cur]) {
            st = find(a.begin(), a.end(), cur) - a.begin();
            break;
        }
        vis[cur] = true;
        a.push_back(cur);
    }
    int period = (int)a.size() - st;
    if (n < st)return a[n];
    n -= st;
    return a[st + n % period];
}
```

example:

- [2018 AMC 10A Problems/Problem 19](https://artofproblemsolving.com/wiki/index.php/2018_AMC_10A_Problems/Problem_19)

  <pre>
  A number m is randomly selected from the set {11, 13, 15, 17, 19}, and a number n is randomly selected from {1999, 2000, 2001, . . . , 2018}. What is the probability that m<sup>n</sup> has a units digit of 1?
  
  -> Given:
  - m ∈ {11, 13, 15, 17, 19}
  - n ∈ {1999, 2000, ..., 2018}
  
  Step 1: Analyze the units digits of m:
  - 11: Units digit = 1 (always 1 for m^n).
  - 13: Units digits cycle as 3, 9, 7, 1 (cycle length = 4).
  - 15: Units digit = 5 (never 1 for m^n).
  - 17: Units digits cycle as 7, 9, 3, 1 (cycle length = 4).
  - 19: Units digits cycle as 9, 1 (cycle length = 2).
  
  Step 2: Determine probabilities for each m:
  - m = 11: Always 1 → Probability = 1.
  - m = 13: n mod 4 = 0. 5 values in n, Probability = 5/20 = 1/4.
  - m = 15: Never 1 → Probability = 0.
  - m = 17: n mod 4 = 0. 5 values in n, Probability = 5/20 = 1/4.
  - m = 19: n mod 2 = 0 (even n). 10 values in n, Probability = 10/20 = 1/2.
  
  Step 3: Calculate overall probability:
  Each m is equally likely (1/5):
  - Total probability = (1/5)(1 + 1/4 + 0 + 1/4 + 1/2)
                      = (1/5)(4/4 + 1/4 + 0/4 + 1/4 + 2/4)
                      = (1/5)(8/4) = 2/5.
  
  Final Answer:
  The probability that m^n has a units digit of 1 is 2/5.
  -----
  - <b>When you multiply two numbers, the units digit of the result is determined only by the units digits of the numbers being multiplied.</b>
  - Each time we multiply, only the units digit of the intermediate result matters. The higher digits do not affect the units digit.
  
  - By focusing on the repeating patterns in the units digits of powers (like cycles of 3,9,7,1 for 13), we can predict the units digit of m<sup>n</sup> without performing full multiplication.
  </pre>

#

### Binary Exponentiation

https://cp-algorithms.com/algebra/binary-exp.html

<pre>
Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate a<sup>n</sup> using only O(logn) multiplications (instead of O(n) multiplications required by the naive approach).

-> Although the complexity of both approaches is identical, iterative approach is faster than recursive 
</pre>

###### Recursive ->O(logn)

<pre>
- We can use divide and conquer to solve this problem.
     n = 0 -> x^n = 1
     n is even -> x^n/2*x^n/2 -> (x<sup>2</sup>)<sup>n/2</sup>
     n is odd -> x^floor(n/2)*x^floor(n/2)*x -> x*(x<sup>2</sup>)<sup>n-1/2</sup> 
</pre>

```cpp
int power(int x, long long n, int mod) {
    if (n == 0) return 1 % mod;//base case
    int cur = power(x, n / 2, mod);//to compute (x^(n/2)) % mod
    if (n % 2 == 0) {
        return 1LL * cur * cur % mod;
    } else {
        return 1LL * cur * cur % mod * x % mod;
    }
}
```

###### Iterative v1 ->O(logn)

<pre>
- any integer n can be written as sum of power of two
-> x<sup>13</sup> = x<sup>2<sup>3</sup>+2<sup>2</sup>+2<sup>0</sup></sup> = x<sup>2<sup>3</sup></sup>*x<sup>2<sup>2</sup></sup>*x<sup>2<sup>0</sup></sup> 
</pre>

```cpp
int power(int x, long long n, int mod) {
    int ans = 1 % mod, cur = x % mod;
    for (int i = 0; (1LL << i) <= n; i++) {
        if (n & (1LL << i)) {
            ans = 1LL * ans * cur % mod;
        }
        cur = 1LL * cur * cur % mod;
    }
    return ans;
}
```

###### Iterative v2 ->O(logn)\*\*\*

<pre>
- same as v1 but in different way. Basically we can get the binary representation of n from LSB to MSB by dividing n by 2 each time. If the current bit is 1, then we multiply the answer by x<sup>2<sup>i</sup></sup>
</pre>

```cpp
int power(int x, long long n, int mod) {
    int ans = 1 % mod;//mod can be 1
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}
```

example:

- [CSES-1095_Exponentiation](./4_binary_exponentiation/cses1095_Exponentiation.cpp)

  <pre>
  Your task is to efficiently calculate values a^b modulo 10^9+7.
  Note that in this task we assume that 0^0=1.
  </pre>

- [UVA-1230_MODEX](./4_binary_exponentiation/UVA1230_MODEX.cpp)

  <pre>
  Given integers x, y and n, compute x^y mod n. In this question, you are tasked to program an efficient way to execute this calculation.
  </pre>

- [UVA-374_Big Mod](./4_binary_exponentiation/UVA374_Big%20Mod.cpp)
  <pre>
  Calculate R := B^P mod M
  for large values of B, P , and M using an efficient algorithm.
  
  The input will contain several test cases, but not given the value of t, M is an integer in the range 1 to 46340 inclusive (so it also support circular way to finding exponentiation O(mod+period length), but not support naive method O(n) because P-> 0 to 2147483647 inclusive)
  </pre>

- [913A_Modular Exponentiation](https://vjudge.net/problem/CodeForces-913A)

    <pre>
    The following problem is well-known: given integers n and m, calculate 2^n mod m
    
    You are asked to solve the "reverse" problem. Given integers n and m, calculate m mod 2^n (1<=n,m<=1e8)
    
    -> python can support large nunber, or java BigInteger
    -> n >= 31 ? m : m % (1 << n))
    </pre>

- https://www.spoj.com/problems/LASTDIG/
- [UVA_11029 Leading and Trailing](./4_binary_exponentiation/UVA11029_Leading%20and%20Trailing.cpp)

  <pre>
  C function pow(125456, 455) can be represented in double data
  type format, but you won’t get all the digits of the result. However we can get at least some satisfaction, if we could know few of the leading and trailing digits. This is the requirement of this problem.
  
  For each line of input there will be one line of output. It will be of the format LLL . . . T T T , where LLL represents the first three digits of nk and T T T represents the last three digits of nk. You are assured that nk will contain at least 6 digits.
  
  n and k. n will fit in 32 bit integer and k will be less than 10000001
  </pre>

  <pre>
  # for finding first three digit
  Logarithmic Identity:
  
  Formula Used: 
  log10(n^k) = k × log10(n)
  
  The idea here is to use the logarithmic identity to transform the problem of finding the first few digits of n^k into a problem of dealing with logarithms.
  In this case:
  - log10(base) computes the logarithm of base (which is n in the function).
  - Multiplying this by exp (which is k in the function) gives the logarithm of n^k, i.e., logValue = exp * log10(base).
  
  Extracting the Fractional Part:
  
  fractionalPart = logValue - floor(logValue);
  
  Logarithms produce a number in the form of an integer part and a fractional part. For example, if log10(1000) = 3.0, the integer part is 3 and the fractional part is 0.
  To get the fractional part (the part after the decimal point), the floor(logValue) function is used, which removes the integer portion.
  For instance, if logValue = 5.2356, then fractionalPart = 0.2356.
  
  Calculating the First Three Digits:
  
  pow(10, fractionalPart) gives us the number 10^fractionalPart, which is a number between 1 and 10. This is a key step for extracting the significant digits.
  For example, if fractionalPart = 0.2356, then pow(10, fractionalPart) will give something like 1.78 (the first part of the number, representing the significant digits).
  Multiplying this result by 100 scales it up to get the first three digits. For example, if pow(10, fractionalPart) = 1.78, then 1.78 * 100 = 178.
  The result is then cast to long long to obtain the integer value of the first three digits.
  
  Returning the Result:
  
  The function returns the first three digits as a long long integer.
  </pre>

  <b>Precision Handling</b> (more precision)

  <b>Logarithmic Method (calculateFirstThreeDigits):</b>

  - Relies heavily on <i>double</i> precision to handle the fractional part and <i>pow</i> function.
  - Floating-point operations, especially with large numbers, can lead to small inaccuracies due to precision limits.
  - Example issue:
    If log<sub>10</sub>(n<sup>k</sup>) = 12.999999, <i>floor(logValue)</i> might misinterpret the result, leading to incorrect digits.

  <b>Combined Logarithmic with Modular Arithmetic:</b>

  - Adjusts fractional part alignment more explicitly:
    <code>
    lg -= floor(lg) - 2;
    </code>
    This ensures a more stable computation for the leading digits by shifting the fractional part to focus on significant digits.
  - Adds a small epsilon (<i>1e-9</i>) during extraction to stabilize floating-point operations.

---

### Mulmod and Binary Exponentiation like Problems

https://cs.stackexchange.com/questions/77016/modular-multiplication

- Why use mulmod ?
<pre>
- When multiplying two large numbers where (𝑎⋅𝑏) exceeds the range of long long.
- To ensure correctness in modular arithmetic computations in languages or systems with limited integer sizes.
</pre>

- <u>Given three integers x,y and m, find x\*y modulo m. (1<=x,y<=1e18, mod<=1e18+7)</u>
<pre>
a * b % mod is overflowing because of a,b,mod are very large.
x * y = x+x+...x (upto y times)
</pre>

```cpp
long long mulmod(long long x, long long y, long long mod) {//O(logy)
    long long ans = 0;
    while (y > 0) {
        if (y & 1) {
            ans = (ans + x) % mod;//do addition, instead of multiplication
        }
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}
```

<pre>
- we can also use 128 bit integer for this purpose
</pre>

```cpp
long long mulmod(long long x, long long y, long long mod) {
    return (long long)((__int128)x * y % mod);
}
```

<pre>
x mod 2<sup>k</sup> = x&(2<sup>k</sup>-1) -> equal to the last k bits of x 
</pre>

- <u>Given two integers x,n, find x<sup>n</sup> modulo 2<sup>64</sup></u>
<pre>
unsigned integers are represented modulo 2^k, where k is the number of bits of the data type. unsigned int are represented modulo 2^32
</pre>

```cpp
//benefit of data type ranges
#define ull unsigned long long

ull power(ull x, ull n) {
    ull ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= x;//ull always do mod by 2^64
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}
```

example:

- [codechef_Chef and Riffles](./1_basic_modular_operation/codechef_JAN221B_RIFFLES_Chef%20and%20Riffles.cpp)

  <pre>
  Let f be a permutation of length N, where N is even. The riffle of f is defined to be the permutation g=(f(1),f(3),…,f(N−1),f(2),f(4),…,f(N))
  
  You are given two integers N and K. Output the resultant permutation when you riffle the identity permutation of length N, K times.
  1≤T≤100, 1≤N≤3⋅1e5, 1≤K≤1e9, N is even
  The sum of N across test cases does not exceed 3⋅1e5
  </pre>

- [spoj_ZSUM - Just Add It](./4_mulmod_and_binExpLike/spoj_ZSUM_Just%20Add%20It.cpp)

  <pre>
  For two given integers n and k find (Zn + Z(n-1) - 2Z(n-2)) mod 10000007, where Zn = Sn + Pn and Sn = 1^k + 2^k + 3^k + … + n^k and Pn = 1^1 + 2^2 + 3^3 + … + n^n. (1 < n < 200000000, 0 < k < 1000000 )
  </pre>

- [spoj_LOCKER - Magic of the locker](./4_mulmod_and_binExpLike/spoj_LOCKER_Magic%20of%20the%20locker.cpp)

  <pre>
  you are given a number n , and break it into parts such that product of all parts is maximum.
  </pre>

---
