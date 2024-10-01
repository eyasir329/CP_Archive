#include <bits/stdc++.h>
using namespace std;

void firstNegNum(vector<int> nums, int k)
{
  int n = nums.size();
  queue<int> q;
  for (int i = 0; i < k; i++)
  {
    if (nums[i] < 0)
    {
      q.push(i);
    }
  }
  cout << q.front() << " ";
  // O(K+(N-K))<->O(N)
  for (int i = 1; i <= n - k; i++)
  {
    if (nums[i + k - 1] < 0)
    {
      q.push((i + k - 1));
    }
    if (q.front() == i - 1)
    {
      q.pop();
    }
    cout << q.front() << " ";
  }
}

int32_t main()
{

  return 0;
}