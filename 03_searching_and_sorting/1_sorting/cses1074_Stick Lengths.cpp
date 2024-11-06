#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int median = (n + 1) / 2;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += abs(a[i] - a[median]);
  }
  cout << ans << endl;
  return 0;
}