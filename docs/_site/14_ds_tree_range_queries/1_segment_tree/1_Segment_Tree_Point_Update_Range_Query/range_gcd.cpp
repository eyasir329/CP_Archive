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

/*  Range GCD: For querying range GCD, we will store the GCD of its two children in the corresponding node. Similarly we will take GCD of its two children when updating and querying */

// update -> gcd(current,value)
// range xor

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
  segTree[index] = (segTree[left] ^ segTree[right]);
}

void update(vector<int> &arr, int start, int end, int index, int pos, int value)
{
  // O(logn)
  if (start == end)
  {
    arr[pos] = gcd(arr[pos], value);
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
  segTree[index] = (segTree[2 * index] ^ segTree[2 * index + 1]);
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
    return 0;
  }
  // partial overlap
  int mid = (start + end) / 2;
  int leftAnswer = query(start, mid, 2 * index, l, r);
  int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
  return (leftAnswer ^ rightAnswer);
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