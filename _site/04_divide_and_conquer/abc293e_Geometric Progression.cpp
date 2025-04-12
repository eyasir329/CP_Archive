#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int power(int x, long long n, int mod)
{
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
// a^0 + a^1 + a^2 ... a^x (mod m)  basically upto a^x-1
int solve(int a, ll x, int m)
{
  if (x == 0)
  {
    return 1 % m; // m can be 1
  }
  if (x & 1)
  {
    ll p = x / 2;
    int cur = solve(a, p, m);
    int ans = (cur + 1LL * cur * power(a, p + 1, m) % m) % m;
    return ans;
  }
  else
  {
    int ans = (solve(a, x - 1, m) + power(a, x, m)) % m;
    return ans;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, m;
  ll x;
  cin >> a >> x >> m;
  cout << solve(a, x - 1, m) << endl;
  return 0;
}