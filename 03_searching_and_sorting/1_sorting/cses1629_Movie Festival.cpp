#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    vp[i] = {l, r};
  }
  sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b)
       { return a.second < b.second; });

  int cnt = 0, max_end = -1;
  for (auto [start, end] : vp)
  {
    if (start >= max_end)
    {
      max_end = end;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}