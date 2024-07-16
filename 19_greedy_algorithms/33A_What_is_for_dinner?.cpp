#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> viability(m + 1, INT_MAX);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    viability[a] = min(viability[a], b);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++)
  {
    ans += viability[i];
  }
  cout << min(ans, k) << endl;
}

int main()
{
  solve();
  return 0;
}
