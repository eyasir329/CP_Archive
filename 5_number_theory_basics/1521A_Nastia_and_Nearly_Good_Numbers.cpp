
#include <bits/stdc++.h>
using namespace std;
#define int long long

// need three int x,y,z such that one is exactly divided by "ab" and other two is divided by "a"

void solve()
{
  int a, b;
  cin >> a >> b;
  if (b == 1)
  {
    cout << "NO" << endl;
  }
  else if (b == 2)
  {
    cout << "YES" << endl;
    cout << a << " " << 3 * a << " " << 4 * a << endl;
  }
  else
  {
    cout << "YES" << endl;
    cout << a << " " << (b - 1) * a << " " << a * b << endl;
  }
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}