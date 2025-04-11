// https://codeforces.com/contest/1506/problem/C

#include <bits/stdc++.h>
using namespace std;

void subString(string s, int n) // O(n*n)
{
  for (int len = 1; len <= n; len++)
  {
    for (int i = 0; i + len - 1 < n; i++)
    {
      string sub = s.substr(i, len);
      cout << sub << endl;
    }
    cout << endl;
  }
}