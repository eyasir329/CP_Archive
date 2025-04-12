#include <bits/stdc++.h>
using namespace std;
// greedy solution
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string n;
    int k;
    cin >> n >> k;

    int length = n.length();

    if (k == length) {
      cout << "\n";  // If k equals the length of n, print an empty line
      continue;
    }

    stack<char> st;
    int remaining = length - k;  // The number of digits we need to keep

    // Process each digit
    for (char digit : n) {
      // Remove digits from the stack if the current digit is larger
      // and we still have digits to remove (k > 0)
      while (!st.empty() && st.top() < digit && k > 0) {
        st.pop();
        k--;  // We've removed one digit
      }
      st.push(digit);  // Push the current digit onto the stack
    }

    // We need to pop exactly (remaining) digits from the stack
    string result = "";
    while (st.size() > remaining) {
      st.pop();
    }

    // Collect the remaining digits in the result
    while (!st.empty()) {
      result += st.top();  // Append the top of the stack to the result
      st.pop();
    }

    // Since the digits are stored in reverse order, reverse the string
    reverse(result.begin(), result.end());

    cout << result << endl;
  }

  return 0;
}