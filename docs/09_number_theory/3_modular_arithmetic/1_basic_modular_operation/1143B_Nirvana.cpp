#include <bits/stdc++.h>
using namespace std;
#define int long long

// max product of digit from 1-n
// max of (2479, 2479*1-1,247*10-1,24*100-1,2*1000-1)
void solve()
{
  int n;
  cin >> n;
  int ans = 0;
  int p = 1;
  auto product = [](int k)
  {
    int z = 1;
    while (k != 0)
    {
      z *= k % 10;
      k /= 10;
    }
    return z;
  };
  ans = product(n);
  while (n != 0)
  {
    ans = max(ans, product(n * p - 1));
    n /= 10;
    p *= 10;
  }
  cout << ans << endl;
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}