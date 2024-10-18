/*
Given a 1-based indexing array arr[] of integers and an integer sum. You mainly need to return the left and right indexes(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.
*/

#include <bits/stdc++.h>
using namespace std;

// [Naive] Using Nested loop – O(N^2) time and O(1) auxiliary space
vector<int> subarraySum(vector<int> arr, int sum)
{
  vector<int> res;
  int n = arr.size();
  for (int s = 0; s < n; s++)
  {
    int curr = 0;
    for (int e = s; e < n; e++)
    {
      curr += arr[e];
      if (curr == sum)
      {
        res.push_back(s + 1);
        res.push_back(e + 1);
        return res;
      }
    }
  }
  return {-1};
}

// [ Sliding Window - Two Pointer] O(N) time and O(1) auxiliary space
// perfect for a[i]>=0
vector<int> subarraySum2p(vector<int> &arr, int sum)
{
  int s = 0, e = 0;
  vector<int> res;
  int curr = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    curr += arr[i];
    if (curr >= sum)
    {
      e = i;
      while (curr > sum && s < e)
      {
        curr -= arr[s];
        ++s;
      }
      if (curr == sum)
      {
        res.push_back(s + 1);
        res.push_back(e + 1);
        return res;
      }
    }
  }
  return {-1};
}

int main()
{
  int n, k;
  vector<int> a(n);
  return 0;
}