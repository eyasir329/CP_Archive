/*
q<=1e6
each query do one thing
- add x
- remove x

then print number of unique element
*/

// if use multiset then we can't find unique element in easy way

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;
  map<int, int> mp;
  while (q--)
  {
    string ty;
    int x;
    cin >> ty >> x;
    if (ty == "add")
    {
      mp[x]++;
    }
    else
    {
      if (mp.find(x) != mp.end())
      {
        mp[x]--;
      }
      if (mp[x] == 0)
      {
        mp.erase(x);
      }
    }
    cout << mp.size() << endl;
  }
  return 0;
}