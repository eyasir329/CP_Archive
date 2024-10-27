#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
using ll = long long;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    std::vector<ll> v(n);

    ordered_multiset<ll> s, ss;
    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      s.insert(v[i]);
      m[v[i]]++;
    }

    ll ans = n;
    for (int i = 0; i < n; i++)
    {
      ss.insert(v[i]);
      ll x = s.order_of_key(v[i]); // exactly small than v[i]
      ll y = ss.order_of_key(v[i]);
      ans = min(n - (x - y + m[v[i]]), ans);
      // n - (small -> large)
      // n - (n(small)+n(large)-n(equal))
      cout << x << " " << y << " " << v[i] << " " << n - (x - y + m[v[i]]) << endl;
    }
    cout << ans << endl;
  }

  return 0;
}