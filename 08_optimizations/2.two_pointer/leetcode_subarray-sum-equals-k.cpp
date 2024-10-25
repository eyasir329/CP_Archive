
// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

/*
    The idea is to store the sum of elements of every prefix of the array in a hashmap, i.e, every index stores the sum of elements up to that index hashmap. So to check if there is a subarray with a sum equal to target_sum, check for every index i, and sum up to that index as curr_sum. If there is a prefix with a sum equal to (curr_sum – target_sum), then the subarray with the given sum is found.
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  int cnt = 0, cur = 0;
  unordered_map<int, int> hashMap; // prefixSumFrequency
  hashMap[0] = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    cur += nums[i];
    cnt += (hashMap[cur - k]);
    hashMap[cur]++;
  }
  return cnt;
}