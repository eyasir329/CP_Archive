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

// static array + range query => prefix sum
// initial array + range update query + final array query => difference array
// dynamic array + range query => segment tree *******

/*Given an array A of N (N<=1e5) elements and Q (Q<=1e5) queries,
In each query, you have to do one of two types of operations.
Operation 1: You will be given two indices L and R, you need to output the sum of values of the array A from index L to R.
Operation 2: You will be given index Pos and a value Val, you have to change the value at index Pos to the value Val. That is set A[Pos]=Val. */

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
  segTree[index] = segTree[left] + segTree[right];
}

void update(vector<int> &arr, int start, int end, int index, int pos, int value)
{
  // O(logn)
  if (start == end)
  {
    arr[pos] = value;
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
  segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
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
  return leftAnswer + rightAnswer;
}

int main()
{
  int n = 4;
  vector<int> arr = {3, 5, 3, 8};

  /*
  if n is power of 2 then => size 2*n-1
  otherwise make it next power of two  .. which is <=2N
  covert n to next power of two <=2n  -> tree size will be (2*(2n)-1) <=4N-1
  */
  segTree.resize(4 * n, -1);
  build(arr, 0, n - 1, 1);
  print(segTree);

  update(arr, 0, n - 1, 1, 2, 7);
  print(segTree);
  print(arr);

  int l = 1, r = 1;
  // we have to make it zero based indexing
  l--;
  r--;
  cout << query(0, n - 1, 1, l, r) << endl;

  return 0;
}