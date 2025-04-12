#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, m;
  cin >> n >> m;
  std::vector<int> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  std::vector<int> freq(m + 1, n / m);
  std::vector<int> vec;
  for (int i = 0; i < n; i++)
  {
    if (v[i] > m or freq[v[i]] == 0)
    {
      vec.push_back(i);
    }
    else
    {
      freq[v[i]]--;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++)
  {
    while (freq[i] != 0)
    {
      int idx = vec.back();
      vec.pop_back();
      v[idx] = i;
      freq[i]--;
      cnt++;
    }
  }
  cout << n / m << " " << cnt << endl;
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
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