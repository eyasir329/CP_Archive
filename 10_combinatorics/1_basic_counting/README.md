## Basic Counting

https://youkn0wwho.academy/topic-list/?category=basics&subCategory=basic_counting

#### <u>Expected Value</u>

<pre>
- Expected value = (total sum of all possible outcomes)/(number of all possible outcome)
</pre>

---

https://www.youtube.com/playlist?list=PLl-gb0E4MII0sGLCJeqDB3y63HZ6lM5LJ

### Two Rule of Basic Counting

<pre>
- Rule of Sum
- Rule of Product
(Total Way = prev way * next way, ex. contribution technique)
</pre>

#### <u>Rule of Sum</u> (one event, multiple ways)

<pre>
- If a task can be done in either one of n1 ways <b>or</b> in one of n2 ways, where the two sets of ways are disjoint, then there are n1+n2 ways to complete the task.

- If A and B are two disjoint sets (i.e., A∩B=∅),the total number of elements in their union is given by:∣A∪B∣=∣A∣+∣B∣
</pre>

example:

<pre>
- A. A woman has decided to shop at one store today, either in the north part of town or the south part of town. If she visits the north part of town, she will shop at either a mall, a furniture store, or a jewelry store. If she visits the south part of town then she will shop at either a clothing store or a shoe store. How many possible shops are there?ore or a shoe store. How many possible shops are there?

-> 2 + 3 = 5

- B. computer science instructor has two colleagues. One colleague has three textbooks on the analysis of algorithms and the other has 5 textbooks. If n denotes the maximum number of different books on this topic that this instructor can borrow, give the possible value(s) for n.

-> min: 5, max: 8
</pre>

#

#### <u>Rule of Product</u> (2 events (or more))

<pre>
- If there are m ways that one event can occur and n ways that another event can occur, then there are m x n ways that both events can occur.

- If A1, A2, ... ,Am are finite sets, then the number of elements in the Cartesian product of these sets is the product of the number of elements of each set.
</pre>

example:

<pre>
- A. During a local campaign, three republican and two democratic candidates are nominated for president of the school board. How many possibilities exist for a pair of candidates (one from each party) to oppose each other for the eventual election.

-> 3*2 = 6

A student ID is made of 3 upper-case letters followed by two digits.
B. How many possible IDs exist?
   26 * 26 * 26 * 10 * 10 = 1,757,600

C. How many IDs are possible if duplicate letters or numbers aren't allowed?
   26 * 25 * 24 * 10 * 9 = 1,404,000

D. How many student IDs are possible with an even number of "A"s?
   - For 0 "A"s:
     25 * 25 * 25 * 10 * 10 = 1,562,500
   - For 2 "A"s:
     3 * (25 * 25 * 10 * 10) = 1,562,500 + 3 * 2,500 = 1,570,000
</pre>

- https://cses.fi/problemset/task/1617

---

- <u>The Complement Rule and Complex Counting Problems</u> <br>
(at least -> Complement of none)
<pre>
- Sometimes when dealing with enumeration problems, it is easier to answer the opposite problem. That is, we can find all outcomes for which our condition isn't true, then subtract that total from our sample space, or total number of outcomes.

- IDs with Repetition = Sample space - no repeats => (26^3*10^2) - (26*25*24*10\*9)
</pre>

example:
![p1](https://i.ibb.co.com/XtfkHYX/IMG-0223.jpg)

<pre>
Determine the number of 6 digit integers (no leading zeros) in which:
A. Digis may be repeated
-> 9*10*10*10*10*10 = 900,000

B. No digit may be repeated
-> 9*9*8*7*6*5 = 136,080

C. No digit may be repeated, even number
-> last digit 0 or (2,4,6,8) => (9*8*7*6*5*1) + (8*8*7*6*5*4) = 68,800 

D. Digits may be repeated, even number
-> 9*10*10*10*10*5 = 450,000

E. No digit may be repeated, divisible by 5 
-> last digit 0 or 5 => (9*8*7*6*5*1) + (8*8*7*6*5*1) = 28,560

F. No digit may be repeated, divisible by 4 
-> last m=2(2^m) digit is divisible by 4 => (last two digit -> have one 0 or not zero) => (8*7*6*5*6(0X|X0)) + (7*7*6*5*16(24-6-2(44,88))) = 33,600
</pre>

#

### The Subtraction and Division Rules

#### <u>The Subtraction Rule - a.k.a. Principle of Inclusion-Exclusion</u>

<pre>
- If a task can be done in either n1 ways or n2 ways, then the total number of ways to do the task is n1+n2 minus the number of ways to do the task that were counted in both n1 and n2. 

A ∪ B = A + B − A ∩ B
</pre>

example:

<pre>
A. How many bit strings of length 7 either start with "1" bit or end with the 3 bit "000"?
-> (1*2*2*2*2*2*2) + (2*2*2*2*1*1*1) - (1*2*2*2*1*1*1) = 64 + 16 - 8 = (64-8)56 + (16-8)8 + 8 = 72

B. A software company receives 200 applications from collage graduations for a job planning a new ed.tech application. If 107 of the applicants majored in web development, 116 majored in computer science, and 23 majored in something else, how many applicants majored in both web development and computer science?
-> 200 - 23 = 107 + 116 - A ∩ B
</pre>

#### <u>The Division Rule</u>

<pre>
- There are n/d ways to do a task if it can be done using a procedure that can be carried out in n ways, where there are d corresponding outcomes per group.

- Or, If the finite set A is the union of n pairwise disjoint subsets each with d elements, then n = |A|/d

- In terms of functions: If f is a function from A to B, where both are finite sets, and for every value y belongs to B there are exactly d values x belongs to A such that f(x)=y, then |B|=|A|/d
</pre>

example:
![dr](https://i.ibb.co.com/F5VVn5h/IMG-0224.jpg)

<pre>
The arrangement (ABCD) is same as (BCDA,CDAB,DABC) because each person has the same left and right neighbors. Since there are 4 possible rotations for any seating order(one for each person being first), every unique circular arrangement is counted 4 times in the linear arrangement. To find the number of unique circular arrangements, we divide the total linear arrangements by the number of rotations.
-> 24/4 = 6  
</pre>

---

## Basic Counting Problems

https://flexbooks.ck12.org/cbook/ck-12-college-precalculus/section/14.2/primary/lesson/counting-with-permutations-and-combinations-c-precalc/

<pre>
- Probability is a mathematical way of calculating how likely an event is to occur.

P(event) = (# of favorable outcomes)/total outcomes

- The method of calculating the number of total outcomes can be stated as a general rule called the Counting Principle.
- The Counting Principle states that the number of choices or outcomes for two independent events.

Total outcomes for A and B = (# outcomes for A)*(# outcomes for B)
</pre>

- <u>The Counting Principle</u>
<pre>
Consider choice A with 3 options (A1,A2,A3), and choice B with 2 options (B1,B2). If you had to choose an option from A and then an option from B, the overall total number of options would be 3⋅2=6. The options are A1B1,A1B2,A2B1,A2B2,A3B1,A3B2.


- A decision tree is a graph that models the options possible at each stage of an experiment.
</pre>
![cp](https://i.ibb.co.com/hf4GG3w/Screenshot-from-2025-01-08-19-08-27.png)

---

## Permutations and Combinations

### <u>Factorial</u>

<pre>
n! is te number of ways to arrange n distinct objects in a line.
</pre>

![fact](https://i.ibb.co.com/K6QRB35/IMG-0232.jpg)
![fact2](https://i.ibb.co.com/Jk35g1g/IMG-0233.jpg)

<pre>
- The difference between combinations and permutations is whether or not the order you are choosing the objects matters.
</pre>

- Finding Power of Factorial Divisor

  You are given two numbers n  and  k . Find the largest power of k x such that n! is divisible by  k^x .

  https://cp-algorithms.com/algebra/factorial-divisors.html<br>
  https://artofproblemsolving.com/wiki/index.php/Factorial

  ```cpp
  //prime k
  //come from Legendre’s formula
  int fact_pow (int n, int k) {
      int res = 0;
      while (n) {
          n /= k;
          res += n;
      }
      return res;
  }
  ```

example:

- https://artofproblemsolving.com/wiki/index.php/2007_iTest_Problems/Problem_6
- https://artofproblemsolving.com/wiki/index.php/2003_AIME_I_Problems/Problem_1
- https://artofproblemsolving.com/wiki/index.php/2006_AIME_II_Problems/Problem_3

    <pre>Let P be the product of the first 100 positive odd integers. Find the largest integer k such that P is divisible by 3^k</pre>

- https://artofproblemsolving.com/wiki/index.php/1987_IMO_Problems/Problem_1

---

### <u> Permutations</u>

<pre>
- <b>order matter</b>
- nPr is the number of ways to choose r objects from n distinct objects and arrange them in line.
- one elements appear exactly one time in each permutation
- nPr = n!/(n-r)!
- It's a arrangement of elements in specific order
- Total number of permutation of sequence with distinct elements of lengths n is n!
</pre>

![perm1](https://i.ibb.co.com/MsQSS3f/IMG-0234.jpg)
![perm2](https://i.ibb.co.com/d20XP5f/IMG-0235.jpg)
![perm3](https://i.ibb.co.com/njVNnGK/IMG-0237.jpg)
![perm4](https://i.ibb.co.com/kcMdRjn/IMG-0236.jpg)
![perm5](https://i.ibb.co.com/ggwvmYV/IMG-0238.jpg)

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

## Summary

![key_dif](https://gre.myprepclub.com/forum/download/file.php?mode=view&id=14915&sid=8edb21de77d3cc7076c632167e1125f1)
<img src="https://gre.myprepclub.com/forum/download/file.php?mode=view&id=15320&sid=12a76328403e68df68076d41c5bf8c9d" alt="pc" width="650">

<code> Whenever you do a counting problem, the 1st thing you should decide is whether the problem is a Fundamental Counting Principle problem, a permutation problem, or a combination problem.</code>

<pre>
- The Fundamental Counting Principle states that if one event has m possible outcomes and a 2nd event has n possible outcomes, then there are m⋅n total possible outcomes for the two events together.

- A combination is the number of ways of choosing k objects from a total of n objects (order does not matter).

- A permutation is the number of ways of choosing and arranging k objects from a total of n objects (order does matter).
</pre>

[Some Problems (Basic)](https://flexbooks.ck12.org/cbook/ck-12-college-precalculus/section/14.2/primary/lesson/counting-with-permutations-and-combinations-c-precalc/)

#

### <u>More Combinations and Combinatorial Proof</u>

![p1](https://i.ibb.co.com/zb2Z1gT/IMG-0244.jpg)
![p3](https://i.ibb.co.com/860gfhc/IMG-0245.jpg)
(n,k) = (n,n-k)

![p2](https://i.ibb.co.com/n7Jy3Jh/IMG-0246.jpg)
![p4](https://i.ibb.co.com/WzGpWP1/IMG-0247.jpg)

---

### <u>The Binamial Theorem</u>

The binomial coefficient (n,k) equals the number of ways we can choose a subset
of k elements from a set of n elements.
![p](https://i.ibb.co.com/S4mvfRZN/Screenshot-from-2025-03-06-15-34-47.png)

![bt0](https://i.ibb.co.com/5FHstYR/IMG-0248.jpg)
![bt1](https://i.ibb.co.com/XsgKGQX/IMG-0249.jpg)
![bt2](https://i.ibb.co.com/mFz9FDm/IMG-0250.jpg)
![bt3](https://i.ibb.co.com/XzwQJ2H/IMG-0251.jpg)
![bt4](https://i.ibb.co.com/y8LyC9y/IMG-0252.jpg)

nC0 + nC1 + nC2 ... + nCn = 2^n

![bt5](https://i.ibb.co.com/bvGXNBn/IMG-0253.jpg)
![bt6](https://i.ibb.co.com/4KnVPZJ/IMG-0254.jpg)

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

### <u>Permutations with Indistinguishable Objects</u>

![pr1](https://i.ibb.co.com/QJ8rJWj/IMG-0271.jpg)
![pr2](https://i.ibb.co.com/NY61W8R/IMG-0272.jpg)
![pr3](https://i.ibb.co.com/KNHMm4w/IMG-0273.jpg)
![pr4](https://i.ibb.co.com/vDW25vF/IMG-0274.jpg)
![pr5](https://i.ibb.co.com/6YVbC4r/IMG-0275.jpg)

example:

- [300C_Beautiful_Numbers](./300C_Beautiful_Numbers.cpp)

    <pre>Vitaly is a very weird man. He's got two favorite digits a and b. Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b. Vitaly calls a good number excellent, if the sum of its digits is a good number.
  
    Now Vitaly is wondering, how many excellent numbers of length exactly n are there. As this number can be rather large, he asks you to count the remainder after dividing it by 1000000007 (1^9 + 7).
  
    sum_of_digits = i * a + (n - i) * b;</pre>

- https://www.codechef.com/problems/NWAYS

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
    ifact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;//1/i! = (1/(i+1)!)*(i+1)
    }
}

int nPr(int n, int r) { //O(1)
    if (n < r)return 0;
    return 1LL * fact[n] * ifact[n - r] % mod;
}

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

### <u>Computing using a Recurrence</u>

<pre>
- if modulo isn't prime then it will help us.

<sup>n</sup>C<sub>r</sub> = <sup>n-1</sup>C<sub>r-1</sub> + <sup>n-1</sup>C<sub>r</sub>

- base case C(n,0) = C(n,n) = 1
</pre>

**Explanation**

1. **Definition**:  
   nCr represents the number of ways to choose \(r\) items from \(n\) items without considering the order of selection.

2. **Breakdown Using Pascal's Identity**:  
   Consider whether the first item is included in the combination:

   - If the first item is included, then we must select \(r-1\) items from the remaining \(n-1\) items: \(n-1)C(r-1).
   - If the first item is excluded, then we must select all \(r\) items from the remaining \(n-1\) items: \(n-1)Cr.

   Adding these two cases gives:
   \[
   nCr = (n-1)C(r-1) + (n-1)Cr.
   \]

**Base Cases**

1. C(n,0) = 1\: There is exactly one way to choose \(0\) items (choose none).
2. C(n,n) = 1\: There is exactly one way to choose all \(n\) items.

```cpp
//O(N^2)
// mod can be any number
const int N = 2005, mod = 1e9 + 7;
int C[N][N], fact[N];

void prec() { //O(n*n)
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
}

int nCr(int n, int r) { //O(1)
    if (n < r) return 0;
    return C[n][r];
}

int nPr(int n, int r) { //O(1)
    if (n < r) return 0;
    return 1LL * nCr(n, r) * fact[r] % mod;
}
```

#

example:

---

### Pigeonhole Principle

<pre>
- Suppose a flock of pigeons fly into a set of pigeonholes to roost. If there are more pigeons than pigeonholes, then there must be at least 1 pigeonhole that has more than one pigeon in it.

- If k+1 or more objects are placed into k boxes, then there is at least one box containing two or more objects.
</pre>

- <u>Generalized Pigeonhole Principle</u>
<pre>
- If N objects are placed into k boxes, then there is at least one box containing ceil(N/k) objects.
</pre>

- <u>The Pigeonhole Proof</u>

![php1](https://i.ibb.co.com/kQKrd2w/IMG-0229.jpg)
![php2](https://i.ibb.co.com/T29Zmrt/IMG-0230.jpg)

example:
![pgh1](https://i.ibb.co.com/tqNtM3V/IMG-0226.jpg)

<pre>
A. Among 50 people, what is the number of people that must be born on the same month?
-> ceil(50/12) = 4.16... => 5 

B. How many students in a class must there be to ensure that 3 students get the same grade (one of A, B, C, D, or F)?
-> ceil(N/5) = 3 =>then consider, (N-1)/5 = 2(3-1) => N = 10+1 = 11 
</pre>

![pgh2](https://i.ibb.co.com/93nkw0t/IMG-0227.jpg)
![pgh3](https://i.ibb.co.com/ChcdKNj/IMG-0228.jpg)

---

## Pascal's Identity

- <u>Pascal's Identity and Triangle</u>

![pt1](https://i.ibb.co.com/C5bvpnS/IMG-0257.jpg)
Binomial coefficients also appear in Pascal’s triangle where each value
equals the sum of two above values
![pt2](https://i.ibb.co.com/NL4d0Mq/IMG-0258.jpg)
![pt3](https://i.ibb.co.com/fkdMPn0/IMG-0259.jpg)
![pt4](https://i.ibb.co.com/Qd0XZPN/IMG-0260.jpg)
![pt5](https://i.ibb.co.com/FnPRKtT/IMG-0261.jpg)

### <u>Other Identities Involving Binomial Coefficients</u>

![oi1](https://i.ibb.co.com/6wMtDKz/IMG-0262.jpg)
![oi2](https://i.ibb.co.com/bWSgrzX/IMG-0263.jpg)

---

## Stars and Bars

---
