#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll m, n;
  cin >> m >> n;
  ll ans = 1;
  n = (n + m - 2);
  m = m - 1;
  // i<=min(r,n-r)
  for (ll i = 1; i <= min(m, n - m); i++) {
    ans = (ans * (n - i + 1)) / i;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}