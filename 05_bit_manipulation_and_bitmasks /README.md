## Bit Manipulation And Bitmasking

### Bit Manipulation and Bitmasks

https://codeforces.com/blog/entry/73490

- In bitwise operation, we have to think it **_bit by bit_**. It's nothing means in decimal number systems.

- We have to use **bracket()** when we use bitwise operation.
- **LEFT SHIFT**: (x<<1) == x\*2 , (x<<2)==x\*2\*2 ... go on ... (x<<k) == x\*2<sup>k</sup>.
- (1<<n) == 2<sup>n</sup>
- **RIGNT SHIFT**: (x>>1) == x/2, (x>>k) == x/(2<sup>k</sup>)

<pre>
    LEFT SHIFT                             RIGHT SHIFT
       13 =     1101                          13 =   1101
(13 << 2) =   110100                   (13 >> 2) =     11  
</pre>

- by default (1) is int. If we need more than 2^31-1, then use (1LL) and store it in long long
- (~a)==(~-a)
- xor -> (a^b) -> single 1 then 1 otherwise 0.
- **ODD** number check (x&1)==1 // last bit is 1 in all odd number//0 for even
- something&1 = something /// something&0=0

<pre>
NOTE: 
- for any int n, (bitwise and) always give a num(x&n)<=n
      - subarray have min and value - whole array
      - subarray have max and value - in length 1

- for any int n, (bitwise or) always give a num(x|n)>=n
      - subarray have max or value - whole array
      - subarray have min and value - in length 1

- xor gives same number of digits(both have).
      - can't say anything 
</pre>

https://codeforces.com/blog/entry/123404 (max xor subarray)

#### Check a Bit ON or OFF

      Last bit-> (x & 1)
      ith bit-> ((x >> i) & 1)

#### Index of all on bit //Count all on bit

      int cnt = 0;
      for(int i=0;i<32;i++) //31(0-30) is also good//because last bit is sign bit
      {
        if(((x>> i)&1)){//on ith bit
          cout<<i<<" ";
          cnt++;
        }
      }

#### SET kth bit ON

      (x |= (1 << k)) // x or 2^k

#### SET kth bit OFF

      (x &= ~(1 << k)) // x and ~2^k

#### Toggle kth bit

      0^1=1  1^1=0 - using xor
      (x ^= (1 << k))

#### Number is power of 2 or not

      if(num_of_set_bit==1)

#

https://www.programiz.com/cpp-programming/bitwise-operators

<hr>

## Example Code

### Total Combination + Total Subset

<pre>
  vector<int> arr = {1, 6, 8, 9};
  // total n! combination// 4! =24 //pick all but different time
  do {
    int num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
    cout << num << endl;
  } while (next_permutation(arr.begin(), arr.end()));

  // total subset 2^n -- pick or not pick
  for (int mask = 0; mask < (1 << arr.size()); mask++) {
    for (int i = 0; i < arr.size(); i++) {
      if ((mask >> i) & 1) {
        cout << arr[i];
      }
    }
    cout << endl;
  }

Output:-
1689 1698 1869 1896 1968 1986 6189 6198 6819 6891 6918 6981 8169 8196 8619 8691 8916 8961 9168 9186 9618 9681 9816 9861 - total combination
{} 1 6 16 8 18 68 168 9 19 69 169 89 189 689 1689 - total subset
</pre>

- <code>You are given N≤20 numbers, each up to 10<sup>9</sup>. Is there a subset with sum equal to given goal S?</code>

      for(int mask = 0; mask < (1 << n); mask++) { //O(2<sup>n</sup>*n)
            long long sum_of_this_subset = 0;
            for(int i = 0; i < n; i++) {
                  if(mask & (1 << i)) {
                        sum_of_this_subset += a[i];
                  }
            }
            if(sum_of_this_subset == S) {
                  puts("YES");
                  return 0;
            }
      }
      puts("NO");

#### Checking Set Bit

https://codeforces.com/contest/2020/problem/C

        int a = 0;
        for (int i = 60; i >= 0; i--)
        {
          int x = ((1LL << i) & b) != 0;
          int y = ((1LL << i) & c) != 0;
          int z = ((1LL << i) & d) != 0;
          int canBe = m[ {x, y, z}];//pre-calculating truth table
          if (canBe == -1)//something that cannot possible
            {
              a = -1;
              break;
            }
            else
            {
              a += canBe * (1LL << i);//answer calculation
            }
        }

#

### XOR Tricks

https://florian.github.io//xor-trick/

- a^a = 0

(xor of even number of same type = 0, otherwise(odd) only one have that type)

- a^0 = a
- a^b = 0 (a==b)

Don't matter order of operations.

- a^b^a = 0^b = b
- a^b = c => a = b^c (vise-versa)

<pre>
if we have a sequence of xor operations... we can remove pair of douplicate value.
</pre>

#### Duplicate number finding

<pre>
we have 1 to n all numbers and a extra one number<=n, we have to find that extra number.
</pre>

```
(1^2^3^....^n)^(xor of given all numbers) = extra one
```

#### Missing number finding

<pre>
we have 1 to n-1, we have to find missing number.
</pre>

```
(1^2^3^....^n)^(xor of given all numbers) = missing one
```

#### Prefix XOR (Subarray XOR)

[cses1650_Range Xor Queries](./3_xor_tricks/cses1650_Range%20Xor%20Queries.cpp)

<pre>
Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

hint: same as prefix sum
</pre>
