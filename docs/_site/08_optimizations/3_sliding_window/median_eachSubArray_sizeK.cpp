#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

// we need pbds instead of set. for accessing mid in logN time.
// convert set to multiset for using pair
// for access median we need pbds

vector<int> medianEachSubArray(vector<int> nums, int k)
{
  int n = nums.size();
  PBDS st;
  vector<int> ans;
  for (int i = 0; i < k; i++)
  {
    st.insert({nums[i], i});
  }
  ans.push_back((*st.find_by_order(k / 2)).first);
  for (int i = 1; i <= n - k; i++)
  {
    st.insert({nums[i + k - 1], i + k - 1});
    st.erase({nums[i - 1], i - 1});
    ans.push_back((*st.find_by_order(k / 2)).first);
  }
  return ans;
}

int32_t main()
{

  return 0;
}