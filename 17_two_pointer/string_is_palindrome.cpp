#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
  int left = 0;                 // Initialize left pointer
  int right = str.length() - 1; // Initialize right pointer

  while (left < right)
  {
    // Skip non-alphanumeric characters (optional)
    while (left < right && !isalnum(str[left]))
      left++;
    while (left < right && !isalnum(str[right]))
      right--;

    // Compare characters
    if (tolower(str[left]) != tolower(str[right]))
    {
      return false; // If they don't match, it's not a palindrome
    }

    // Move the pointers towards each other
    left++;
    right--;
  }

  return true; // If no mismatches, it's a palindrome
}

int main()
{
  string str;
  cout << "Enter a string: ";
  getline(cin, str);

  if (isPalindrome(str))
  {
    cout << "The string is a palindrome." << endl;
  }
  else
  {
    cout << "The string is not a palindrome." << endl;
  }

  return 0;
}
