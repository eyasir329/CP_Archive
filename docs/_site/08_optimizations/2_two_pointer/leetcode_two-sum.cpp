#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> ans;
  vector<pair<int, int>> vp;
  for (int i = 0; i < nums.size(); i++)
  {
    vp.push_back({nums[i], i});
  }
  sort(vp.begin(), vp.end());
  int left = 0, right = nums.size() - 1;
  while (left < right)
  {
    if (vp[left].first + vp[right].first == target)
    {
      ans.push_back(vp[left].second);
      ans.push_back(vp[right].second);
      return ans;
    }
    else if (vp[left].first + vp[right].first < target)
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  return ans;
}