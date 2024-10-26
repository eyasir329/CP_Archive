#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, s;
  cin >> n >> s;

  if (n == 1)
  {
    cout << s << endl;
    return 0;
  }
  int ans = 0;
  int d = min(n, s);
  while (s)
  {
    ans += s / d;
    s = s % d;
    d = min(n, s);
  }
  cout << ans << endl;

  return 0;
}

/*
  int n, s;
  cin >> n >> s;

  cout << (s+n-1)/n << endl;
*/