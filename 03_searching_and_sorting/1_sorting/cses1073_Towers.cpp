#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  multiset<int> tower_top;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    auto it = tower_top.upper_bound(x); // Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
    if (it != tower_top.end())
    {
      tower_top.erase(it);
      tower_top.insert(x);
    }
    else
    {
      tower_top.insert(x);
    }
  }
  cout << tower_top.size() << endl;
  return 0;
}