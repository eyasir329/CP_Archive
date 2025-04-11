#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int k;
  cin >> k;
  int left = 1, right = 2e18;
  int ans = 0;
  while (left <= right)
  {
    int n = (left + right) / 2;
    if (n - (int)sqrtl(n) < k)
    {
      left = n + 1;
    }
    else
    {
      ans = n;
      right = n - 1;
    }
  }
  cout << ans << endl;
}

// cout<<(int)(k+sqrt(k+sqrt(k)))<<endl;
//  cout<<k+(long long)(sqrtl(k)+0.5)<<endl;

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