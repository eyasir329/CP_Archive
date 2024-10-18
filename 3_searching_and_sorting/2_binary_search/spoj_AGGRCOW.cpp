#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, c;

bool canWePlace(vector<int> arr, int dis)
{
  int cow = 1, lastDist = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] - lastDist >= dis)
    {
      cow++;
      lastDist = arr[i];
    }
  }
  if (cow >= c)
    return true;
  return false;
}

void solve()
{
  cin >> n >> c;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int ans = 0;
  // 0(n*n)-->0(nlog(n))
  // for(int i=1;i<=(v.back()-v[0]);i++){
  //   if(canWePlace(v,i)){
  //     ans = i;
  //   }else{
  //     break;
  //   }
  // }
  int l = 1, r = (v.back() - v[0]);
  while (l < r)
  {
    int m = (l + r) / 2;
    if (canWePlace(v, m))
    {
      ans = m;
      l = m + 1;
    }
    else
    {
      r = m;
    }
  }
  cout << ans << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}