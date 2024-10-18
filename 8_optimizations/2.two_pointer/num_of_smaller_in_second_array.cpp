// adhoc
/*
  ->Binary Search O(NlogN)
  ->Two pointer O(N+M)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  vector<int> a(n), b(m);
  vector<int> ans(n);

  int i = 0, j = 0;

  while (i < n)
  {
    while (j < m and b[j] < a[i])
    {
      j++;
    }
    ans[i] = j;
    i++;
  }
  return 0;
}