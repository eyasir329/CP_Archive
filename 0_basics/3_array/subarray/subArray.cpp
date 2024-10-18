#include <bits/stdc++.h>
using namespace std;

// has to be contiguous
// total subarray size n*(n+1)/2
void subArray(int arr[], int n) // O(n*n*n)
{
  // Pick starting point
  for (int i = 0; i < n; i++)
  {
    // Pick ending point
    for (int j = i; j < n; j++)
    {
      // Print subarray between current starting and ending points
      for (int k = i; k <= j; k++)
      {
        cout << arr[k] << " ";
      }
      cout << endl;
    }
  }
}

// https://codeforces.com/contest/1506/problem/C

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