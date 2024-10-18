#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  if (k == 1 or k > n)
  {
    cout << n << endl;
    return;
  }
  int cnt = 0;
  while (n > 0)
  {
    cnt += n % k;
    n /= k;
  }
  cout << n + cnt << endl;
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