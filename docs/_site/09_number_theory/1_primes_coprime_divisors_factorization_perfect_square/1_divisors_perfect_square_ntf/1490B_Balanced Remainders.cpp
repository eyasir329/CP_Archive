#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  std::vector<int> c(3);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    c[x % 3]++;
  }

  int expect = n / 3;
  int cnt = 0;

  while (*max_element(c.begin(), c.end()) != *min_element(c.begin(), c.end()))
  {
    for (int i = 0; i < 3; i++)
    {
      while (c[i] > expect)
      {
        c[i]--;
        c[(i + 1) % 3]++;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
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