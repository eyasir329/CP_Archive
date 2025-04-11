#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
map<pair<int, int>, int> mp;

int query(int l, int r)
{
  if (l == r)
    return INT_MIN;
  if (mp.find(make_pair(l, r)) != mp.end())
  {
    return mp[{l, r}];
  }
  cout << "? " << l << " " << r << endl;
  int x;
  cin >> x;
  return mp[{l, r}] = x;
}

void solve()
{
  cin >> n;
  int max2 = query(1, n);
  int ans = 0;
  if (query(1, max2) == max2)
  {
    int l = 1, r = max2;
    while (r - l > 1)
    {
      int m = (l + r) / 2;
      if (query(m, max2) == max2)
      {
        l = m;
      }
      else
      {
        r = m;
      }
    }
    ans = l;
  }
  else
  {
    int l = max2, r = n;
    while (r - l > 1)
    {
      int m = (l + r) / 2;
      if (query(max2, m) == max2)
      {
        r = m;
      }
      else
      {
        l = m;
      }
    }
    ans = r;
  }
  cout << "! " << ans << endl;
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