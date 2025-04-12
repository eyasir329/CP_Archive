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
// range min index query

vector<int> segTree;

// Function to build the segment tree
void build(vector<int> &arr, int start, int end, int index)
{
  if (start == end)
  {
    segTree[index] = start; // Store the index of the element
    return;
  }
  int mid = (start + end) / 2;
  build(arr, start, mid, 2 * index);
  build(arr, mid + 1, end, 2 * index + 1);
  // Store the index with the minimum value between two children
  segTree[index] = (arr[segTree[2 * index]] <= arr[segTree[2 * index + 1]]) ? segTree[2 * index] : segTree[2 * index + 1];
}

// Function to update the segment tree
void update(vector<int> &arr, int start, int end, int index, int pos, int value)
{
  if (start == end)
  {
    arr[pos] += value;
    segTree[index] = start;
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
  segTree[index] = (arr[segTree[2 * index]] <= arr[segTree[2 * index + 1]]) ? segTree[2 * index] : segTree[2 * index + 1];
}

// Function to query the index of the minimum value in a given range
int query(vector<int> &arr, int start, int end, int index, int l, int r)
{
  // Complete overlap
  if (l <= start && r >= end)
  {
    return segTree[index]; // Return the index in the original array
  }
  // Disjoint
  if (l > end || r < start)
  {
    return -1; // Invalid index
  }
  // Partial overlap
  int mid = (start + end) / 2;
  int leftAnswer = query(arr, start, mid, 2 * index, l, r);
  int rightAnswer = query(arr, mid + 1, end, 2 * index + 1, l, r);

  if (leftAnswer == -1)
    return rightAnswer;
  if (rightAnswer == -1)
    return leftAnswer;

  // Return the index with the minimum value in the original array
  return (arr[leftAnswer] <= arr[rightAnswer]) ? leftAnswer : rightAnswer;
}

int main()
{
  int n = 4;
  vector<int> arr = {3, 5, 1, 8};
  segTree.resize(4 * n, -1);
  build(arr, 0, n - 1, 1);

  int l = 1, r = 4;
  l--; // Convert to zero-based indexing
  r--;
  int minIndex = query(arr, 0, n - 1, 1, l, r);
  cout << "Index in the original array: " << minIndex << endl;
  print(arr);
  update(arr, 0, n - 1, 1, 0, -8);
  minIndex = query(arr, 0, n - 1, 1, l, r);
  cout << "Index in the original array after update: " << minIndex << endl;
  print(arr);

  return 0;
}