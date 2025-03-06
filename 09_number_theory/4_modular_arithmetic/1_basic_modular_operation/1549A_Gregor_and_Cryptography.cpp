#include <bits/stdc++.h>
using namespace std;
#define int long long

// p mod a = p mod b
// even%2=0 odd%2=1

void solve()
{
  int p;
  cin >> p;
  if (p & 1)
  {
    cout << 2 << " " << p - 1 << endl; // p%(p-1)=1
  }
  else
  {
    cout << 2 << " " << p << endl;
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