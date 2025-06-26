### <u>Factorial</u>

```text
n! is the number of ways to arrange n distinct objects in a line.
```

![fact](https://i.ibb.co.com/K6QRB35/IMG-0232.jpg)  
![fact2](https://i.ibb.co.com/Jk35g1g/IMG-0233.jpg)

<pre>
- The difference between combinations and permutations is whether or not the order you are choosing the objects matters.
</pre>

#### Finding Power of Factorial Divisor

You are given two numbers \(n\) and \(k\). Find the largest power of \(k^x\) such that \(n!\) is divisible by \(k^x\).

**Factorial Divisors:** [cp-algorithms](https://cp-algorithms.com/algebra/factorial-divisors.html), [AoPS](https://artofproblemsolving.com/wiki/index.php/Factorial)

```cpp
// Prime k — uses Legendre’s formula
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}
```

**Example Problems**:

- [2007 iTest Problem 6](https://artofproblemsolving.com/wiki/index.php/2007_iTest_Problems/Problem_6)
- [2003 AIME I Problem 1](https://artofproblemsolving.com/wiki/index.php/2003_AIME_I_Problems/Problem_1)
- [2006 AIME II Problem 3](https://artofproblemsolving.com/wiki/index.php/2006_AIME_II_Problems/Problem_3)

> Let \(P\) be the product of the first 100 positive odd integers. Find the largest integer \(k\) such that \(P\) is divisible by \(3^k\).

- [1987 IMO Problem 1](https://artofproblemsolving.com/wiki/index.php/1987_IMO_Problems/Problem_1)

- Factorial Under Modulo [Gym Problem Link](https://vjudge.net/problem/Gym-248968S)

> Given a large number n, determine efficiently the factorial of n. Since the answer might be very large, you should output the answer modulo 998244353.

---

### <u> Permutations</u>

(arrange)

<pre>
- <b>order matter</b>
- nPr is the number of ways to choose r objects from n distinct objects and arrange them in line.
- one elements appear exactly one time in each permutation
- nPr = n!/(n-r)!
- It's a arrangement of elements in specific order
- Total number of permutation of sequence with distinct elements of lengths n is n!

- all combinatorics problem -> combinatorial explosion (easily grow)
</pre>

![perm1](https://i.ibb.co.com/MsQSS3f/IMG-0234.jpg)

![perm2](https://i.ibb.co.com/d20XP5f/IMG-0235.jpg)

![perm3](https://i.ibb.co.com/njVNnGK/IMG-0237.jpg)

![perm4](https://i.ibb.co.com/kcMdRjn/IMG-0236.jpg)

![perm5](https://i.ibb.co.com/ggwvmYV/IMG-0238.jpg)

<pre>
- 4 letters word with unique letters -> P(26,4) = C(26,4)*4! = 26*25*24*23

</pre>

<pre>
- next_permutation -> gives immediate next permutation(lexicographical order)
- prev_permutation -> gives immediate previous permutation(lexicographical order)

# also return boolean(have or not)
</pre>

- <u>Generate all possible permutations</u>

```cpp
int main() {
    int a[] = {1, 2, 3};
    // if we need all permutation, then we have to sort it
    sort(a, a + n);
    do {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}
```

example:

- [300C_Beautiful_Numbers](./300C_Beautiful_Numbers.cpp)

    <pre>Vitaly is a very weird man. He's got two favorite digits a and b. Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b. Vitaly calls a good number excellent, if the sum of its digits is a good number.
  
    Now Vitaly is wondering, how many excellent numbers of length exactly n are there. As this number can be rather large, he asks you to count the remainder after dividing it by 1000000007 (1^9 + 7).
  
    sum_of_digits = i * a + (n - i) * b;</pre>

- https://www.codechef.com/problems/NWAYS

---

### <u> Combinations</u>

<pre>
- <b>order don't matter</b>
nCr is the number of ways to choose r objects from n distinct objects.
nCr = n!/(r!(n-r)!)
</pre>

- Given and find out how many different ways are there to represent N as sum of K non-zero integers.

<pre>
In general, for N there will be N-1 dashes, and out of those we want to choose K-1 and place comma in place of those and in place of rest of the dashes place plus sign. So ways of choosing K-1 objects out of N-1 is C(N-1,K-1)
</pre>

![comp1](https://i.ibb.co.com/LQt1X96/IMG-0239.jpg)

![comp2](https://i.ibb.co.com/CJDPQ0h/IMG-0240.jpg)

![comp3](https://i.ibb.co.com/QrbWYQx/IMG-0241.jpg)

![comp4](https://i.ibb.co.com/3Tgc1ZS/IMG-0242.jpg)

![comp5](https://i.ibb.co.com/yNfDYRL/IMG-0243.jpg)

### <u>More Combinations and Combinatorial Proof</u>

![p1](https://i.ibb.co.com/zb2Z1gT/IMG-0244.jpg)
![p3](https://i.ibb.co.com/860gfhc/IMG-0245.jpg)
(n,k) = (n,n-k)

![p2](https://i.ibb.co.com/n7Jy3Jh/IMG-0246.jpg)
![p4](https://i.ibb.co.com/WzGpWP1/IMG-0247.jpg)

---

#### Summary

![key_dif](https://gre.myprepclub.com/forum/download/file.php?mode=view&id=14915&sid=8edb21de77d3cc7076c632167e1125f1)

<code> Whenever you do a counting problem, the 1st thing you should decide is whether the problem is a Fundamental Counting Principle problem, a permutation problem, or a combination problem.</code>

<pre>
- The Fundamental Counting Principle states that if one event has m possible outcomes and a 2nd event has n possible outcomes, then there are m⋅n total possible outcomes for the two events together.

- A combination is the number of ways of choosing k objects from a total of n objects (order does not matter).

- A permutation is the number of ways of choosing and arranging k objects from a total of n objects (order does matter).
</pre>

[Some Problems (Basic)](https://flexbooks.ck12.org/cbook/ck-12-college-precalculus/section/14.2/primary/lesson/counting-with-permutations-and-combinations-c-precalc/)

<pre>
- Two team A(10), B(6), how much way they form a line such that no 2 member from B can't place beside? => 10! * C(11,6) * 6!
- Number of substring -> choose first and last letter of a substring C(N,2) + N (Single letter))
</pre>

---

### Code

- <u>nCr using Naive Recursive method</u>

```cpp
//nCr using naive recursion -> O(2^n)
int binomial(int n, int k, int p) {
    if (k == 0 || k == n) { return 1; }
    return (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p)) % p;
}
```

- <u>Using Multiplicative Formula (Best for Single Queries)</u>

<pre>
- Computes the result in O(r) time
- More efficient than factorial-based approaches for single queries
- Handles cases where r > n-r by computing nC(n-r) instead
</pre>

```math
\binom{n}{r} = \frac{n \cdot (n-1) \cdot (n-2) \cdots (n - r + 1)}{r \cdot (r-1) \cdot (r-2) \cdots 1}
```

This is equivalent to:

```math
\binom{n}{r} = \frac{n!}{r!(n-r)!}
```

```cpp
//method 1
ll nCr(int n, int r) {
  if (r > n) return 0;
  if (r == 0 || r == n) return 1;

  // To minimize calculations, we compute nCr = nC(n-r)
  r = min(r, n - r);

  ll result = 1;
  for (int i = 1; i <= r; i++) {
    result *= (n - r + i);
    result /= i;
  }
  return result;
}

//method2
ll nCr(int n, int r) {
  if (r > n) return 0;
  if (r == 0 || r == n) return 1;
  ll ans = 1;
  for (size_t i = 1; i <= min(r, n - r); i++) {
    ans = (ans * (n - i + 1)) / i;
  }
  return ans;
}
```

- <u>Dynamic Programming (Better for Multiple Queries)</u>

<pre>
- Uses Pascal's Triangle approach
- Time complexity: O(n*r)
- Space complexity: O(n*r)
- Better when you need to compute many nCr values (memoization)
</pre>

```cpp
long long nCr(int n, int r) {
    if (r > n) return 0;

    vector<vector<long long>> dp(n+1, vector<long long>(r+1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}
```

```cpp
//space optimized dp
long long nCr(int n, int r) {
    if (r > n) return 0;

    vector<long long> dp(r+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[r];
}
```

<pre>
- For single queries: Use Method 1 (fastest)
- For multiple queries: Use Method 3 (most memory efficient)
- For very large n and r: Consider using modulo arithmetic with precomputed factorials
</pre>

- <u>Given q queries. In each query, you are given two integers n and r, you will have to find nPr and nCr modulo 1e9+7 (1<=n,q<=1e6, 0<=r<=n)</u>

```cpp
// mod must be prime number -> O(n + log MOD)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 1e9 + 7;//N must be less than mod

int fact[N], ifact[N];

int power(int x, int n) { //O(logn)
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

int inverse(int a) { //O(logmod)
    return power(a, mod - 2);
}

void prec() { //O(n)
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    // for(int i=0;i<N;i++){
    //     ifact[i] = power(fact[i],mod-2);
    // }
    ifact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;//1/i! = (1/(i+1)!)*(i+1)
    }
}

int nPr(int n, int r) { //O(1)
    if (n < r)return 0;
    return 1LL * fact[n] * ifact[n - r] % mod;
}

// int nCr(int n, int r) { //O(logn)
//     ll ans = fact[n];
//     ans = ans*power(fact[r],mod-2)%mod;
//     ans = ans*power(fact[n-r],mod-2)%mod;
//     return ans;
// }

int nCr(int n, int r) { //O(1)
    if (n < r)return 0;
    return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int32_t main() {//O(N + q)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    int q; cin >> q;
    while (q--) {
        int n, r; cin >> n >> r;
        cout << nPr(n, r) << " " << nCr(n, r) << endl;
    }
    return 0;
}
```

```cpp
void prec() {
    // Factorials and inverses
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    //The code computes inverses for all numbers from 1 to N-1 using this recursive formula:
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    }
    finv[0] = 1;
    for (int i = 1; i < N; i++) {
        finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
    }
}
```

example:

- [leetcode_Unique Paths](leetcode_unique_paths.cpp)

<pre>
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

1 <= m, n <= 100
</pre>

- [hackerearth_K-Special Cells](./hackerearth_K-Special%20Cells.cpp)

<pre>
we need to find the total strength collected across all possible paths from the top-left corner (1,1) to the bottom-right corner (H,W) of an H×W grid, moving only right or down, while passing through K special cells that each contribute their strength when visited.
</pre>

- https://cses.fi/problemset/task/1079

- [lightoj1067_Combinations](./1_basic_counting/2_combination/loghtoj1067_Combinations.cpp)

  <pre>
  Given n distinct objects, you want to take k of them. How many ways can you do it?
  </pre>

- [LeetCode1922. Count Good Numbers](./LeetCode1922_Count%20Good%20Numbers.cpp)

    <pre>
    A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
  
    Given an integer n(1<=n<=1e15), return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.
  
    A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
    </pre>

- [1178C_Tiles](./1178C_Tiles.cpp)
    <pre>
    The dimension of this tile is perfect for this kitchen, as he will need exactly w×h tiles without any scraps. That is, the width of the kitchen is w tiles, and the height is h tiles. he still needs to decide on how exactly he will tile the floor. 
  
    There is a single aesthetic criterion that he wants to fulfil: two adjacent tiles must not share a colour on the edge — i.e. one of the tiles must have a white colour on the shared border, and the second one must be black.
  
    Find the number of possible tilings. As this number may be large, output its remainder when divided by 998244353 (a prime number).
  
    -> when all tiles (1,i) and (j,1) are placed, the rest is determined uniquely. We only need to count the number of ways to tile the first row and first column
  
    -> 1 box can be 4 way to order
    </pre>

- [cses1716_Distributing Apples](./cses1716_Distributing%20Apples.cpp)

    <pre>There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.</pre>

- [spoj_ADATEAMS](./spoj_ADATEAMS%20_Ada_and_Teams.cpp)

    <pre>There are N schools from which exactly A will participate. Moreover there are B students in each school and exactly D of them will participate in the Olympiad.
  
    Step 1: Choose A schools from N.
        Number of ways = C(N, A)
    Step 2: For each of those A schools, choose D students from B.
        Number of ways per school = C(B, D)
    For A schools, it becomes (C(B, D))^A</pre>

- https://codeforces.com/problemset/problem/288/B

---
