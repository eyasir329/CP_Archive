#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
  int n;
  cin >> n;
  while (n % 2 == 0)
    n /= 2;
  if (n != 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
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