#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
  int left = 0;         // Initialize left pointer
  int right = size - 1; // Initialize right pointer

  while (left < right)
  {
    // Swap elements at left and right pointers
    swap(arr[left], arr[right]);

    // Move the pointers towards each other
    left++;
    right--;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  reverseArray(arr, size);

  cout << "Reversed array: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
