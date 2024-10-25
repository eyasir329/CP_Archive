#include <bits/stdc++.h>
using namespace std;
#define int long long

// sliding window

void solve()
{
  int n, k, q;
  cin >> n >> k >> q;
  std::vector<int> v(n), ans(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    v[i] -= i;
  }

  map<int, int> m;
  multiset<int> ms;

  for (int i = 0; i < k; i++)
  {
    m[v[i]]++;
    ms.insert(m[v[i]]);
  }

  ans[0] = k - *ms.rbegin();

  for (int i = k; i < n; i++)
  {
    if (ms.find(m[v[i - k]]) != ms.end())
    {
      ms.erase(ms.find(m[v[i - k]]));
    }
    m[v[i - k]]--;
    m[v[i]]++;
    ms.insert(m[v[i]]);
    ans[i - k + 1] = k - *ms.rbegin();
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << ans[l - 1] << endl;
  }
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