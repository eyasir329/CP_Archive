// (a|b)-(a&c)=d //find a // not possible print -1
// solve these bit by bit

#include <bits/stdc++.h>
using namespace std;
#define int long long
map<tuple<int, int, int>, int> m;

void solve()
{
  int b, c, d;
  cin >> b >> c >> d;
  int a = 0;
  for (int i = 60; i >= 0; i--)
  {
    int x = ((1LL << i) & b) != 0;
    int y = ((1LL << i) & c) != 0;
    int z = ((1LL << i) & d) != 0;
    int canBe = m[{x, y, z}];
    if (canBe == -1)
    {
      a = -1;
      break;
    }
    else
    {
      a += canBe * (1LL << i);
    }
  }
  cout << a << endl;
}
// void solve()
// {
//   int b, c, d;
//   cin >> b >> c >> d;
//   int a = (d|b)-(d&c);
//   if((a|b)-(a&c)==d){
//     cout<<a<<endl;
//   }else{
//     cout<<-1<<endl;
//   }
// }

int32_t main()
{
  m[{0, 0, 0}] = 0;
  m[{0, 0, 1}] = 1;
  m[{0, 1, 0}] = 0;
  m[{0, 1, 1}] = -1;
  m[{1, 0, 0}] = -1;
  m[{1, 0, 1}] = 0;
  m[{1, 1, 0}] = 1;
  m[{1, 1, 1}] = 0;
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