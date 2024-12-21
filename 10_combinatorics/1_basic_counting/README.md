## Basic Counting

https://youkn0wwho.academy/topic-list/?category=basics&subCategory=basic_counting

#

###### Expected Value

<pre>
- Expected value = (total sum of all possible outcomes)/(number of all possible outcome)
</pre>

Two Rule of Basic Counting

<pre>
- Rule of Sum
- Rule of Product
(Total Way = prev way * next way, ex. contribution technique)
</pre>

## Permutations, Combinations and Basic Counting Problems

###### Factorial

<pre>
n! is te number of ways to arrange n distinct objects in a line.
</pre>

###### Combinations

<pre>
# order don't matter
nCr is the number of ways to choose r objects from n distinct objects.
nCr = n!/(r!(n-r)!)
</pre>

###### Permutations

<pre>
- order matter
- nPr is the number of ways to choose r objects from n distinct objects and arrange them in line.
- one elements appear exactly one time in each permutation
- nPr = n!/(n-r)!
- It's a arrangement of elements in specific order
- Total number of permutation of sequence with distinct elements of lengths n is n!
</pre>

#

- Given q queries. In each query, you are given two integers n and r, you will have to find nPr and nCr modulo 1e9+7 (1<=n,q<=1e6, 0<=r<=n)

```cpp
// mod must be prime number
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

---

<pre>
- next_permutation -> gives immediate next permutation(lexicographical order)
- prev_permutation -> gives immediate previous permutation(lexicographical order)

# also return boolean(have or not)
</pre>

- Generate all possible permutations

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

#

- Computing using a Recurrence
<pre>
- if modulo isn't prime then it will help us.

<sup>n</sup>C<sub>r</sub> = <sup>n-1</sup>C<sub>r-1</sub> + <sup>n-1</sup>C<sub>r</sub>

- base case C(n,0) = C(n,n) = 1
</pre>

###### **Explanation**

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

###### **Base Cases**

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

- [loghtoj1067_Combinations](./1_basic_counting/2_combination/loghtoj1067_Combinations.cpp)

  <pre>
  Given n distinct objects, you want to take k of them. How many ways can you do it?
  </pre>

- [cese1715_Creating Strings II](./1_basic_counting/2_combination/cses1715_Creating%20Strings2.cpp)
  <pre>
  Given a string, your task is to calculate the number of different strings that can be created using its characters.
  
  Print the <b>number of different strings</b> modulo 1e9+7
  
  -> n!/(a!b!c!...)
  </pre>

---

## Stars and Bars
