#include <bits/stdc++.h>
using namespace std;

string query(int i)
{
  cout << i << endl;
  string s;
  cin >> s;
  return s;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  int l = 1, r = 1e6, ans = -1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    string s = query(mid);
    if (s == ">=")
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << "! " << ans << endl;
  return 0;
}
