#include <bits/stdc++.h>
using namespace std;

#define double long double
int n, k;
vector<int> v;

bool goodFunction(double m)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cnt += (int)(v[i] / m);
  }
  return (cnt >= k) ? true : false;
}

int32_t main()
{
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  double l = 0, r = 1e7;
  for (int i = 0; i < 100; i++)
  {
    double m = (l + r) / 2;
    (goodFunction(m)) ? l = m : r = m;
  }
  cout << fixed << setprecision(7) << l << endl;
  return 0;
}