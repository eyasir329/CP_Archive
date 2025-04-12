// find the largest substring with
// non-repeating characters using Sliding Window

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string &s)
{

  // if string length is 0
  if (s.length() == 0)
    return 0;

  // if string length 1
  if (s.length() == 1)
    return 1;

  // if string length is more than 1
  int maxLength = 0;
  vector<bool> visited(256, false);

  // left and right pointer of sliding window
  int left = 0, right = 0;
  while (right < s.length())
  {

    // If the character is repeated, move left pointer
    // to the right and mark visited characters as false
    // until the repeating character is no longer part
    // of the current window.
    while (visited[s[right]] == true)
    {

      visited[s[left]] = false;
      left++;
    }

    visited[s[right]] = true;

    // The length of the current window (right - left + 1)
    // is calculated and answer is updated accordingly.
    maxLength = max(maxLength, (right - left + 1));
    right++;
  }
  return maxLength;
}

int main()
{
  string s = "geeksforgeeks";
  cout << longestUniqueSubstr(s);
  return 0;
}
