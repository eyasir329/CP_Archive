#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int rem = x - (v[i].first + v[j].first);
      auto k = lower_bound(v.begin() + j + 1, v.end(), make_pair(rem, 0LL));
      if (k != v.end() and v[k - v.begin()].first == rem)
      {
        cout << v[i].second << " " << v[j].second << " " << v[k - v.begin()].second << endl;
        return;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
  solve();
  return 0;
}