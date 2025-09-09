// C++ program to find all combinations
// of a string in lexicographical order
// https://www.geeksforgeeks.org/print-all-the-combinations-of-a-string-in-lexicographical-order/
#include <bits/stdc++.h>
using namespace std;

// function to print string
void printResult(char* result, int len) {
  for (int i = 0; i <= len; i++) cout << result[i];
  cout << endl;
}

// Method to found all combination
// of string it is based in tree
void stringCombination(char result[], char str[], int count[], int level,
                       int size, int length) {
  // return if level is equal size of string
  if (level == size) return;

  for (int i = 0; i < length; i++) {
    // if occurrence of char is 0 then
    // skip the iteration of loop
    if (count[i] == 0) continue;

    // decrease the char occurrence by 1
    count[i]--;

    // store the char in result
    result[level] = str[i];

    // print the string till level
    printResult(result, level);

    // call the function from level +1
    stringCombination(result, str, count, level + 1, size, length);

    // backtracking
    count[i]++;
  }
}

void combination(string str) {
  // declare the map for store
  // each char with occurrence
  map<char, int> mp;

  for (int i = 0; i < str.size(); i++) {
    if (mp.find(str[i]) != mp.end())
      mp[str[i]] = mp[str[i]] + 1;
    else
      mp[str[i]] = 1;
  }

  // initialize the input array
  // with all unique char
  char* input = new char[mp.size()];

  // initialize the count array with
  // occurrence the unique char
  int* count = new int[mp.size()];

  // temporary char array for store the result
  char* result = new char[str.size()];

  map<char, int>::iterator it = mp.begin();
  int i = 0;

  for (it; it != mp.end(); it++) {
    // store the element of input array
    input[i] = it->first;

    // store the element of count array
    count[i] = it->second;
    i++;
  }

  // size of map(no of unique char)
  int length = mp.size();

  // size of original string
  int size = str.size();

  // call function for print string combination
  stringCombination(result, input, count, 0, size, length);
}

// Driver code
int main() {
  string str = "ABC";

  combination(str);

  return 0;
}
