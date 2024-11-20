#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    std::vector<int> v(n), cnt(30, 0);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      for (int j = 0; j < 30; j++)
      {
        if (v[i] >> j & 1)
        {
          cnt[j]++;
        }
      }
    }
    for (int k = 1; k <= n; k++)
    {
      bool ok = true;
      for (int j = 0; j < 30; j++)
      {
        if (cnt[j] % k != 0)
        {
          ok = false;
        }
      }
      if (ok)
      {
        cout << k << " ";
      }
    }
    cout << endl;
  }
  return 0;
}