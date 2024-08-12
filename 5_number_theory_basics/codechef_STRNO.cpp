// given x and k... find a number 'a' such that it has 'x' divisors and 'k' of them prime number
// print if 'a' exists then 1 otherwise 0

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int x, k;
  cin >> x >> k;
  int cnt = 0;
  for (int i = 2; i * i <= x; i++)
  {
    while (x % i == 0)
    {
      cnt++;
      x /= i;
    }
  }
  if (x > 1)
  {
    cnt++;
  }
  if (cnt >= k)
  {
    cout << 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}