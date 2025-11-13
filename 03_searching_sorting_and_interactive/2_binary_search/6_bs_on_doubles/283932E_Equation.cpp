#include <bits/stdc++.h>
using namespace std;

double c;
bool f(double x)
{
  return (x * x + sqrt(x)) >= c;
}

int32_t main()
{
  cin >> c;
  double l = 0, r = 1e5; // r = 10^11*10^-6
  while (r - l >= 1e-7)
  {
    double mid = (l + r) / 2;
    if (f(mid))
    {
      r = mid;
    }
    else
    {
      l = mid;
    }
  }
  cout << fixed << setprecision(10) << r << endl;
  return 0;
}