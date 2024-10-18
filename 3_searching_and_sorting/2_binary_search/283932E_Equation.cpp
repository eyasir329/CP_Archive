#include <bits/stdc++.h>
using namespace std;

#define double long double

int32_t main()
{
  double c;
  cin >> c;
  double l = 0, r = 1e5; // r = 10^11*10^-6
  int k = 100;           // log2(max/epsilon)<<k
  for (int i = 0; i < k; i++)
  {
    double m = (l + r) / 2;
    (m * m + sqrt(m) <= c) ? l = m : r = m;
  }
  cout << fixed << setprecision(15);
  cout << l << endl;
  return 0;
}