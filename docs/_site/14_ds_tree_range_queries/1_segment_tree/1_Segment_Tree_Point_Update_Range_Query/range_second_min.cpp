#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

// update => a[pos]=value
/* range query of second min{
vector<pair<int,int>segTree;
pair<int,int>merge(pair<int,int>l,pair<int,int>r){
  if(l.ff<r.first){
    return {l.ff,min(r.ff,l.ss)};
  }else{
    return {r.ff,min(l.ff,r.ss)};
  }
}
}*/

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
  ll val1;
  ll val2;
  Node1()
  {
    val1 = INT_MAX;
    val2 = INT_MAX;
  }

  Node1(ll p1)
  {
    val1 = p1;
    val2 = INT_MAX;
  }

  void merge(Node1 &l, Node1 &r)
  {
    vector<ll> vals = {l.val1, l.val2, r.val1, r.val2};
    sort(all(vals));
    val1 = vals[0];
    val2 = vals[1];
  }

  // void merge(Node1 &l, Node1 &r)
  // {
  //   // Set the smallest value to val1
  //   if (l.val1 < r.val1)
  //   {
  //     val1 = l.val1;
  //     val2 = min(l.val2, r.val1); // second smallest
  //   }
  //   else
  //   {
  //     val1 = r.val1;
  //     val2 = min(r.val2, l.val1); // second smallest
  //   }

  // Ensure val2 is not equal to val1
  // if (val1 == val2)
  // {
  //   if (l.val2 != val1 && l.val2 != INT_MAX)
  //     val2 = l.val2;
  //   else if (r.val2 != val1 && r.val2 != INT_MAX)
  //     val2 = r.val2;
  // }
  // }
};

struct Update1
{
  ll val;
  Update1(ll p1)
  {
    val = p1;
  }

  void apply(Node1 &a)
  {
    a.val1 = val;
    a.val2 = INT_MAX;
  }
};

int main()
{
  int n = 4;
  vector<ll> arr = {3, 5, 1, 8};

  SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, arr);

  cout << seg.make_query(1, 2).val2 << endl;
  seg.make_update(1, 2);
  cout << seg.make_query(1, 2).val2 << endl;
  return 0;
}