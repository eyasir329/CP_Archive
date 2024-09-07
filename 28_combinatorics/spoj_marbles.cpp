#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
  ll n, k;
  cin >> n >> k;
  // cout << ncr(n - 1, k - 1) << endl;
  ll ans = 1;
  n = n - 1;
  k = k - 1;
  for (int i = 1; i <= min(k, n - k); i++)
  {
    ans = (ans * (n - i + 1)) / i;
  }
  cout << ans << endl;
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // precomp();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}