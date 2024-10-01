#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

void solve()
{
  // i<j and a[i]+a[j]>b[i]+b[j]
  // a[i]-b[i]>b[j]-a[j]-- a[i]-b[i]>-(a[i]-b[i])
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++)
  {
    c[i] = a[i] - b[i];
  }

  PBDS st;

  long long cnt = 0;
  for (int i = 0; i < n; i++)
  {
    // strictly less than 1 = order_of_key({1,-1}) --- at least 1 starting to {1,0}
    // strictly greater than 1 = st.size()-order_of_key({1,INF})... have to find (<=) to find strictly greather(>)
    cnt += st.size() - st.order_of_key({-(c[i]), 1e6});
    st.insert({c[i], i});
  }
  cout << cnt << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

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