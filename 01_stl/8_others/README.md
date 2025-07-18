- Standard Algorithms

![algo](https://hackingcpp.com/cpp/std/algorithms_crop.png)

- Lambda Expressions
<pre>
- [&] capture all variable by refference
- [=] capture all variable by value
- [a,&b] capture a by value, b byb refference
</pre>

![Lambda Expressions](https://hackingcpp.com/cpp/lang/lambdas_crop.png)

- Custom Comparator
<pre>
- weak ordering (a>=b) (in C++ '=' always return false)
- so don't use it('=') in comparator function
</pre>

```cpp
sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    return a.second>b.second;
});
```

example:

- [632C_The Smallest String Concatenation]()

    <pre>We have to sort all string by lexicographical order.
  
    (a < b), (b < c) -> (a < c)</pre>

- https://codeforces.com/problemset/problem/1623/B

### Some Necessary Technique

#

- Sort the Distance from Origin

- Sort 5D Points
- String Sort
- Balanced Bracket
- Sliding Window Technique
- Kth Smallest in Each Prefix
- Unique Elements
- Remove B from A
- Word Frequency
- Occurrences
- Update and Remove Query
- Number of Pair of Strings such that d(a,b)<=k in Binary String

---
