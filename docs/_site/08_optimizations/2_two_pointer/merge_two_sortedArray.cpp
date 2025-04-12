// Adhoc

/*
  -> Add all element in the array and sort it
  -> Using Two pointer O(N+M)
*/

// Merge Sort O(NlogN) ...(best/avg/worst)
// Quick Sort best O(N)...avg O(NlogN)...worst O(N*N)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  vector<int> a(n), b(m);
  vector<int> c(n + m);

  int i = 0, j = 0, k = 0;

  while (i < n and j < m)
  {
    if (a[i] < b[j])
    {
      c[k++] = a[i++];
    }
    else
    {
      c[k++] = b[j++];
    }
  }

  while (i < n)
  {
    c[k++] = a[i++];
  }
  while (j < m)
  {
    c[k++] = b[j++];
  }

  return 0;
}