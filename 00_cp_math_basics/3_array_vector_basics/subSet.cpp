#include <bits/stdc++.h>
using namespace std;

// sub-set - all element are distint, order not matter
// total number of subset 2^n - 1
// r length subset -> nCr

// generating all subset using bitmask

void subSet(int a[], int n)  // O(n*2^n)
{
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cout << a[i] << " ";
      }
    }
    cout << endl;
  }
}

// https://codeforces.com/problemset/problem/550/B

// fixed length subset
// https://www.spoj.com/problems/HC12/