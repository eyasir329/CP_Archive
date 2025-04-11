#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

void solve()
{
  // i<j and l<=(a[i]+a[j])<=r
  // st.size()-(strictle less than l + strictly greater thar r)
  // strictly less than l order_of_key({a[i],-1})
  // strictly greater than r st.size()-order_of_key({a[i],INF})
  // cnt+=st.size()-(order_of_key({a[i],-1})+(st.size()-order_of_key({a[i],INF})))

  int n, l, r;
  cin >> n >> l >> r;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  PBDS st;

  long long cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int x = l - v[i]; // >=
    int y = r - v[i]; // <=

    int left = st.order_of_key({x, -1});
    int right = st.order_of_key({y, 1e6});
    ;

    cnt += right - left;
    st.insert({v[i], i});
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
  cin >> t;
  while (t--)
    solve();
  return 0;
}