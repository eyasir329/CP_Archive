// good segment technique (increasing)

// have to be contiguous

// using two pointer O(2N)<->O(N)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  vector<int> a(n);
  int ans = 0, sum = 0;

  int i = 0, j = 0;
  map<int, int> freq;

  while (j < n)
  {
    freq[a[j]]++;                      // include the jth element
    while (i <= j and freq.size() > k) // move left pointer one step right
    {
      freq[a[i]]--; // removing a[i]
      if (freq[a[i]] == 0)
      {
        freq.erase(a[i]);
      }
      i++;
    }
    if (freq.size() <= k)
    {
      ans = max(ans, j - i + 1);
    }
    j++; // move right pointer one step right
  }
  return 0;
}