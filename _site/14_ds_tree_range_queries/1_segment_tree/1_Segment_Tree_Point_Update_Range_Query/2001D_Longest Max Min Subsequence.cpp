// longest subsequence such that it does not contain duplicate
// if multiple then lexicographical min after after multiply -1 in odd position
// that means big value in odd position  ... to become small
// ^v^v^v^ big sm big sm

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

template <typename Node, typename Update>
struct SegTree
{
  vector<Node> tree;
  vector<ll> arr;
  int n;
  int s;

  SegTree(int a_len, vector<ll> &a)
  {
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n)
    {
      s = s << 1;
    }
    tree.resize(s);
    fill(all(tree), Node());
    build(0, n - 1, 1);
  }

  void build(int start, int end, int index)
  {
    if (start == end)
    {
      tree[index] = Node(arr[start], start);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }

  void update(int start, int end, int index, int query_index, Update &u)
  {
    if (start == end)
    {
      u.apply(tree[index]);
      return;
    }
    int mid = (start + end) / 2;
    if (query_index <= mid)
      update(start, mid, 2 * index, query_index, u);
    else
      update(mid + 1, end, 2 * index + 1, query_index, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }

  Node query(int start, int end, int index, int left, int right)
  {
    if (start > right || end < left)
      return Node();
    if (start >= left && end <= right)
      return tree[index];
    int mid = (start + end) / 2;
    Node l = query(start, mid, 2 * index, left, right);
    Node r = query(mid + 1, end, 2 * index + 1, left, right);
    Node ans;
    ans.merge(l, r);
    return ans;
  }

  void make_update(int index, ll val)
  {
    Update new_update(val);
    update(0, n - 1, 1, index, new_update);
  }

  Node make_query(int left, int right)
  {
    return query(0, n - 1, 1, left, right);
  }
};

struct Node1
{
  ll min_val; // Minimum value
  ll max_val; // Maximum value
  ll min_idx; // Index of the minimum value
  ll max_idx; // Index of the maximum value

  Node1()
  {
    min_val = numeric_limits<ll>::max();
    max_val = numeric_limits<ll>::min();
    min_idx = -1;
    max_idx = -1;
  }

  Node1(ll p1, ll p2) : min_val(p1), max_val(p1), min_idx(p2), max_idx(p2) {}

  void merge(Node1 &l, Node1 &r)
  {
    // Update minimum value and its index, considering only non -1 values
    if (l.min_val != -1 && (r.min_val == -1 || l.min_val < r.min_val))
    {
      min_val = l.min_val;
      min_idx = l.min_idx;
    }
    else if (r.min_val != -1 && (l.min_val == -1 || r.min_val < l.min_val))
    {
      min_val = r.min_val;
      min_idx = r.min_idx;
    }
    else if (l.min_val == r.min_val && l.min_val != -1)
    {
      min_val = l.min_val;
      min_idx = min(l.min_idx, r.min_idx); // Prefer the earlier index
    }
    else
    {
      min_val = -1;
      min_idx = -1;
    }

    // Update maximum value and its index, considering only non -1 values
    if (l.max_val != -1 && (r.max_val == -1 || l.max_val > r.max_val))
    {
      max_val = l.max_val;
      max_idx = l.max_idx;
    }
    else if (r.max_val != -1 && (l.max_val == -1 || r.max_val > l.max_val))
    {
      max_val = r.max_val;
      max_idx = r.max_idx;
    }
    else if (l.max_val == r.max_val && l.max_val != -1)
    {
      max_val = l.max_val;
      max_idx = min(l.max_idx, r.max_idx); // Prefer the earlier index
    }
    else
    {
      max_val = -1;
      max_idx = -1;
    }
  }
};

struct Update1
{
  ll val;

  Update1(ll p1) : val(p1) {}

  void apply(Node1 &a)
  {
    if (val != -1)
    {
      a.min_val = val;
      a.max_val = val;
    }
    else
    {
      a.min_val = -1;
      a.max_val = -1;
    }
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (auto &i : arr)
    cin >> i;

  SegTree<Node1, Update1> seg(n, arr);

  vector<int> uniq(n), prefixSum(n + 1), answer;
  map<int, int> mp, vis, occ;
  map<int, vector<int>> mv;

  // Compute the suffix array for unique counts
  for (int i = n - 1; i >= 0; i--)
  {
    if (!occ.count(arr[i]))
      occ[arr[i]] = i;
    mp[arr[i]]++;
    uniq[i] = mp.size();
    mv[arr[i]].push_back(i);
  }

  // main
  for (int i = 0, j = 0, index = 0; index < mp.size(); index++)
  {
    while (j < n)
    {
      if (j && prefixSum[j])
      {
        uniq[j] -= prefixSum[j];
        prefixSum[j + 1] += prefixSum[j];
        prefixSum[j] = 0;
      }
      if (uniq[j] >= mp.size() - index)
        j++;
      else
        break;
    }
    // cout << i << "id" << j - 1 << endl;
    auto result = seg.make_query(i, j - 1);
    if ((index + 1) & 1)
    {
      int mx = result.max_val;
      // cout << mx << " " << result.max_idx << endl;
      // relace all other mx
      for (int indx : mv[mx])
      {
        seg.make_update(indx, -1);
      }
      answer.push_back(mx);
      if (j <= occ[mx])
      {
        prefixSum[j]++;
        prefixSum[occ[mx] + 1]--;
      }
      i = result.max_idx + 1;
    }
    else
    { // Even index
      int mn = result.min_val;
      // cout << mn << " " << result.min_idx << endl;
      // relace all other mn
      for (int indx : mv[mn])
      {
        seg.make_update(indx, -1);
      }
      answer.push_back(mn);
      if (j <= occ[mn])
      {
        prefixSum[j]++;
        prefixSum[occ[mn] + 1]--;
      }
      i = result.min_idx + 1;
    }
  }
  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); i++)
  {
    cout << answer[i] << " ";
  }
  cout << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
