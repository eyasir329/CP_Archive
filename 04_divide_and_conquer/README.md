- Merge Sort + Quick Sort

### Merge Sort -> O(nlogn)

Divide & Conquer

```cpp
//more important than other sorting algorithm
//divide it (half by half) untill size is 1
//then merge two sorted array using two pointer (within O(N))
#include <bits/stdc++.h>
using namespace std;
vector<int>a;

vector<int> merge(vector<int>&l, vector<int>&r) {
  int n = l.size(), m = r.size();
  vector<int>ans;
  int i = 0, j = 0;
  while (i < n and j < m) {
    if (l[i] < r[j]) {
      ans.push_back(l[i++]);
    } else {
      ans.push_back(r[j++]);
    }
  }
  while (i < n) ans.push_back(l[i++]);
  while (j < m) ans.push_back(r[j++]);
  return ans;
}

vector<int> merge_sort(int l, int r) {
  if (l == r)return {a[l]};
  int mid = (l + r) / 2;
  vector<int>left = merge_sort(l, mid);
  vector<int>right = merge_sort(mid + 1, r);
  return merge(left, right);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a = merge_sort(0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
```

![merge sort](https://miro.medium.com/v2/resize:fit:1400/1*iTaxrPnbPOwtL9p8BsHuTg.png)

<pre>
Divide and Conquer follow three steps,
- Divide (break the given problem into subproblems of same type)
- Conquer (recursively solve these subproblems)
- Combine (appropriatly combine the answers)
</pre>

example:

- [abc293e_Geometric Progression](./abc293e_Geometric%20Progression.cpp)

  <pre>
  Given integers A, X, and M, find ∑(i=0->X−1)Ai, modulo M
  (1<=A,M<=1e9, 1<=X<=1e12) (m can be any number)
  
  a^0 + a^1 + a^2 ... a^n-1 (mod m) = (a<sup>x</sup>-1/a-1) % mod -> we can't use these formula because m can't always prime .. can be done using extentedgcd
  
  - when we have to do something in k times, then most probably use binary exponentiation(through recursion) to solve faster
  
  - use divide and conquer technique
  
  a<sup>0</sup> + a<sup>1</sup> + a<sup>2</sup> + a<sup>3</sup> + a<sup>4</sup>(a<sup>0</sup> + a<sup>1</sup> + a<sup>2</sup> + a<sup>3</sup>) -> x is odd   
  
  prev(same as odd) + a^x -> x is even 
  </pre>
