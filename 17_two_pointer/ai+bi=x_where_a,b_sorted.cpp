#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a(n), b(m);
int x;

void BSTechnique() // O(NlogN)
{
  // if b is monotonic
  for (int i = 0; i < n; i++)
  {
    int rem = x - a[i];
    int l = -1, r = m;
    while (r - l > 1)
    {
      int mid = (l + r) / 2;
      if (b[mid] <= rem) // if(b[mid]<rem)l=mid else r=mid //then ans in r
      {
        l = mid;
      }
      else
      {
        r = mid;
      }
    }
    if (l != -1 and b[l] == x)
    {
      cout << i << " " << l << endl;
      return;
    }
  }
}

void twoPointerTechnique() // O(N+M)
{
  for (int i = 0, j = m - 1; i < n; i++) // O(N)
  {
    int rem = x - a[i];
    while (j >= 0 and b[j] > rem) // O(M) in total
    {
      j--;
    }
    if (j >= 0 and b[j] == rem)
    {
      cout << i << " " << j << endl;
      return;
    }
  }
}

int main()
{
  return 0;
}