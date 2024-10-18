#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int power(int x, long long n)
{ // O(log n)
  int ans = 1 % mod;
  while (n > 0)
  {
    if (n & 1)
    {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void solve()
{
  int t;
  cin >> t;
  std::vector<int> ans;
  for (int i = 0; i < t; i++)
  {
    int x;
    cin >> x;
  }
  for (int i = 0; i < t; i++)
  {
    int y;
    cin >> y;
    int ncr = power(2, y);
    ans.push_back(ncr);
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
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