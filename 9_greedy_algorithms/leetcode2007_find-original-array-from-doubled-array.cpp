#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> &changed)
{
  int n = changed.size();
  vector<int> res;
  if (n & 1)
  {
    return res;
  }
  sort(changed.begin(), changed.end());
  unordered_map<int, int> mp;
  for (auto x : changed)
  {
    mp[x]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (mp[changed[i]] == 0)
    {
      continue;
    }
    int doubled = changed[i] * 2;
    if (mp[doubled])
    {
      res.push_back(changed[i]);
      mp[changed[i]]--;
      mp[doubled]--;
    }
    else
    {
      vector<int> temp;
      return temp;
    }
  }
  return res;
}

int main()
{
  vector<int> changed = {0, 0, 0, 0}, res;
  res = findOriginalArray(changed);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}