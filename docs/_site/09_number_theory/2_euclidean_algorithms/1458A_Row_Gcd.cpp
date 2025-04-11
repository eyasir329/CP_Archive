#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n, m;
  cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  int g = 0;
  for (int i = 1; i < n; i++)
  {
    g = gcd(g, a[i] - a[0]);
  }
  for (int i = 0; i < m; i++)
  {
    cout << gcd(a[0] + b[i], g) << " ";
  }
  cout << endl;
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