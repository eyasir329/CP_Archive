#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == '0' or b[i] == '0')
    {
      ans++;
    }
    if (a[i] == '0' and b[i] == '1' or a[i] == '1' and b[i] == '0')
    {
      ans++;
    }
  }
  int i = 0;
  while (i < n - 1)
  {
    if (a[i] == '0' and b[i] == '0' and a[i + 1] == '1' and b[i + 1] == '1' or a[i] == '1' and b[i] == '1' and a[i + 1] == '0' and b[i + 1] == '0')
    {
      ans++;
      i++;
    }
    i++;
  }
  cout << ans << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}