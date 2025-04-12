#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    int x;
    cin >> x;
    // gcd(a,b)+lcm(a,b)=x
    cout << 1 << " " << x - 1 << endl;
  }

  return 0;
}