## Sliding Window

    1. Fixed Size Sliding Window
    2. Variable Size Sliding Window (2 Pointer)
    Used is array based problem, basically is subarray

#### _Current Window must get enough info to get the ans for that window_


- https://codeforces.com/contest/2148/problem/E

## Sliding Window

https://usaco.guide/gold/sliding-window?lang=cpp

<pre>
- A sliding window is a constant-size subarray that moves from left to right through the array.
- For each position of the window, we want to compute some information.
</pre>

- Sum of every k length subarray

```cpp
int sum = 0;
for(int i=1;i<=n;i++){
  sum+=a[i];
  if(i>=k){
    cout<<sum<<" ";
    sum-=a[i-k+1];
  }
}
```

- Maximum sum subarray of length k

```cpp
struct DS {
  multiset<ll>ms;
  DS() {}
  void insert(ll x) {
    ms.insert(x);
  }
  void erase(ll x) {
    ms.erase(ms.find(x));
  }
  ll get_max() {
    return *(--ms.end());
  }
} ds;
for(int i=1;i<=n;i++){
  ds.insert(a[i]);
  if(i>=k){
    cout<<ds.get_max()<<" ";
    ds.erase(a[i-k+1]);
  }
}
```

- Maximum of all subarray of length k

- Number of unique elements in all subarrays of length k

>example

---