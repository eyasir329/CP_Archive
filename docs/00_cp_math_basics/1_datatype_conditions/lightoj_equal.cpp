#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ull t;
  cin >> t;
  while (t--)
  {
    ull a, b, c, d;
    cin >> a >> b >> c >> d;
    __int128_t aa = a, bb = b, cc = c, dd = d;

    if (aa * dd == cc * bb)
      cout << "Equal\n";
    else
      cout << "Not Equal\n";
  }
}
