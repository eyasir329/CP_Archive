### Divisors

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

- atcoder C - Cream puff

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

---

### Number Theoretic Function

<pre>
Two important number theoretic functions in mathematics are:

- τ(n) (Tau function): Counts the number of positive divisors of n
- σ(n) (Sigma function): Calculates the sum of all positive divisors of n

other two are eulers and mobius function

n -> 1e16 => sqrt(n) -> 1e8 : it can pass
</pre>

- <u>τ(n) (Tau function)</u>

<pre>τ(12) =>
- Step 1: Prime Factorization 12 = 2<sup>2</sup> × 3<sup>1</sup>
- Step 2: Use the divisor-counting formula 
If n = p<sub>1</sub><sup>a</sup> × p<sub>2</sub><sup>b</sup> × ... × p<sub>k</sub><sup>z</sup>, 
then <b>τ(n) = (a + 1)(b + 1)...(z + 1)</b> -> (+1 because of 0)

So, τ(12) = (2 + 1)(1 + 1) = 3 × 2 = 6 
- Step 3: List all divisors of 12 All numbers of the form 2<sup>i</sup> × 3<sup>j</sup> where 0 ≤ i ≤ 2, 0 ≤ j ≤ 1 

→ Possible combinations: 
i = 0, j = 0 → 1 
i = 0, j = 1 → 3 
i = 1, j = 0 → 2 
i = 1, j = 1 → 6 
i = 2, j = 0 → 4 
i = 2, j = 1 → 12 
→ Divisors of 12: 1, 2, 3, 4, 6, 12 Hence, τ(12) = 6 
✔ Confirmed: The number of positive divisors of 12 is 6. 
</pre>

<pre>
-> odd divisors not count for 2
-> square divisors : a^x . b^y . c^z => (no.(o,2,4..x)).(no.(o,2,4..y)).(no.(o,2,4..z))
-> non square
-> squarefree (not divide by any square)
</pre>

```cpp
//number of disisors
using ll = long long
int tau(ll n) {
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i)cnt++;
        }
    }
    return cnt;
}
```

- <u>Sieve-Based Implementation of τ(n)</u>

<pre>
1 2 3 4 5 6 7 8 9 10 ... n
|-||-||-|||-||-||||-||-||||-|||-|||| (for 1 to n go all divisor of i and add 1)
1 2 2 3 2 4 2 4 3 4
</pre>

```cpp
const int nmax = 1e5 + 10;

int tau[nmax];
int sigma[nmax];
//can go easily 1e6
void seive() { //O(nlog(n)) //can't go upto 9e7 but original can go
    for (int i = 1; i < nmax; i++) {
        for (int m = i; m < nmax; m += i) {
            tau[m]++
            sigma[m] += i;
        }
    }
}
/* original seive-> O(nloglogn) -> only find prime record ...
then apply math formula of tau and sigma...
try to use this all the time*/
```

```math
\log n \approx 1 + \frac{1}{2} + \frac{1}{3} + \cdots + \frac{1}{n}
```

- <u>Sieve-Based Implementation (Optimised)</u>

```cpp
/*
SPF sieve: O(n log log n)
Main loop: O(n) amortized
Total: O(n log log n) + O(n) = O(n log log n)*/

const int nmax = 1e5 + 10;
int spf[nmax]; // smallest prime factor
int tau[nmax];
int sigma[nmax];

void optimized_sieve() {
    // Initialize smallest prime factors
    iota(spf, spf + nmax, 0); // spf[i] = i

    // Sieve of Eratosthenes to find smallest prime factors
    for (int i = 2; i * i < nmax; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < nmax; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    // Initialize tau and sigma for n = 1
    tau[1] = 1;
    sigma[1] = 1;

    for (int n = 2; n < nmax; n++) {
        if (spf[n] == n) { // n is prime
            tau[n] = 2;
            sigma[n] = n + 1;
        } else {
            // Factorize n using spf
            int p = spf[n];
            int m = n;
            int exponent = 0;
            while (m % p == 0) {
                m /= p;
                exponent++;
            }

            // Using multiplicative properties:
            // τ(n) = τ(m) * (exponent + 1)
            // σ(n) = σ(m) * (p^(exponent+1) - 1)/(p - 1)
            tau[n] = tau[m] * (exponent + 1);

            int power = 1;
            for (int i = 0; i <= exponent; i++) {
                power *= p;
            }
            sigma[n] = sigma[m] * (power - 1) / (p - 1);
        }
    }
}
```

- <u>σ(n) (Sigma function)</u>

<pre>σ(12) => 
- Step 1: Prime Factorization 
12 = 2<sup>2</sup> × 3<sup>1</sup> 

- Step 2: Formula for sum of divisors 
If n = p<sub>1</sub><sup>a</sup> × p<sub>2</sub><sup>b</sup> × ... × p<sub>k</sub><sup>z</sup>, then 
σ(n) = [(p<sub>1</sub><sup>0</sup> + p<sub>1</sub><sup>1</sup> + ... + p<sub>1</sub><sup>a</sup>) × (p<sub>2</sub><sup>0</sup> + p<sub>2</sub><sup>1</sup> + ... + p<sub>2</sub><sup>b</sup>) × ... ] 

((p<sub>1</sub><sup>a<sub>1</sub>+1</sup>-1)/(p<sub>1</sub>-1)).((p<sub>2</sub><sup>a<sub>2</sub>+1</sup>-1)/(p<sub>2</sub>-1))...

So, σ(12) = (2<sup>0</sup> + 2<sup>1</sup> + 2<sup>2</sup>) × (3<sup>0</sup> + 3<sup>1</sup>) 
= (1 + 2 + 4) × (1 + 3) = 7 × 4 = 28 

=> 12 = 2<sup>2</sup> × 3<sup>1</sup> 
Apply the formula: 
σ(12) = ((2<sup>2+1</sup> - 1) / (2 - 1)) × ((3<sup>1+1</sup> - 1) / (3 - 1)) 
= ((2<sup>3</sup> - 1) / 1) × ((3<sup>2</sup> - 1) / 2) 
= (8 - 1) × (9 - 1) / 2 = 7 × 8 / 2 = 7 × 4 = 28 

- Step 3: List all divisors and sum them directly Divisors of 12: 1, 2, 3, 4, 6, 12 Sum = 1 + 2 + 3 + 4 + 6 + 12 = 28 
✔ Confirmed: σ(12) = 28 </pre>

```math
\sigma(n) =
\left( \frac{p_1^{a_1+1} - 1}{p_1 - 1} \right)
\cdot
\left( \frac{p_2^{a_2+1} - 1}{p_2 - 1} \right)
\cdot \dots \cdot
\left( \frac{p_k^{a_k+1} - 1}{p_k - 1} \right)
```

❗ So, even though the individual terms look like fractions, they always simplify to integers because they represent the sum of a geometric series of powers of integers.

```cpp
//sum of all disisors
using ll = long long
int sigma(ll n) {
    int sum = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n/i;
        }
    }
    return sum;
}
```

- <u>Sieve-Based Implementation of σ(n)</u>

<pre>
1 2 3 4 5 6 7 8 9 10 ... n
(for 1 to n go all divisor of i and add i everytime)
</pre>

```cpp
const int nmax = 1e5 + 10;

int tau[nmax];
int sigma[nmax];

void seive() {
    for (int i = 1; i < nmax; i++) {
        for (int m = i; m < nmax; m += i) {
            tau[m]++
            sigma[m] += i;
        }
    }
}
```

example:

- [spojABA12D - Sum of divisors!](spojABA12D_Sum_of_divisors.cpp)

<pre>
he decided to look out for numbers whose sum of divisors is a prime number and he was the inventor of these special numbers he gave them the name K-numbers.

Given a range [A, B] you are expected to find the number of K-numbers in this range.

1 <= T <= 10000, 1<=A<=B<=10^6
</pre>

---

### Perfect Square

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

---
