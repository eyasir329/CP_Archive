## Technique

---

## Contribution Technique

### Basic Contribution Technique

https://medium.com/spidernitt/contribution-technique-i-c1730f195b41

<pre>
The basic idea behind this technique is to identify the entities (basic elements) that constitute the final answer. We need an answer to this question: “What is my final answer made up of?” Then, we would iterate on each entity and find its own contribution to the final answer.

FOR(1,N) ans += indivisual contribution of a[i] 
</pre>

- Sum of Pair Sums (All Pair)

  <pre>
  Given an array a of size n, find sum(a[i]+a[j]) from (i,j)->1 to n 
  
  Here, each element add 2*n times (n+n)
  FOR(1,n)-> ans += 2*n*a[i]
  </pre>

- Sum of Subarray Sums

  <pre>
  Given an array a of size n, find sum(i:1->n,j:1->n (a[i]+a[i+1]+...+a[j]))
  (find all subarray sum of sum)
  
  FOR(1,n)-> ans += a[i]*i*(n-i+1);
  </pre>

- Sum of Subset Sums

  <pre>
  Given an array a of size n, find the sum of all subset sums of a (ans modulo 1e9+7)
  
  FOR(1,n)-> ans += a[i]*2<sup>n-1</sup>;
  </pre>

- Product of Pair Products

  <pre>
  Product of every pair and product of all this product, (ans modulo 1e9+7)
  
  FOR(1,n)-> ans *= a[i]<sup>2n</sup> 
  </pre>

- XOR of Subarray XORs

  <pre>
  - a[i] contribute to my ans if (i*(n-i+1))&1
  </pre>

- Sum of (max-min) over all Subsets

  <pre>
  - sum of (max(subset) - min(subset)) from 1 to n
  
  - sort the array, then
  a(min) ..upto k in between.. b(max) -> 2<sup>j-i+1</sup>; in between element, k = j-i+1
  </pre>

  ```cpp
  sort(a+1,a+n+1);
  int ans = 0;
  for(int i=1;i<=n;i++){//O(N*N)
    for(int j=i+1;j<=n;j++){
      ans += (a[j]-a[i])*(1<<(j-i-1));
    }
  }
  //can be done within O(N)
  //by separating min max
  ```

- Sum of Sum Length over all Subarrays

  <pre>
  Given an array a of size n, find the sum (the sum of the subarray multiplied by the length of the subarray) over all subarrays of a.
  
  a[i]*len -> a[i]*(k1+k2+...+kn)//whose subarray that contain a[i], sum of their length
  -> (sum(left(1->i)), sum(right(i->N))) (right - left + 1)
  -> sum(l->1,i)-> S(i,n)-l(n-i+1)+(n-i+1)
  -> S(i,n)*i - (n-i+1)*S(1,i) + (n-i+1)*i
  </pre>

  ```cpp
  //bruteforce O(N*N)
  int ans = 0;
  for(int i=1;i<=n;i++){
    int sum = 0;
    for(int j=i;j<=n;j++){
      sum+=a[j];
      ans+=sum*(j-i+1);//subarray sum*length
    }
  }
  //o(N) approach
  int F(int n){
    return n*(n+1)/2;
  }
  int S(int l,int r){
    return F(r)-F(l-1);//l to r sum
  }
  ...
  int ans = 0;
  for(int i=1;i<=n;i++){
    int contribution = S(i,n)*i-(n-i+1)*S(1,i)+(n-i+1)*i;
    ans += a[i]*contribution;
  }
  ```

- Sum of Number of Vowels in Substrings

  <pre>
  Given a string s of size n, find the sum of number of vowels in all substrings of s.
  </pre>

  [leetcode2063_Vowels of All Substrings]()

  ```cpp
  long long countVowels(const std::string& s) {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    long long total_sum = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (vowels.count(s[i])) {
        total_sum += (long long)(i + 1) * (n - i);
      }
    }
    return total_sum;
  }
  ```

- Sum of Number of Inversions in Permutations

  <pre>
  Given an int n, find the sum of the number of inversions in all permutations (1,2...n)
  
  number of inversion -> how much such that (i < j and a[i] > a[j])
  
  around half permutation i is behind j and vice-versa (where a[i]>a[j])
  n!/2 and there are n*(n-1)/2 total pair
  </pre>

- Sum of Number of Inversions in Subarrray

---
