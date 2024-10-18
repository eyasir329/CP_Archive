#include <bits/stdc++.h>
using namespace std;

int maxSumOfSizeK(vector<int> nums, int k)
{
  int n = nums.size();
  int cur_sum = 0;
  int max_sum = INT_MIN;
  for (int i = 0; i < k; i++)
  {
    cur_sum += nums[i];
  }
  max_sum = cur_sum;
  // O(K+(N-K))<->O(N)
  for (int i = 1; i <= n - k; i++)
  {
    cur_sum += nums[i + k - 1] - nums[i - 1];
    max_sum = max(max_sum, cur_sum);
  }
  return max_sum;
}

int32_t main()
{

  return 0;
}