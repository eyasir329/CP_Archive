#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int i)
{
  cout << "? " << i + 1 << endl;
  int x;
  cin >> x;
  return x - 1;
}

void solve()
{
  int n;
  cin >> n;
  std::vector<int> v(n, -1);
  for (int i = 0; i < n; i++)
  {
    if (v[i] == -1)
    {
      int cur = query(i);
      while (v[cur] == -1)
      {
        int temp = cur;
        cur = query(i);
        v[temp] = cur;
      }
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++)
  {
    cout << v[i] + 1 << " ";
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
  cin >> t;
  while (t--)
    solve();
  return 0;
}