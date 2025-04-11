#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<tuple<int, int, int, int, int>> vec;
  for (int i = 0; i < n; i++)
  {
    int x, y, z, u, v;
    cin >> x >> y >> z >> u >> v;
    vec.push_back(make_tuple(z, y, u, x, v));
  }
  sort(vec.begin(), vec.end()); // sort by this serial z,y,u,x,v
  for (auto [x, y, z, u, v] : vec)
  {
    cout << x << " " << y << " " << z << " " << u << " " << v << endl;
  }
  return 0;
}