#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int a, b;
  cin >> a >> b;
  if (a == b)
  {
    cout << "infinity" << endl;
  }
  else if (a < b)
  {
    cout << 0 << endl;
  }
  else
  {
    int ans = 0;
    a -= b;
    if (a == 1)
    {
      cout << (b == 0) << endl;
      return;
    }
    for (int i = 1; i * i <= a; i++)
    {
      if (a % i == 0)
      {
        if (i > b)
          ans++;
        if (a / i > b)
          ans++;
        if (i > b and a / i > b and i == a / i)
          ans--;
      }
    }
    cout << ans << endl;
  }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}