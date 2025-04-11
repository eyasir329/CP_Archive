#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n;
  cin >> n;
  std::vector<int> r(n);
  for (auto &i : r)
    cin >> i;
  int m;
  cin >> m;
  std::vector<int> b(m);
  for (auto &i : b)
    cin >> i;

  partial_sum(r.begin(), r.end(), r.begin());
  partial_sum(b.begin(), b.end(), b.begin());

  cout << max(0LL, *max_element(r.begin(), r.end())) + max(0LL, *max_element(b.begin(), b.end())) << endl;
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