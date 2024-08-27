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