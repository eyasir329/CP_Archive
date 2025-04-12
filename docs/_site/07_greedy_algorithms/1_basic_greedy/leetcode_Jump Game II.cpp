#include <bits/stdc++.h>
using namespace std;
#define int long long

int jump(vector<int> &nums)
{
  int prev = 0;
  int farthest = nums[0];
  int ans = 1;
  while (farthest < nums.size() - 1)
  {
    int max_jump = -1;
    for (int i = prev + 1; i <= farthest; i++)
    {
      max_jump = max(max_jump, nums[i] + i);
    }
    prev = farthest;
    farthest = max_jump;
    ans++;
  }
  return nums.size() == 1 ? 0 : ans;
}

void solve()
{
  vector<int> nums = {1, 2, 3, 1, 1};
  cout << jump(nums) << endl;
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