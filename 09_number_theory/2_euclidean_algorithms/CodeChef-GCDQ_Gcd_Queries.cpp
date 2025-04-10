#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, q;
  cin >> n >> q;
  std::vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  std::vector<int> pre(n + 2), suf(n + 2);
  for (int i = 1; i <= n; i++) {
    pre[i] = gcd(pre[i - 1], v[i]);
  }
  for (int i = n; i > 0; i--) {
    suf[n - i + 1] = gcd(suf[n - i], v[i]);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    l--;
    r++;
    if (l >= 1 and l <= n) {
      ans = gcd(ans, pre[l]);
    }
    if (r <= n and r >= 1) {
      ans = gcd(ans, suf[r]);
    }
    cout << ans << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}