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

### <u>Combinations with Repetition</u>

![cr1](https://i.ibb.co.com/8zP86Tk/IMG-0264.jpg)
![cr2](https://i.ibb.co.com/9ZWL600/IMG-0265.jpg)
![cr3](https://i.ibb.co.com/TTBszc5/IMG-0266.jpg)
![cr4](https://i.ibb.co.com/KbFhDsL/IMG-0267.jpg)
![cr5](https://i.ibb.co.com/2F0dvWT/IMG-0268.jpg)
![cr6](https://i.ibb.co.com/SJY2cgJ/IMG-0269.jpg)
![cr7](https://i.ibb.co.com/b6gtzJg/IMG-0270.jpg)

example:

- [cses1716_Distributing Apples](./cses1716_Distributing%20Apples.cpp)

    <pre>There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.</pre>

- [spoj_ADATEAMS](./spoj_ADATEAMS%20_Ada_and_Teams.cpp)

    <pre>There are N schools from which exactly A will participate. Moreover there are B students in each school and exactly D of them will participate in the Olympiad.
  
    Step 1: Choose A schools from N.
        Number of ways = C(N, A)
    Step 2: For each of those A schools, choose D students from B.
        Number of ways per school = C(B, D)
    For A schools, it becomes (C(B, D))^A</pre>

---

### <u>Distributing Objects into Boxes</u>

https://usaco.guide/CPH.pdf#page=219

<pre>
- Scenario 1: Each box can contain at most one ball. For example, when n = 5 and k = 2, there are 10 solutions-> the answer is directly the binomial coefficient C(n,k).

- Scenario 2: A box can contain multiple balls. For example, when n = 5 and k = 2, there are 15 solutions -> the number of solutions is C(n+k−1,k)

- Scenario 3: Each box may contain at most one ball, and in addition, no two
adjacent boxes may both contain a ball. For example, when n = 5 and k = 2, there
are 6 solutions -> There are n − 2k + 1 such boxes and k + 1 positions for them. Thus, using the formula of scenario 2, the number of solutions is C(n−k+1,n−2k+1).
</pre>

![db1](https://i.ibb.co.com/9b1Kwd8/IMG-0276.jpg)
![db2](https://i.ibb.co.com/nD3m73n/IMG-0277.jpg)

The multinomial coefficient => C(n,(k1, k2, . . . , km))= n!/(k1!k2! · · · km!) ,
equals the number of ways we can divide n elements into subsets of sizes k1, k2, . . . , km, where k1 + k2 + · · · + km = n. Multinomial coefficients can be seen as a generalization of binomial cofficients; if m = 2, the above formula corresponds
to the binomial coefficient formula

![db3](https://i.ibb.co.com/k6xYjkQ/IMG-0278.jpg)
![db4](https://i.ibb.co.com/BBrPcLN/IMG-0279.jpg)
![db5](https://i.ibb.co.com/M14Zp0t/IMG-0280.jpg)
![db6](https://i.ibb.co.com/BNBd8Mm/IMG-0282.jpg)

---

#### Permutations and Combinations Summary

![key_dif](https://gre.myprepclub.com/forum/download/file.php?mode=view&id=14915&sid=8edb21de77d3cc7076c632167e1125f1)
<img src="https://gre.myprepclub.com/forum/download/file.php?mode=view&id=15320&sid=12a76328403e68df68076d41c5bf8c9d" alt="pc" width="650">

<code> Whenever you do a counting problem, the 1st thing you should decide is whether the problem is a Fundamental Counting Principle problem, a permutation problem, or a combination problem.</code>

<pre>
- The Fundamental Counting Principle states that if one event has m possible outcomes and a 2nd event has n possible outcomes, then there are m⋅n total possible outcomes for the two events together.

- A combination is the number of ways of choosing k objects from a total of n objects (order does not matter).

- A permutation is the number of ways of choosing and arranging k objects from a total of n objects (order does matter).
</pre>

[Some Problems (Basic)](https://flexbooks.ck12.org/cbook/ck-12-college-precalculus/section/14.2/primary/lesson/counting-with-permutations-and-combinations-c-precalc/)

```cpp
//O(2^n)
/** @return nCk mod p using naive recursion */
int binomial(int n, int k, int p) {
    if (k == 0 || k == n) { return 1; }
    return (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p)) % p;
}
```

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
    for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
    //The code computes inverses for all numbers from 1 to N-1 using this recursive formula:
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
    finv[0] = 1;
    for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
```

example:

- https://cses.fi/problemset/task/1079
- https://cses.fi/problemset/task/1715
- [cses1715_Creating Strings II](./cses1715_Creating%20Strings2.cpp)

    <pre>Given a string, your task is to calculate the number of different strings that can be created using its characters.
  The only input line has a string of length n. Each character is between a–z.</pre>

- [Factorial Under Modulo](https://vjudge.net/problem/Gym-248968S)

  <pre>
   Given a large number nn, determine efficiently the factorial of n. Since the answer might be very large, you should output the answer modulo 998,244,353998,244,353.
  </pre>

- [lightoj1067_Combinations](./1_basic_counting/2_combination/loghtoj1067_Combinations.cpp)

  <pre>
  Given n distinct objects, you want to take k of them. How many ways can you do it?
  </pre>

- [cese1715_Creating Strings II](./1_basic_counting/2_combination/cses1715_Creating%20Strings2.cpp)
  <pre>
  Given a string, your task is to calculate the number of different strings that can be created using its characters.
  
  Print the <b>number of different strings</b> modulo 1e9+7
  
  -> n!/(a!b!c!...)
  </pre>

- [LeetCode1922. Count Good Numbers](./1_permutations_combinations_and_basic_counting/LeetCode1922_Count%20Good%20Numbers.cpp)

    <pre>
    A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
  
    Given an integer n(1<=n<=1e15), return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.
  
    A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
    </pre>

- [1178C_Tiles](./1_permutations_combinations_and_basic_counting/1178C_Tiles.cpp)
    <pre>
    The dimension of this tile is perfect for this kitchen, as he will need exactly w×h tiles without any scraps. That is, the width of the kitchen is w tiles, and the height is h tiles. he still needs to decide on how exactly he will tile the floor. 
  
    There is a single aesthetic criterion that he wants to fulfil: two adjacent tiles must not share a colour on the edge — i.e. one of the tiles must have a white colour on the shared border, and the second one must be black.
  
    Find the number of possible tilings. As this number may be large, output its remainder when divided by 998244353 (a prime number).
  
    -> when all tiles (1,i) and (j,1) are placed, the rest is determined uniquely. We only need to count the number of ways to tile the first row and first column
  
    -> 1 box can be 4 way to order
    </pre>

---
