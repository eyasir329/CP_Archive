#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> a(n + 2, 0);

  while (k--)
  {
    int l, r;
    cin >> l >> r;
    a[max(l - d + 1, 1ll)]++;
    a[r + 1]--;
  }
  int mi = 1, mx = 1;
  for (int i = 1; i <= n - d + 1; i++)
  {
    a[i] += a[i - 1];
    if (a[i] < a[mi])
      mi = i;
    if (a[i] > a[mx])
      mx = i;
  }
  cout << mx << " " << mi << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
