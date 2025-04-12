#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

template <typename Node, typename Update>
struct SegTree
{
  vector<Node> tree;
  vector<ll> arr; // Change type here if necessary
  int n;
  int s;
  SegTree(int a_len, vector<ll> &a)
  { // Change if type updated
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
  { // Never change this
    if (start == end)
    {
      tree[index] = Node(arr[start]);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  void update(int start, int end, int index, int query_index, Update &u)
  { // Never Change this
    if (start == end)
    {
      u.apply(tree[index]);
      return;
    }
    int mid = (start + end) / 2;
    if (mid >= query_index)
      update(start, mid, 2 * index, query_index, u);
    else
      update(mid + 1, end, 2 * index + 1, query_index, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  Node query(int start, int end, int index, int left, int right)
  { // Never change this
    if (start > right || end < left)
      return Node();
    if (start >= left && end <= right)
      return tree[index];
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans.merge(l, r);
    return ans;
  }
  void make_update(int index, ll val)
  {                                  // Pass in as many parameters as required
    Update new_update = Update(val); // May change
    update(0, n - 1, 1, index, new_update);
  }
  Node make_query(int left, int right)
  {
    return query(0, n - 1, 1, left, right);
  }
};

struct Node1
{
  ll val; // May change
  Node1()
  {          // Identity element
    val = 0; // May change
  }
  Node1(ll p1)
  {           // Actual Node
    val = p1; // May change
  }
  void merge(Node1 &l, Node1 &r)
  {                      // Merge two child nodes
    val = l.val + r.val; // May change
  }
};

struct Update1
{
  ll val; // May change
  Update1(ll p1)
  {           // Actual Update
    val = p1; // May change
  }
  void apply(Node1 &a)
  {              // Apply update to given node
    a.val = val; // May change
  }
};

int main()
{
  int n = 4;
  vector<ll> arr = {3, 5, 1, 8};

  SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, arr);

  cout << seg.make_query(1, 2).val << endl;
  seg.make_update(1, 2);
  cout << seg.make_query(1, 2).val << endl;
  return 0;
}
