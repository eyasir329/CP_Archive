### String

<pre>
s = s + 'a' -> O(N) -> access whole string
s += 'a' -> O(1) -> not accesssing whole string
</pre>

### stringstream

    - input from string

```cpp
string s = "12  13    24";
stringstream ss(s);
cout << ss.str << endl;
int a, b, c; ss >> a >> b >> c;
//alternate
while (ss >> n) {
        cout << n << endl;
}
//separate words from string
getline(cin, s);
stringstream ss(s);
while (ss >> n) {
        cout << n << endl;
}
```

<code>string(int, char)</code> n=3, c='a' => "aaa"

<code>char c = num + '0'</code>
<code>int num = 'c' - '0'</code>

https://www.geeksforgeeks.org/cpp-string-functions/

#### Binary String

- [2029B_Replacement]()
- [1971D_Binary Cut]()
- [1913B_Swap and Delete]()
- [1837C_Best Binary String]()
- [2030C_A TRUE Battle]()

---

### Implementation

- https://codeforces.com/problemset/problem/1609/B
- https://codeforces.com/problemset/problem/2039/B
- https://codeforces.com/problemset/problem/1536/B
- https://codeforces.com/contest/1594/problem/C
