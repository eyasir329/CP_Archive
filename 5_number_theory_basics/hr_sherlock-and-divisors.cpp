#include <bits/stdc++.h>
using namespace std;
#define int long long

// how much divisors have

void solve()
{
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      if (i % 2 == 0)
        cnt++;
      if (n / i != i)
      {
        if ((n / i) % 2 == 0)
          cnt++;
      }
    }
  }
  cout << cnt << endl;
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