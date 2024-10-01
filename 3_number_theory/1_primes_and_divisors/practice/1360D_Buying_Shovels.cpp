#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  int ans = INT_MAX;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      if (n / i <= k)
        ans = min(ans, i);
      if (i <= k)
        ans = min(ans, n / i);
    }
  }
  cout << ans << endl;
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}