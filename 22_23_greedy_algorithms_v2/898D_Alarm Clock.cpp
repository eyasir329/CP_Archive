#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    while (!q.empty() and q.front() <= v[i] - m)
    {
      q.pop();
    }
    if (q.size() == k - 1)
    {
      cnt++;
    }
    else
    {
      q.push(v[i]);
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
  // cin >> t;
  while (t--)
    solve();
  return 0;
}