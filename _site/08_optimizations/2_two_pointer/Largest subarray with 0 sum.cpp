#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

// Function to find the length of the
// largest subarray with sum 0
int maxLen(vector<int> &arr)
{

  int n = arr.size();

  // Initialize the result
  int max_len = 0;

  // Loop through each starting point
  for (int i = 0; i < n; i++)
  {

    // Initialize the current sum for
    // this starting point
    int curr_sum = 0;

    // Try all subarrays starting from 'i'
    for (int j = i; j < n; j++)
    {

      // Add the current element to curr_sum
      curr_sum += arr[j];

      // If curr_sum becomes 0, update max_len if required
      if (curr_sum == 0)
        max_len = max(max_len, j - i + 1);
    }
  }
  return max_len;
}

int main()
{
  vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
  cout << maxLen(arr) << endl;
  return 0;
}
