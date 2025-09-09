#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
  int n = a.size(), m = b.size();
  for (int i = 0; i < min(n, m); i++)
  {
    if (a[i] < b[i])
    {
      return true;
    }
    else if (a[i] > b[i])
    {
      return false;
    }
  }
  return n < m;
}