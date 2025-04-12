#include <bits/stdc++.h>
using namespace std;
#define int long long

// if my ans is floating value then it can't work

// otherwise it work // in int value
// less than min is always true, greater than max is always false

int bs(vector<int> arr, int k)
{
  int l = -1;             // min-1
  int r = arr.size() + 1; // max+1
  auto pred = [&](int m) -> bool
  {
    // return m<=k; //last occurence of k // ans = l
    // return m<k;  //first occurence of k // ans = r
  };
  while (r - l > 1)
  {
    int m = (l + r) / 2;
    if (pred(m))
    {
      l = m; // l is always last true
    }
    else
    {
      r = m; // r is always first false
    }
  }
}

void solve()
{
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}