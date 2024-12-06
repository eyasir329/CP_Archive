# Number Theory

https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/

## Modular Arithmetic

https://libraryguides.centennialcollege.ca/c.php?g=717548&p=5121821
https://codeforces.com/blog/entry/72527

### Properties

<pre>
-> a mod m = b mod m => (a-b) mod m = 0
-> x mod m = x if m>x
-> x mod m < x/2 when m <= x
</pre>

![](https://prod-qna-question-images.s3.amazonaws.com/qna-images/answer/6195f099-697f-489e-94ae-c77f1a063c08/8512de78-d4fd-43ef-9f61-33fcd14fa8c9/2dm5l1.jpg)

#

#### Mulmod

- Why use mulmod ?
<pre>
- When multiplying two large numbers where (𝑎⋅𝑏) exceeds the range of long long.
- To ensure correctness in modular arithmetic computations in languages or systems with limited integer sizes.
</pre>

- Given three integers x,y and m, find x\*y modulo m. (1<=x,y<=1e18, mod<=1e18+7)
<pre>
a * b % mod is overflowing because of a,b,mod are very large.
x * y = x+x+...x (upto y times)
</pre>

```cpp
long long mulmod(long long x, long long y, long long mod) {//O(logy)
    long long ans = 0;
    while (y > 0) {
        if (y & 1) {
            ans = (ans + x) % mod;
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

- Given two integers x,n, find x<sup>n</sup> modulo 2<sup>64</sup>

```cpp
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

#

example:

- [gfg_Find the maximum possible value of a[i] % a[j] over all pairs of i and j]()
  <pre>
  - 2nd maximum is the answer (other is always smaller than 2nd_mx%1st_max)
  
  reverse problem cf_484b
  </pre>

- [toph_Modulo](./4_modular_arithmetic/2_basic_modular_arithmetic/toph_modulo.cpp)
  <pre>
  Given an array A of N integers. Then there will be Q queries. In each query You will be given an integer M. For every ii where 1≤i≤N you have to change A[i] to A[i] mod M. After executing all queries you have to print the array A in the order of input.
  
  - be careful to put newline in i==n
  </pre>

- [495_Modular Equations](./5.modular_arithmetic/modular_arithmetic/495B_Modular%20Equations.cpp)

  <pre>
  # print the number of solutions of the modular equation (a mod x = b). (0<=a,b<=1e9)
  
  # (x>b, a%x <=a)by the rule of modulo
  
  *a = b => infinity (then x can be any integer larger than a)
  *a < b =>  0 (there is no such x for that)
  *a > b =>  (b < x <= a)
    a = 21, b = 5
    a-b = 16 (except a=1,(b==0)1:0)
    num of divisors of a-b(16) that are more than b
  </pre>

---

## Exponentiation

- Given two integer x and n, find x^n modulo m

#### Naive ->O(N)

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

#### Circular ->O(mod+period length)

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

## Binary Exponentiation

#### Recursive ->O(logn)

<pre>
- We can use divide and conquer to solve this problem.
  {
     n = 0 -> x^n = 1
     n is even -> x^n/2*x^n/2 
     n is odd -> x^floor(n/2)*x^floor(n/2)*x 
  }
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

#### Iterative v1 ->O(logn)

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

#### Iterative v2 ->O(logn)

<pre>
- same as v1 but in different way. Basically we can get the binary representation of n from LSB to MSB by dividing n by 2 each time. If the current bit is 1, then we multiply the answer by x<sup>2<sup>i</sup></sup>
</pre>

```cpp
int power(int x, long long n, int mod) {
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
```

example:

- [ces1095_Exponentiation](./4_modular_arithmetic/1_binary_exponentiation/ces1095_Exponentiation.cpp)

---

## Divisors

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

example:

- [375A_Divisible By Seven](./2.divisors/375A_Divisible%20by%20Seven.cpp)

  <pre>
  # we need (num % 7 == 0)
  
  Rearrange the digits in its decimal representation so that the resulting number will be divisible by 7.
  It doesn't contain any leading zeroes and always contains digits 1, 6, 8, 9
  {"1869", "1968", "1689", "6198", "1698", "1986", "1896"}%7={0,1,2,3,4,5,6}, find it using next_permutation.
  
  #({... Other num mod + (7-other num mod) mod from list }%7=0 + zero at last)%7=0
  
  ex. (5+2+0)%7=0, (4+3+0)%7=0
  </pre>

- [2050C_Uninteresting Number](./1_primes_and_divisors/2_divisors/2050C_Uninteresting%20Number.cpp)
  <pre>
  Given a number n with length(1e5), perform operation any number of times (choose one of its digits, square it, and replace the original digit with the result)
  
  Is it possible to obtain a number that is divisible by 9 through these operations?
  </pre>

## Primes

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

---

## Fermat's Little Theorem

<pre>
Let p be a prime which does not divide the integer a, then a<sup>p-1</sup> ≡ 1 (mod p).
</pre>

https://t5k.org/notes/proofs/FermatsLittleTheorem.html

<pre>
x<sup>n</sup> ≡ x<sup>n mod (p-1)</sup> (mod p), if p is prime 
- because x^0, x^1, x^2 ... cycles after p-1 terms
</pre>

example:

- [cses1712_Exponentiation II](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/cses1712_Exponentiation2.cpp)

  <pre>
  we have to find a<sup>b<sup>c</sup></sup> modulo 1e9+7
  - not working in normal way, we have to use fermat's little theorem
  </pre>

## Modular Multiplicative Inverse

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

<pre>
Naive Method
- A number a has a modular multiplicative inverse modulo m if there exists a number b such that a*b ≡ 1 (mod m)
- If a has a modular multiplicative inverse modulo m, then we can write a<sup>-1</sup> for the modular multiplicative inverse of a modulo m.
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

<pre>
Optimize Approach
  -> a<sup>p-1</sup> ≡ 1 (mod p). (from little fermat's theorem)
  -> a<sup>p-2</sup> ≡ a<sup>-1</sup> (mod p)
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
    return power(a, mod - 2, mod);
}
```

example:

- [hackerearth_modular inverse](https://www.hackerearth.com/problem/algorithm/modulo-inverse-problem/)

- [eolymp9606_modular division](./4_modular_arithmetic/3_fermats_little_theorem_and_modular_inverse/eolymp9606_modular_division.cpp)
  <pre>
  Three positive integers a,b, and n are given. Compute the value of a / b mod n. In other words, find a value x such that b⋅x = a mod n. 
  
  n<=2e9, 1 < a,b < n
  -> a*inverse(b)%n
  </pre>

---
