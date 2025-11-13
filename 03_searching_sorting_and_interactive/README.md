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

example:

- [First minimum x for f(x)>=M, where f(x) is the monotonic function](./3_binary_search/2_bs_on_answer/find_largest_for_fx_isgreater_orEqual_toX.cpp)

  convert to 000001111 or 111100000 like this and detect first one (01/10)

- rope problem
- [CSES1620_Factory Machines](./3_binary_search/2_bs_on_answer/cses1620_factory_machine.cpp)

    <pre>a factory has n machines, each need ki time to produce one product, What is the shoetest time needed to produce t product.</pre>

- [1201C_Maximum Median](./3_binary_search/2_bs_on_answer/1201C_Maximum%20Median.cpp)
    <pre>make median as large as possible within atmost k operations, each operation increase a[i] = a[i]+1 -> answer>=x? (minimum number of operations) worst case 1e9+1e9 -> 2e9 
  
    - median (middle element in the sortest array, in even length (mid_left+mid_right)/2), odd -> (n+1)/2</pre>

- [2091D - Place of the Olympiad](https://codeforces.com/contest/2091/problem/D)

To maximize the number of desks in one row, we arrange as many **benches** of length `x` as possible, with an **indent** of 1 unit after each bench.  
Hence, each block (bench + indent) occupies a total length of `x + 1`.

Let `m` be the total available length of the row.

We can fit:

```math
\left\lfloor \frac{m}{x + 1} \right\rfloor
```

such blocks in the row.

The total number of desks will be:

```math
f(x) = x \cdot \left\lfloor \frac{m}{x + 1} \right\rfloor + (m \bmod (x + 1))
```

- The first term counts desks from the full blocks.
- The second term counts extra desks that can fit in the remaining space (if any).

- https://codeforces.com/problemset/problem/1613/C

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
