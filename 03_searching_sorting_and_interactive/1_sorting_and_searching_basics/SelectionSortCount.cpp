#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 998244353;

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
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;  // 1/i! = (1/(i+1)!)*(i+1)
  }
}

int nCr(int n, int r) {  // O(1)
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int32_t main() {  // O(N + q)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int n;
  cin >> n;
  std::vector<int> t(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> t[i];
  }
  int ans = 1;
  for (int i = n - 2; i >= 0; i--) {
    int r1 = t[i];
    int n1 = 0;
    if (i != n - 2) n1 = t[i + 1];
    ans = (1LL * ans * nCr(n1 + 1, r1)) % mod;
    // comb(c_next + 1, c_i): Number of ways to choose swap positions.
  }
  cout << ans << endl;
  return 0;
}