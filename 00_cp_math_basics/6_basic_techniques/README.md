### Balanced Bracket

example:

- [1860A_Not a Substring]()

---

### Permutation (basic)

<pre>
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).
</pre>

example:

- https://codeforces.com/contest/2071/problem/B

- [1828B_Permutation_Swap](1828B_Permutation_Swap.cpp)
- https://codeforces.com/problemset/problem/1608/B

---

### Palindrome

<pre>
A string is a palindrome if it is the same from the left to the right and from the right to the left. For example, the strings 'kek', 'abacaba', 'r' and 'papicipap' are palindromes, while the strings 'abb' and 'iq' are not.
</pre>

```cpp
//By Comparing with Reversed String
void isPalindrome(string str) {

  	// Stores the reverse of the string s
    string rev = str;

    // Reverse the string
    reverse(rev.begin(), rev.end());

    // If rev is equal to str
    if (str == rev)
        cout << "\"" << str
      	<< "\" is palindrome." << endl;

	// If rev is NOT equal to str
    else
        cout << "\"" << str
      	<< "\" is NOT palindrome." << endl;
}
/*Time Complexity: O(n), where n is the length of string.
Auxiliary Space: O(n)*/
```

```cpp
//Using Two Pointer Method
void isPalindrome (string str) {

  	// Specify the starting and ending indexes
    int left = 0, right = str.size() - 1;

  	// Flag to terminate the loop if mismatch
  	// characters found
  	bool flag = true;

  	// Till the left is less than right
    while (left < right) {

        // If any character not match, break the
        // loop, string is not palindrome
        if (str[left] != str[right]) {
            flag = false;
            break;
        }
        left++;
        right--;
    }

  	if (flag)
        cout << "\"" << str
      	<< "\" is palindrome." << endl;

    else
        cout << "\"" << str
      	<< "\" is NOT palindrome." << endl;
}
/*Time Complexity: O(n), where n is the length of string.
Auxiliary Space: O(1)*/
```

```cpp
//using recursion
bool palinHelper(const string& str, int left,
                 int right) {

    // If the start and end pointers cross each other,
  	// it means all characters have matched
    if (left >= right)
        return true;

    // If characters don't match, the string is not
  	// a palindrome
    if (str[left] != str[right])
        return false;

    // Recursively check for the rest of the string
    return palinHelper(str, left + 1, right - 1);
}

// Function to check if the string is a palindrome
void isPalindrome(string str) {

    // Calling the recursive function to check
  	// palindrome string
    if (palinHelper(str, 0, str.length() - 1))
        cout << "\"" << str << "\" is palindrome."
      		<< endl;
    else
        cout << "\"" << str << "\" is NOT palindrome."
      		<< endl;
}
```

- https://codeforces.com/problemset/problem/1466/C
  example:

- https://codeforces.com/problemset/problem/1610/B
- https://codeforces.com/problemset/problem/1582/C

---

### Mex

- https://codeforces.com/contest/1496/problem/B

---
