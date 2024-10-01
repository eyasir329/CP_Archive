## TWO POINTER

    1. Adhoc Two Pointer
    2. Good Segment Category*

https://usaco.guide/silver/two-pointers?lang=cpp

### Iterating two monotonic pointers across an array to search for a pair of indices satisfying some condition in linear time.

_Each variable moves in a single direction_, and they only traverse the array a single time.
Therefore, time complexity will be O(N+M)

### Optimization_Technique

    Binary Search on Array O(NlogN)-> using two pointer O(N)
    Binary Search <-> Two Pointer

https://www.geeksforgeeks.org/window-sliding-technique/
https://www.geeksforgeeks.org/two-pointers-technique/

### Variable Size Sliding Window (Also known as two pointer)

The general steps to solve these questions by following below steps:

    In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
    At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
    Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
    We follow these steps until we reach to the end of the array.

### Good Segment Technique Tricks

    *If segment within [L,R] is good, segment enclosed within will be good.
        -> Increasing, Decreasing Technique
    *Do not use binary search in that problem
    *Good segment-> multiple of (j-i+1) for every i in (longest_subarray_length_sum<=k)

### Problems

https://usaco.guide/CPH.pdf#page=87

- #### Subarray sum

  Given an array of N (1<=N<=1e5 ) positive elements, find a contiguous subarray that
  sums to X.

  A[] ={1 3 2 5 1 1 2 3} , x = 8

  _Naive Method_ : Find all subarray and compare to x, but that give O(N\*N)

  This problem can be solved in O(n) time by using the two pointers method.

  ![subarray sum](https://i.ibb.co.com/VTCc0hw/Screenshot-from-2024-10-01-12-49-20.png)

  **Time Complexity**

  The running time of the algorithm depends on the number of steps the right
  pointer moves. we know that the pointer moves a total of
  O(n) steps during the algorithm, because it only moves to the right.

  [View Full Code](./gfg_find-subarray-with-given-sum.cpp)

  Pros and Cons:

        f(A[i]<0) then it will give WRONG ANSWER
        The above solution does not work for arrays with negative numbers.
        Then, We use [Hashing + Prefix Sum] O(N) time and O(N) Space

  Ex. [Leetcode_Subarray Sum Equals K](../practice/leetcode_subarray-sum-equals-k.cpp)

  https://darrenyao.com/usacobook/cpp.pdf#page=70

- #### 2SUM problem

  Given an array of N elements (1<=N<=1e5 ), find two elements that sum to X .

  We can
  solve this problem using two pointers; sort the array, then set one pointer at the beginning
  and one pointer at the end of the array.

        int left = 0; int right = n-1;
        while(left < right){
            if(arr[left] + arr[right] == x){
                break;
            } else if(arr[left] + arr[right] < x){
                left++;
            } else {
                right--;
            }
        }
        // if left >= right after the loop ends, no answer exists.

- #### Maximum subarray sum

  Given an array of N integers (1<=N<=1e5 ), which can be positive or negative, find the maximum sum of a contiguous subarray.

  It is not solved by two pointers, but it similar to that kind of problem.
  We can solve this problem using Kadane’s algorithm.

        int best = 0, current = 0;
        for(int i = 0; i < n; i++){
            current = max(0, current + arr[i]);
            best = max(best, current);
        }
