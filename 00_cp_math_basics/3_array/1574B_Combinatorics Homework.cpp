
#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1574/problem/B
void solve()
{
  int a, b, c;

  std::vector<int> v = {a, b, c};
  sort(v.begin(), v.end());
  a = v[0], b = v[1], c = v[2];
  int max_adj_pair = (a - 1 + b - 1 + c - 1); // (n*(n+1)/2)-n
  b -= a;
  c -= b;
  int min_adj_pair = max((c - 2 * a) - 1, 0); // max(0,max_value - (sum of other_value+1))
  // n-((n-1 * (n-1+1))/2 +1)
  // n - ((n*(n-1))/2 +1)
  // n-(n*n-1)/2-1
}
