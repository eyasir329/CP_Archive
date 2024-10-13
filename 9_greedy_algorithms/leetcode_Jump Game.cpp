#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canJump(vector<int> &nums)
{
  int n = nums.size();
  int max_jump = nums[0];
  for (int i = 1; i < n; i++)
  {
    if (i <= max_jump)
    {
      max_jump = max(max_jump, i + nums[i]);
    }
    else
    {
      return false;
    }
  }
  if (max_jump >= n - 1)
  {
    return true;
  }
  return false;
}

void solve()
{
  vector<int> nums = {0};
  cout << canJump(nums) << endl;
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