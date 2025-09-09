# 📚 String Handling

## ✨ Table of Contents

* [String Basics](#string-basics)
* [C-String](#c-string)
* [Input with Spaces](#input-with-spaces)
* [Stringstream](#stringstream)
* [Substring](#substring)
* [Binary String](#binary-string)
* [Implementation Problems](#implementation-problems)

---

## String Basics

```cpp
string sub = s.substr(2, 2);      // characters at index 2 and 3
int pos = s.find("kk");          // first occurrence
int pos = s.rfind('1');           // last occurrence

if (pos == string::npos) {
  // not found
} else {
  // found at pos
}

s.replace(11, 5, "abcde");
s.append("abc");
s.compare("abc");
std::getline(std::cin, str);

s += 'a';     // O(1)
s = s + 'a';  // O(N)

s.insert(...);
s.erase(...);

string s = string(c_string);
char* c_string = s.c_str();
```
* [GeeksForGeeks: C++ String Functions](https://www.geeksforgeeks.org/cpp-string-functions/)

![std::string cheatsheet](https://hackingcpp.com/cpp/std/string_crop.png)

---

## 📄 C-String

C-strings are arrays of `char` terminated by the null character `\0`.

```c
char hello[] = "World";
```

### 📆 Common Functions

| Function            | Description                               | Example                             |
| ------------------- | ----------------------------------------- | ----------------------------------- |
| `strlen(s)`         | Length of string (excluding `\0`)         | `strlen("hello")` → `5`             |
| `strcpy(dest, src)` | Copy string from `src` to `dest`          | `strcpy(dest, "hi")`                |
| `strcmp(a, b)`      | Compare two strings                       | `strcmp("abc", "abd")` → `-1`       |
| `strcat(a, b)`      | Append `b` to `a`                         | `strcat(a, "world")`                |
| `strrev(s)`         | Reverse the string *(non-standard)*       | `strrev("hello")` → `"olleh"`       |
| `strchr(s, c)`      | Pointer to first occurrence of `c` in `s` | `strchr("abcde", 'c')` → `'c'`      |
| `strstr(a, b)`      | First occurrence of `b` in `a`            | `strstr("abcdef", "cd")` → `"cdef"` |

---

## Input with Spaces

```cpp
char hello[10];
cin.getline(hello, 10);
cout << hello << endl;
```

```cpp
int n;
cin >> n; // stops at whitespace or non-digit

string s;
cin >> s; // reads up to whitespace
```

```cpp
int n; cin >> n;
cin.get(); // or cin.ignore() / getchar()
string s;
for (int i = 0; i < n; i++) {
  cin >> s;
  cout << s << " ";
}
```
example:
* [UVA Problem 1225](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1886)
---

## Stringstream

Read words or numbers from a string:

```cpp
string s = "12  13    24";
stringstream ss(s);
int a, b, c;
ss >> a >> b >> c;
```

### ✅ Alternate Pattern:

```cpp
while (ss >> n) {
  cout << n << endl;
}

getline(cin, s);
stringstream ss2(s);
while (ss2 >> n) {
  cout << n << endl;
}
```

### 📌 Misc:

```cpp
string(3, 'a'); // "aaa"
char c = num + '0';
int num = c - '0';
```

---

## Substring

### ⚖️ Syntax:

```cpp
string substr (size_t pos = 0, size_t len = npos) const;
```
* pos: starting index (0-based)
* len: number of characters to extract (optional)
* Returns a substring starting at pos with at most len characters

### 📆 Examples:

```cpp
string s = "abcdef";

string sub1 = s.substr(2);      // "cdef"
string sub2 = s.substr(1, 3);   // "bcd"
string sub3 = s.substr(0, 1);   // "a"
```

### 📌 Use Cases

```cpp
string filename = "photo.jpg";
string ext = filename.substr(filename.find_last_of('.') + 1); // "jpg"

string s = "hello world";
if (s.substr(0, 5) == "hello") {...}
if (s.substr(s.size() - 5) == "world") {...}
```

### ⚡ Brute Force All Substrings:

```cpp
for (int i = 0; i < s.size(); ++i)
  for (int len = 1; len <= s.size() - i; ++len)
    cout << s.substr(i, len) << endl;
```

**Problem Example**: [Codeforces 1437B](https://codeforces.com/problemset/problem/1437/B)

---

## Binary String

A **binary string** contains only `0` and `1`.

```cpp
string s = "101101";
```

---

## 🧠 Basic Properties

| Property                   | Description                         | Example                                                  |
| -------------------------- | ----------------------------------- | -------------------------------------------------------- |
| Length                     | `s.length()` or `s.size()`          | `"101".length()` = 3                                     |
| Count of 1s / 0s           | `count(s.begin(), s.end(), '1')`    | 4 for `"101101"`                                         |
| All same                   | Check if all chars are 0 or 1       | `all_of(s.begin(), s.end(), [](char c){return c=='1';})` |
| Alternating                | No two adjacent chars are same      | `"0101"` is alternating                                  |
| Palindromic                | `s == string(s.rbegin(), s.rend())` | `"10101"` is palindrome                                  |
| Longest continuous segment | Use sliding window / manual loop    | Longest `"111"` segment                                  |

---

## 🔍 Pattern Matching Examples

### 1. Count total 1s and 0s

```cpp
int ones = count(s.begin(), s.end(), '1');
int zeros = count(s.begin(), s.end(), '0');
```

### 2. Longest contiguous 1s / 0s

```cpp
int max_ones = 0, cur = 0;
for (char c : s) {
    if (c == '1') cur++;
    else cur = 0;
    max_ones = max(max_ones, cur);
}
```

### 3. Check if string is alternating

```cpp
bool isAlt = true;
for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) isAlt = false;
}
```

---

## 🔢 Useful Tricks

| Trick                      | Code                                   |
| -------------------------- | -------------------------------------- |
| Convert to number (base 2) | `int x = stoi(s, 0, 2);`               |
| Convert number to binary   | `bitset<8>(n).to_string();`            |
| XOR to toggle              | `'1' ^ '1' = 0`, `'1' ^ '0' = 1`, etc. |
| Flip character             | `c = (c == '1' ? '0' : '1');`          |
| Compare binary strings     | `s1 < s2` (lexicographically)          |

---

## 🧠 Example Task

**Task**: Make the binary string alternating by removing minimum characters.

```cpp
string s = "100101";
int cnt = 0;
for (int i = 1; i < s.size(); ++i)
    if (s[i] == s[i-1]) cnt++;
cout << cnt << endl;  // Output: 2
```

---

## 📌 Practice Ideas

* Count substrings with equal number of 0s and 1s
* Longest alternating substring
* Palindromic binary substrings
* Number of 1s between two 0s, and vice versa
* Greedy deletion to make all characters same
* Flip substrings to maximize 1s

### 🔗 Problems

| ID    | Name               | Link                                                     |
| ----- | ------------------ | -------------------------------------------------------- |
| 2029B | Replacement        | [Link](https://codeforces.com/problemset/problem/2029/B) |
| 1971D | Binary Cut         | [Link](https://codeforces.com/problemset/problem/1971/D) |
| 1913B | Swap and Delete    | [Link](https://codeforces.com/problemset/problem/1913/B) |
| 1837C | Best Binary String | [Link](https://codeforces.com/problemset/problem/1837/C) |
| 2030C | A TRUE Battle      | [Link](https://codeforces.com/problemset/problem/2030/C) |

---


## Implementation Problems

* [1609B – CF Problem](https://codeforces.com/problemset/problem/1609/B)
* [2039B – CF Problem](https://codeforces.com/problemset/problem/2039/B)
* [1536B – CF Problem](https://codeforces.com/problemset/problem/1536/B)
* [1594C – CF Problem](https://codeforces.com/contest/1594/problem/C)
* [1354B – CF Problem](https://codeforces.com/problemset/problem/1354/B)

---