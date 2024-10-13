#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, k;
  cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int sum = 0, ans = 0;
  int i = 0, j = 0;
  while (j < n)
  {
    sum += a[j];               // include the jth element
    while (i <= j and sum > k) // move left pointer one step right
    {
      sum -= a[i]; // removing a[i]
      i++;
    }
    if (sum <= k)
    {
      ans = max(ans, j - i + 1);
    }
    j++; // move right pointer one step right
  }
  cout << ans << endl;
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