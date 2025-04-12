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

### Pascal's Identity

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
