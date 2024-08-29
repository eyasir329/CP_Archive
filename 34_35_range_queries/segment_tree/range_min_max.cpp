#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

/* Range minimum/maximum: For querying range minimum/maximum, we will store the minimum/maximum of its two children in the corresponding node. Similarly we will take minimum/maximum of its two children when updating and querying. */

// update -> current+=value
// range min query

vector<int> segTree;

void build(vector<int> &arr, int start, int end, int index)
{
  // build => o(n)
  if (start == end)
  {
    segTree[index] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  int left = 2 * index, right = 2 * index + 1;
  build(arr, start, mid, left);
  build(arr, mid + 1, end, right);
  segTree[index] = min(segTree[left], segTree[right]);
}

void update(vector<int> &arr, int start, int end, int index, int pos, int value)
{
  // O(logn)
  if (start == end)
  {
    arr[pos] += value;
    segTree[index] = arr[pos];
    return;
  }
  int mid = (start + end) / 2;
  if (pos <= mid)
  {
    update(arr, start, mid, 2 * index, pos, value);
  }
  else
  {
    update(arr, mid + 1, end, 2 * index + 1, pos, value);
  }
  segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
}

int query(int start, int end, int index, int l, int r)
{
  // O(logn)
  // sum from l->r
  // complete overlap
  // l... start ... end ... r
  if (l <= start and r >= end)
  {
    return segTree[index];
  }
  // disjoint
  if (l > end or r < start)
  {
    return INT_MAX;
  }
  // partial overlap
  int mid = (start + end) / 2;
  int leftAnswer = query(start, mid, 2 * index, l, r);
  int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
  return min(leftAnswer, rightAnswer);
}

/*min max with index
struct Node1 {
    ll min_val;    // Minimum value
    ll max_val;    // Maximum value
    ll min_idx;    // Index of the minimum value
    ll max_idx;    // Index of the maximum value

    Node1() {
        min_val = LLONG_MAX;
        max_val = LLONG_MIN;
        min_idx = -1;
        max_idx = -1;
    }

    Node1(ll p1, ll p2) : min_val(p1), max_val(p1), min_idx(p2), max_idx(p2) {}

    void merge(Node1 &l, Node1 &r) {
        // Update minimum value and its index
        if (l.min_val < r.min_val) {
            min_val = l.min_val;
            min_idx = l.min_idx;
        } else if (l.min_val > r.min_val) {
            min_val = r.min_val;
            min_idx = r.min_idx;
        } else {
            min_val = l.min_val;
            min_idx = min(l.min_idx, r.min_idx);
        }

        // Update maximum value and its index
        if (l.max_val > r.max_val) {
            max_val = l.max_val;
            max_idx = l.max_idx;
        } else if (l.max_val < r.max_val) {
            max_val = r.max_val;
            max_idx = r.max_idx;
        } else {
            max_val = l.max_val;
            max_idx = max(l.max_idx, r.max_idx);
        }
    }
};

struct Update1 {
    ll val;

    Update1(ll p1) : val(p1) {}

    void apply(Node1 &a) {
        a.min_val = val;
        a.max_val = val;
        // We don't manage indices directly in this update.
    }
};

*/

/* min max both
struct Node1 {
  ll val1;  // Minimum value
  ll val2;  // Maximum value

  Node1() {
    val1 = LLONG_MAX;
    val2 = LLONG_MIN;
  }

  Node1(ll p1) {
    val1 = p1;
    val2 = p1;  // In a single element range, both are the same
  }

  void merge(Node1 &l, Node1 &r) {
    // When merging, only consider valid values
    vector<ll> vals;
    if (l.val1 != LLONG_MAX) vals.push_back(l.val1);
    if (l.val2 != LLONG_MIN) vals.push_back(l.val2);
    if (r.val1 != LLONG_MAX) vals.push_back(r.val1);
    if (r.val2 != LLONG_MIN) vals.push_back(r.val2);

    // Sort only the valid values
    sort(all(vals));

    // If we have valid values, set val1 and val2
    if (!vals.empty()) {
      val1 = vals.front();  // Minimum value
      val2 = vals.back();   // Maximum value
    } else {
      // If no valid values, this node should not influence the segment tree
      val1 = LLONG_MAX;
      val2 = LLONG_MIN;
    }
  }
};

struct Update1 {
  ll val;

  Update1(ll p1) {
    val = p1;
  }

  void apply(Node1 &a) {
    a.val1 = val;
    a.val2 = val;  // When applying an update, both min and max should be the same
  }
};
*/

int main()
{
  int n = 4;
  vector<int> arr = {3, 5, 1, 8};
  segTree.resize(4 * n, -1);
  build(arr, 0, n - 1, 1);
  print(segTree);

  int l = 1, r = 4;
  // we have to make it zero based indexing
  l--;
  r--;
  cout << query(0, n - 1, 1, l, r) << endl;

  update(arr, 0, n - 1, 1, 2, 7);
  print(segTree);
  print(arr);
  cout << query(0, n - 1, 1, l, r) << endl;

  return 0;
}

// struct Node1 {
//     ll min_val;    // Minimum value
//     ll max_val;    // Maximum value
//     ll min_idx;    // Index of the minimum value
//     ll max_idx;    // Index of the maximum value

//     Node1() {
//         min_val = numeric_limits<ll>::max();
//         max_val = numeric_limits<ll>::min();
//         min_idx = -1;
//         max_idx = -1;
//     }

//     Node1(ll p1, ll p2) : min_val(p1), max_val(p1), min_idx(p2), max_idx(p2) {}

//     void merge(Node1 &l, Node1 &r) {
//         // Update minimum value and its index, considering only non -1 values
//         if (l.min_val != -1 && (r.min_val == -1 || l.min_val < r.min_val)) {
//             min_val = l.min_val;
//             min_idx = l.min_idx;
//         } else if (r.min_val != -1 && (l.min_val == -1 || r.min_val < l.min_val)) {
//             min_val = r.min_val;
//             min_idx = r.min_idx;
//         } else if (l.min_val == r.min_val && l.min_val != -1) {
//             min_val = l.min_val;
//             min_idx = min(l.min_idx, r.min_idx);  // Prefer the earlier index
//         } else {
//             min_val = -1;
//             min_idx = -1;
//         }

//         // Update maximum value and its index, considering only non -1 values
//         if (l.max_val != -1 && (r.max_val == -1 || l.max_val > r.max_val)) {
//             max_val = l.max_val;
//             max_idx = l.max_idx;
//         } else if (r.max_val != -1 && (l.max_val == -1 || r.max_val > l.max_val)) {
//             max_val = r.max_val;
//             max_idx = r.max_idx;
//         } else if (l.max_val == r.max_val && l.max_val != -1) {
//             max_val = l.max_val;
//             max_idx = min(l.max_idx, r.max_idx);  // Prefer the earlier index
//         } else {
//             max_val = -1;
//             max_idx = -1;
//         }
//     }
// };

// struct Update1 {
//     ll val;

//     Update1(ll p1) : val(p1) {}

//     void apply(Node1 &a) {
//         if (val != -1) {
//             a.min_val = val;
//             a.max_val = val;
//         } else {
//             a.min_val = -1;
//             a.max_val = -1;
//         }
//     }
// };