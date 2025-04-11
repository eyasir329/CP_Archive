#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e6 + 7, mod = 1e9 + 7;  // N must be less than mod

int fact[N], ifact[N], g[N];
;

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

  // rook pre select
  // g[i] counts ways to place rooks on i rows/columns
  g[0] = 1;
  // First loop counts all possible pair placements
  for (int i = 2; i < N; i++) {
    // i * (i - 1): Ways to choose two distinct rows (and their corresponding
    // columns) g[i - 2]: Ways to place remaining rooks on the reduced board
    g[i] += 1LL * i * (i - 1) % mod * g[i - 2] % mod;
    g[i] %= mod;
  }
  // Second loop adjusts for indistinguishable pairs by dividing by (i/2)!
  for (int i = 2; i < N; i += 2) {
    g[i] = 1LL * g[i] * ifact[i / 2] % mod;
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
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int m = n;
    for (int i = 1; i <= k; i++) {
      int r, c;
      cin >> r >> c;
      if (r == c)
        m--;  // Diagonal move uses 1 row/column
      else
        m -= 2;  // Non-diagonal uses 2
    }
    int ans = 0;
    for (int k = 0; k <= m; k++) {
      // nCr(m, k): Ways to choose positions for singles
      // g[m-k]: Ways to place pairs in remaining positions
      ans += 1LL * nCr(m, k) * g[m - k] % mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}