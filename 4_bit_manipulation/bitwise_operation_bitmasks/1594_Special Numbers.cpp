#include <bits/stdc++.h>
using namespace std;
#define int long long

// base of n
// a sequence written by each num which is a sum of different non-negative powers of n

const int mod = 1e9 + 7;
void solve()
{
  int n, k;
  cin >> n >> k;
  int p = 1, ans = 0;
  for (int i = 0; i < 31; i++)
  {
    if (k & (1 << i))
    {
      ans = (ans + p) % mod;
    }
    p = (p * n) % mod;
  }
  cout << ans << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

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