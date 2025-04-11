#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
  int k = 0;
  for (int i = 1; i <= n; i++)
  {
    k = gcd(k, abs(v[i] - i));
  }
  cout << k << endl;
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