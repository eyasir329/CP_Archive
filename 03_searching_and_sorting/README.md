## Sorting

https://visualgo.net/en/sorting

### Bubble Sort ->O(n\*n)

```cpp
//each operation bigger go to last index
//compare adjacent two by two
//iteration go upto n-1
for(int step = 1;step<n;step++){
  for(int i=1;i<n;i++){
    if(a[i]>a[i+1]){//1 based indexing
      swap(a[i],a[i+1]);
    }
  }
}
```

### Selection Sort -> 0(n\*n)

```cpp
//select smaller and swap that to first index
for(int i=1;i<n;i++){
  int min_index = i;
  for(int j=i+1;j<=n;j++){
    if(a[j]<a[min_index]){
      min_index = j;
    }
  }
  swap(a[i],a[min_index]);
}
```

### Insertion Sort -> 0(n\*n)

```cpp
//each element(select) and move to the right positions
//insert new element to the right position
for(int i=2;i<=n;i++){
  int key = a[i];
  int j = i-1;
  while(j>=1 and a[j]>key){
    a[j+1] = a[j];
    j--;
  }
  a[j+1]=key;
}
```

### Counting Sort -> O(n+max)

Extra Space -> O(MAX)

```cpp
//store each in frequency array
//1 to max print i cnt[i] times
const int MAX = 1e6;
int cnt[MAX+1];
{
  for(int i=1;i<=n;i++){
    cnt[a[i]]++;
  }
  for(int i=1;i<=MAX;i++){
    for(int j=1;j<=cnt[i];j++){
      cout<<i<<" ";
    }
  }
}
```

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

example:

- [2027B_Stalin Sort](./1_sorting/2027B_Stalin%20Sort.cpp)

  <pre>
  starting from the second element in the array, if it is strictly smaller than the previous element (ignoring those which have already been deleted), then delete it. Continue iterating through the array until it is sorted in non-decreasing order. 
  
  We define an array as vulnerable if you can sort it in non-increasing order by repeatedly applying a Stalin Sort to any of its subarrays, as many times as is needed.
  
  Given an array a of n integers, determine the minimum number of integers which must be removed from the array to make it vulnerable?
  
  Therefore, we just need to find the longest subsequence in which the first element is the largest. This can be done easily in O(n2) — consider each index being the first item in the subsequence, and count all items to the right of it which are smaller or equal to it. Find the maximum over all of these, then subtract this from n.
  </pre>

- https://codeforces.com/contest/1741/problem/D

#### Greedy With Sorting

- [cses1629_Movie Festival](./1_sorting/cses1629_Movie%20Festival.cpp)

  <pre>
  In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
  
  - single time only watch single movie
  - sort ny ending time which is less comes first
  
  [Activity Selection Problem]
  </pre>

- [cses1074_Stick Lengths](./1_sorting/cses1074_Stick%20Lengths.cpp)

  <pre>There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
  You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
  What is the minimum total cost?
  
  - make everything to became middle element
  </pre>

- [cses1630_Tasks and Deadlines](./1_sorting/cses1630_Tasks%20and%20Deadlines.cpp)

  <pre>
  You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
  
  What is your maximum reward if you act optimally?
  - we have to maximize sum(d - f) and do all work.
  - start first which has minimum duration 
  </pre>

- [cses1073_Towers](./1_sorting/cses1073_Towers.cpp)

  <pre>
  You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
  You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
  </pre>

- [cses1161_Stick Divisions](./1_sorting/cses1161_Stick%20Divisions.cpp)
  <pre>
  You have a stick of length x and you want to divide it into n sticks, with given lengths, whose total length is x.
  On each move you can take any stick and divide it into two sticks. The cost of such an operation is the length of the original stick.
  What is the minimum cost needed to create the sticks?
  
  input has n integers d_1,d_2,\ldots,d_n: the length of each stick in the division.
  
  - first merge two min size stick
  </pre>

---

## Searching

    - linear search ->  worst case O(N)

example;

- [cses1640_Sum of Two Values](./2_searching/cses1640_Sum%20of%20Two%20Values.cpp)

  <pre>
  Given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
  </pre>

- [cses1662_Subarray Divisibility](./2_searching/cses1662_Subarray%20Divisibility.cpp)

  <pre>Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
  
  pref[j] - pref[i-1] % n = 0
  </pre>

---

## Binary Search

      - need to be sorted
      - worst case O(logN)

- bs using recursive and iterative way (GENERAL TYPE)

```cpp
//yusing recursive
bool bs(int l, int r) {
    if (l > r)return false;
    int mid = (l + r) / 2;
    if (v[mid] == x) {
        return true;
    } else if (x > v[mid]) {
        return bs(mid + 1, r);
    } else {
        return bs(l, mid - 1);
    }
}
```

```cpp
//using iterative
bool bs(int l, int r) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x) {
            return true;
        } else if (x > v[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}
```

- bs for leftmost

- bs for right most

- bs generalize

```cpp
int bs(vector<int> arr, int k){
  int l = -1,/*min-1*/ r = arr.size() + 1; // max+1
  auto pred = [&](int m) -> bool{
    return m<=k; //last occurence of k // ans = l
    // return m<k;  //first occurence of k // ans = r
  };
  while (r - l > 1){
    int m = (l + r) / 2;
    if (pred(m)){
      l = m; // l is always last true
    }
    else{
      r = m; // r is always first false
    }
  }
  return l;//r
}
```

#

#### Different Types

[ITMO Academy: pilot course » Binary Search](https://codeforces.com/edu/course/2/lesson/6/1)

##### LEVEL1 (Searching an item in an array, Find closest in array)

- Find something on array (general)
- [Given a sortest **_binary string_**, we have to find where first 1 occur](./3_binary_search/1_general_bs/sorted_binary_string_1st_1.cpp)
- Find closest in array

  - Find the maximum element not greater than x (closest to x on the left)
  - Find the minimum element not less than x (closest to x on the right)

- STL (binary_search, lower_bound, upper_bound)
<pre>
LB, UB -> returns iterator (it - v.begin() -> index, *it -> value)
- lower_bound -> (>=x) (first value which is atleast >=x)
- upper_bound -> (>x) (first value which is strictly >x)

(UB-LB -> number of same elements)

- binary_search -> (0/1) (find x or not)
</pre>

##### LEVEL2 (Binary Search On Answer)

<pre>
- Important to find worst case (search space)
- Careful to calculate mid and monotonic function, it can occur overflow
- int mid = (l+r)/2;(upto 2e9) => l+(r-l)/2;//if l+r occur overflow
</pre>

Binary search on **_monotonic function_** (value is becoming greater or lesser but not both)

- [First minimum x for f(x)>=M, where f(x) is the monotonic function](./3_binary_search/2_bs_on_answer/find_largest_for_fx_isgreater_orEqual_toX.cpp)

  convert to 000001111 or 111100000 like this and detect first one (01/10)

- rope problem
- [CSES1620_Factory Machines](./3_binary_search/2_bs_on_answer/cses1620_factory_machine.cpp)

    <pre>a factory has n machines, each need ki time to produce one product, What is the shoetest time needed to produce t product.</pre>

- [1201C_Maximum Median](./3_binary_search/2_bs_on_answer/1201C_Maximum%20Median.cpp)
    <pre>make median as large as possible within atmost k operations, each operation increase a[i] = a[i]+1 -> answer>=x? (minimum number of operations) worst case 1e9+1e9 -> 2e9 
  
    - median (middle element in the sortest array, in even length (mid_left+mid_right)/2), odd -> (n+1)/2</pre>

##### LEVEL3 (Minimax Problems)

<pre>
- minimize some maximum value
- maximize some minimum value
</pre>

- [CSES1085_Array Division](./3_binary_search/3_bs_on_minimax/cses1085_Array%20Division.cpp)

  <pre>Divide the array into k subarray(distinct and put all value in array), such that maximum sum in a subarray(all subarray sum) is as small as possible.
  
  we have to divide array, such that each sum<=x (possible or not) and no. of divide<=k
  </pre>

##### LEVEL4 (Maximum Average)

-

- maximum average

##### LEVEL5 (Finding the K-th(smallest/largest) Element)

<pre>
- kth smallest/largest (something) -> try to consider binary search
- check kth smallest num <=x ? or not// greater >=x
</pre>

- [1352C_Kth Not Divisible by n](./3_binary_search/5_bs_on_kth_element/1352C_Kth%20Not%20Divisible%20by%20n.cpp)

  <pre>
  print kth int (which is not divisible by n -> this series kth value)
  
  if(enough num within x) -> x - floor(x/3);//total - no. divisors by 3(between x)
  </pre>

- [K-th Sum](./3_binary_search/5_bs_on_kth_element/cfedu_kth_sum.cpp)
  <pre>
  array a,b (n int in each), make sum of each pair(not to be distinct) of numbers and find kth sum in ascending order 
  
  using bs -> O(n*n)->0(nlogn)
  - cnt pair of sum <=x and check it to k(at least k)
  
  cnt pair of sum <=x in bruteforce O(n*n)
  O(nlogn)-> using sorting (another binary search (b[i]<=x-a[i]))  
  0(n)-> using two pointer
  
  </pre>

##### LEVEL6 (BS ON Doubles)

<pre>
- while(r-l>= EPS){...}(1e-7) (because of double value)
- this type of problem given something like that ... answer will be considered correct if the relative or absolute error is not more than 10−6 (maybe -1 extra)
- for 1e-6 -> 100 iterators are enough
</pre>

- [cfedu_Equation](./3_binary_search/6_bs_on_doubles/283932E_Equation.cpp)
  <pre>
  find number x such that x*x+sqrt(x) = c (1.0<=c<=1e10), absolute error not more than 1e-6
  
  largest x for which f(x)<=c or smallest x for which f(x)>=c
  </pre>

#

example:

https://codeforces.com/contest/2020/problem/B

https://codeforces.com/contest/2031/problem/C

- Odd number of divisors are perfect square

      k+(long long)(sqrtl(k)+0.5) //upto ... we find k perfect sqr

---

## Interactive

<pre>
- Interactive problems are problems where you have to interact with the judge to get the answer.
- don't use fastio and '\n'
- if use '\n' then cout.flush()
- endl = '\n' + flush()
- main goal -> we have to minimize the query number 
</pre>

example:

- [cfgym101021_Guess the Number](./4_interactive/cfgym_101021_Guess%20the%20Number.cpp)
<pre>
- Your program is allowed to make no more than 25 queries
- so we have use BS (1 to 1 000 000 within 25 query)
</pre>

- [679A_Bear and Prime 100](./4_interactive/679A_Bear%20and%20Prime%20100.cpp)
<pre>
- query to all prime number upto 50,... 51\*2 >100 (so our number don't have bigger prime number than 50)
- composite number always have move than one prime numbers
</pre>

---

## Ternary Search

---
