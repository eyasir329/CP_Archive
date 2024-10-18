#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n;
  cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  set<int> s;
  int prev = 1;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++)
  {
    if (s.find(v[i]) != s.end())
    {
      vp.push_back({prev, i + 1});
      s.clear();
      prev = i + 2;
    }
    else
    {
      s.insert(v[i]);
    }
  }
  if (vp.size() == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << vp.size() << endl;
    int cnt = 0;
    for (auto [x, y] : vp)
    {
      cnt++;
      if (cnt == vp.size())
      {
        cout << x << " " << n << endl;
      }
      else
      {
        cout << x << " " << y << endl;
      }
    }
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