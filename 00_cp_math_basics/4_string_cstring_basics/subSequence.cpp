#include <bits/stdc++.h>
using namespace std;

// sub-sequence -> without changing order
// total number of subsequence 2^n

// naive O(2^N)
// Pick and Don’t Pick Concept
// Find all subsequences
void printSubsequence(string input, string output) {
  // Base Case
  // if the input is empty print the output string
  if (input.empty()) {
    cout << output << endl;
    return;
  }

  // output is passed with including
  // the Ist character of
  // Input string
  printSubsequence(input.substr(1), output + input[0]);

  // output is passed without
  // including the Ist character
  // of Input string
  printSubsequence(input.substr(1), output);
}

// Driver code
int main() {
  // output is set to null before passing in as a
  // parameter
  string output = "";
  string input = "abcd";

  printSubsequence(input, output);

  return 0;
}
