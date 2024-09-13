#include <bits/stdc++.h>
using namespace std;

// abc366d_Cuboid Sum Query

void solve()
{
  int n;
  cin >> n;

  vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n, 0)));

  // Input
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        cin >> a[i][j][k];
      }
    }
  }

  // Dynamic allocation of sum array
  vector<vector<vector<int>>> sum(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

  // Prefix sum calculation
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        sum[i + 1][j + 1][k + 1] =
            sum[i][j + 1][k + 1] + sum[i + 1][j][k + 1] +
            sum[i + 1][j + 1][k] - sum[i][j][k + 1] - sum[i][j + 1][k] -
            sum[i + 1][j][k] + sum[i][j][k] + a[i][j][k];
      }
    }
  }

  int q;
  cin >> q;
  while (q--)
  {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    lx--, ly--, lz--;
    cout << sum[rx][ry][rz] - sum[lx][ry][rz] - sum[rx][ly][rz] -
                sum[rx][ry][lz] + sum[lx][ly][rz] + sum[lx][ry][lz] +
                sum[rx][ly][lz] - sum[lx][ly][lz]
         << "\n";
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

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