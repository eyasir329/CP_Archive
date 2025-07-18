### String

```cpp
 // index 2 to upto 2 char
 string sub = s.substr(2,2);//char of index 2-3 [cautions its not range like]

 int pos = s.find("kk");//first occurance -> O(N*N)
 int pos = s.rfind('1');//last occurance -> O(N)
 if(pos==string::npos)//not found (-1)
 else //found at pos (starting index)
 s.replace(11,5,"abcde");
 s.append("abc");
 s.compare("abc");
 std::getline(std::cin, str);//line input

 s+='a';//O(1)
 s = s+'a';//O(N)
 //works in both index based and iterator based
 s.insert();
 s.erase();

 string s = string(c_string);
 char c_string[] = s.c_str();
```

- std::string Interface & Utilities Overview

## ![string cheatsheet](https://hackingcpp.com/cpp/std/string_crop.png)

### Multidimentional Arrays and Strings

example:

- 2033B_Sakurako and Water
  https://www.spoj.com/problems/MAX_NUM/en/

---

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
>examples
- https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1886

### SubString
- https://codeforces.com/problemset/problem/1437/B

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
- https://codeforces.com/problemset/problem/1354/B