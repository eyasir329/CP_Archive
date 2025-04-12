#include <bits/stdc++.h>
using namespace std;

// 1506C_Double-ended Strings
void solve()
{
  string a, b;
  cin >> a >> b;

  // 1st way: general way to find max common substr
  // find all sub array from both then compare and find biggest
  set<string> va, vb;
  // using subarray method
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = i; j < a.size(); j++)
    {
      string s = "";
      for (int k = i; k <= j; k++)
      {
        s += a[k];
      }
      va.insert(s);
    }
  }
  for (int i = 0; i < b.size(); i++)
  {
    for (int j = i; j < b.size(); j++)
    {
      string s = "";
      for (int k = i; k <= j; k++)
      {
        s += b[k];
      }
      vb.insert(s);
    }
  }
  int cnt = 0;
  for (auto s1 : va)
  {
    for (auto s2 : vb)
    {
      if (s1 == s2)
      {
        cnt = max(cnt, (int)s1.size());
      }
    }
  }
  int ans = 0;
  ans += (a.size() - cnt);
  ans += (b.size() - cnt);
  cout << ans << endl; // n+m-2*r

  // 2nd way
  // optimum way
  int r = 0, n = a.size(), m = b.size();
  for (int len = 1; len <= n; len++)
    for (int i = 0; i + len - 1 < n; i++)
      if (b.find(a.substr(i, len)) != string::npos)
        r = max(len, r);
  cout << n + m - r * 2 << endl;
}