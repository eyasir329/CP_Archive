#include <bits/stdc++.h>
using namespace std;
#define int long long

// type1
/*
int maxSubarraySumCircular(vector<int> &a)
{
  int n = a.size();
  // Corner Case
  if (n == 1)
    return a[0];

  // Initialize sum variable which store total sum of the array.
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
  }

  // Initialize every variable with first value of array.
  int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];

  // Concept of Kadane's Algorithm
  for (int i = 1; i < n; i++)
  {
    // Kadane's Algorithm to find Maximum subarray sum.
    curr_max = max(curr_max + a[i], a[i]);
    max_so_far = max(max_so_far, curr_max);

    // Kadane's Algorithm to find Minimum subarray sum.
    curr_min = min(curr_min + a[i], a[i]);
    min_so_far = min(min_so_far, curr_min);
  }

  if (min_so_far == sum)
    return max_so_far;

  // returning the maximum value
  return max(max_so_far, sum - min_so_far);
}
*/

// type2
int maxSubarraySumCircular(vector<int> &nums)
{
  int n = nums.size();
  int cur_sum = 0, min_sum = INT_MAX;
  int total_sum = 0;
  for (int i = 0; i < n; i++)
  {
    total_sum += nums[i];
  }
  for (int i = 0; i < n; i++)
  {
    cur_sum += nums[i];
    min_sum = min(min_sum, cur_sum);
    if (cur_sum > 0)
    {
      cur_sum = 0;
    }
  }
  cur_sum = 0;
  int max_sum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    cur_sum += nums[i];
    max_sum = max(max_sum, cur_sum);
    if (cur_sum < 0)
    {
      cur_sum = 0;
    }
  }
  // if all nums is -ve // then tot-min = 0
  if (max_sum < 0)
  {
    return max_sum;
  }
  return max(total_sum - min_sum, max_sum);
}

void solve()
{
  vector<int> nums = {-9, 14, 24, -14, 12, 18, -18, -10, -10, -23, -2, -23, 11, 12, 18, -9, 9, -29, 12, 4, -8, 15, 11, -12, -16, -9, 19, -12, 22, 16};
  cout << maxSubarraySumCircular(nums) << endl;
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