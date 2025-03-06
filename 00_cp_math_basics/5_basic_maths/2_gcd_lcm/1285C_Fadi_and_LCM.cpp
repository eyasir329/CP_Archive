#include <bits/stdc++.h>
using namespace std;
#define int long long

// x = lcm(a,b) ... given x, we have to find a,b
// minimum possible value of max(a,b)

void solve()
{
  int x;
  cin >> x;
  int ans = LLONG_MAX;
  for (int i = 1; i <= sqrt(x); i++)
  {
    if (x % i == 0 and gcd(i, (x / i)) == 1)
    // lcm(a,b)=a*b/gcd(a,b) => x = x/gcd(a,b) => gcd(a,b)=1
    {
      ans = min(ans, max(i, (x / i)));
    }
  }
  cout << ans << " " << (x / ans) << endl;
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