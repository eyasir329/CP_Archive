#include <bits/stdc++.h>
using namespace std;
#define int long long

// n,n<=1e6 we have to count (a+b%5==0),1<=a,b<=n,m

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(5, 0), b(5, 0);
  for (int i = 1; i <= n; i++) a[i % 5]++;
  for (int i = 1; i <= m; i++) b[i % 5]++;
  int cnt = 0;
  cnt += (a[0] * b[0]);
  cnt += (a[1] * b[4]);
  cnt += (a[2] * b[3]);
  cnt += (a[3] * b[2]);
  cnt += (a[4] * b[1]);
  cout << cnt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}