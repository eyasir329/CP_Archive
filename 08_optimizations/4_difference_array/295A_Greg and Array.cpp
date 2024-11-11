#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e6 + 9;
ll l[N], r[N], x[N], d[N], a[N], opt[N];

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
  { // initial array
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  { // difference array
    d[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= m; i++)
  { // operations
    cin >> l[i] >> r[i] >> x[i];
  }
  while (q--)
  { // number of operations
    int l, r;
    cin >> l >> r;
    opt[l]++;
    opt[r + 1]--;
  }
  for (int i = 1; i <= m; i++)
  { // prefix of operation -> to find actual number of oprations
    opt[i] += opt[i - 1];
  }
  for (int i = 1; i <= m; i++)
  {
    d[l[i]] += x[i] * opt[i];
    d[r[i] + 1] -= x[i] * opt[i];
  }
  for (int i = 1; i <= n; i++)
  {
    d[i] += d[i - 1];
    cout << d[i] << " ";
  }
  cout << endl;
  return 0;
}