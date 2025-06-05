#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e6 + 7, mod = 1e9 + 7;  // N must be less than mod

int fact[N], ifact[N];

int power(int x, int n) {  // O(logn)
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

int inverse(int a) {  // O(logmod)
  return power(a, mod - 2);
}

void prec() {  // O(n)
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
  // for(int i=0;i<N;i++){
  //     ifact[i] = power(fact[i],mod-2);
  // }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;  // 1/i! = (1/(i+1)!)*(i+1)
  }
}

int nCr(int n, int r) {  // O(1)
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int n;
  cin >> n;
  cout << (((2LL * nCr(n + n - 1, n - 1)) % mod - n) + mod) % mod
       << endl;  //>=0
  return 0;
}