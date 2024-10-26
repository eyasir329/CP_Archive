#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n;
  cin >> n;
  std::vector<int> v(n);
  set<int> st;
  int zero = 0, one = 0, two = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (v[i] == 0)
      zero++;
    if (v[i] == 1)
      one++;
    if (v[i] == 2)
      two++;
    st.insert(v[i]);
  }
  if (st.size() == 1 or !one)
  {
    cout << "YES" << endl;
    return;
  }
  if (one and (zero or two))
  {
    cout << "NO" << endl;
    return;
  }
  if (one)
  {
    for (auto x : v)
    {
      if (st.find(x - 1) != st.end())
      {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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