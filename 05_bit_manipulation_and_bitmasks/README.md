## Bit Manipulation And Bitmasking

### Basic Technique

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

#

#### Builtin Functions

```cpp
int x = 20;               // x in binary: 00000000 00000000 00000000 00010100
long long y = 30;  // y = 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00011110

// 1. Counting Set Bits
cout<<__builtin_popcount(x);//2
cout<<__builtin_popcountll(y);//4

// 2. Counting Leading Zeros
cout<<__builtin_clz(x);//27
cout<<__builtin_clzll(y);//59

// 3. Counting Trailing Zeros
cout<<__builtin_ctz(x);//2
cout<<__builtin_ctzll(y);//1

// 4. Finding the Position of the First Set Bit
cout<<__builtin_ffs(x);
cout<<__builtin_ffsll(x);

// 5. Parity of the Number of Set Bits
int parity = __builtin_parity(x);
int parity_ll = __builtin_parityll(y);

//6. Index of the highest set bit (MSB)
cout<<31 - __builtin_clz(x)<<endl;//4
cout<<63 - __builtin_clzll(y)<<endl;//4
cout<<__lg(x)<<endl;//4
cout<<__lg(y)<<endl;//4

//7. Index of the lowest set bit (LSB)
cout<__builtin_ffs(x) - 1<<endl;//2
cout<__builtin_ffsll(y) - 1<<endl;//1
cout<<__builtin_ctz(x)<<endl;//2
```

---

### Bitwise OR

---

### Bitwise AND

---

### XOR Tricks

https://codeforces.com/contest/2048/problem/C

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

- https://codeforces.com/problemset/problem/2039/C1

---

### BitMasks

#### Total Combination + Total Subset

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

---

### Bit Manipulation

- The Bit Law
<pre>
Always think bit by bit. If the solution is independent of the other bits, then we can solve the problem for each bit separately. 
</pre>

[1601A_Array Elimination](./1_bit_manipulation/1601A_Array%20Elimination.cpp)

<pre>
Everytime select k element, do "bitwise and" for all of that element, 
Calculate x=ai1 & ai2 & … & aik,
Subtract x from each of ai1,ai2,…,aik; all other elements remain untouched.

print all values k, such that it's possible to make all elements of a equal to 0 in a finite number of elimination operations with the given parameter k

- firstly think to solve of zero/one array
- then solve independent bit (if possible) 
- if all a[i] = 1, then select k such that our "and" outcome would be 1, then 1-1 = 0
- count of 1 is a multiple of k

- every bit is independent 
</pre>

#### Some Technique

- [Sum of all Numbers in an array using the Bit Law](./1_bit_manipulation/sum_of_all_bitlaw.cpp)

<pre>
- any number <=1e9 can be represented as sum of(i=0->30) 2<sup>i</sup>*b<sub>i</sub>
- For each bit k, we can calculate the number of numbers that have 1 in the k-th bit. if there are cnt<sub>k</sub>[1] numbers with 1. then the sum of all numbers with 1 in the k-th bit is cnt<sub>k</sub>[1]*2<sup>i</sup>*b<sub>i</sub>
</pre>

```cpp
int n; cin >> n;
vector<int> cnt(30, 0);
for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (int k = 0; k < 30; k++) {
        if (x >> k & 1) {
            cnt[k]++;
        }
    }
}
int ans = 0;
for (int k = 0; k < 30; k++) {
    ans += cnt[k] * (1 << k);
}
cout << ans << endl;
```

- [Sum of Pair XORs](./1_bit_manipulation/sum_of_pair_xor.cpp)

<pre>
- find how much pair possible where first 0 and second 1 ->cnt[0]*cnt[1]*2 (01/10)
</pre>

```cpp
//bruteforce
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        ans += a[i] ^ a[j];
    }
}
//optimise solution
int cnt[30][2];
memset(cnt, 0, sizeof(cnt));
for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 30; k++) {
        if (a[i] >> k & 1) {
            cnt[k][1]++;
        } else {
            cnt[k][0]++;
        }
    }
}
ll ans = 0;
for (int k = 0; k < 30; k++) {
    ll contrib = 1LL * cnt[k][0] * cnt[k][1] * 2;
    ans += contrib * (1 << k);
}
```

- [Sum of Pair ANDs](./1_bit_manipulation/sum_of_pair_ands.cpp)
<pre>
- cnt[1]\*cnt[1]
</pre>

```cpp
//bruteforce
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        ans += a[i] & a[j];
    }
}
//optimise
ll ans = 0;
for (int k = 0; k < 30; k++) {
    ll contrib = 1LL * cnt[k][1] * cnt[k][1];
    ans += contrib * (1 << k);
}
```

- Sum of Pair ORs

- Sum of Subset XORs
<pre>
- half of subset has odd number of count
- 2<sup>cnt[1]-1</sup>
</pre>

```cpp
ll ans = 0;
for (int k = 0; k < 30; k++) {
    if(!cnt[k][1])continue;  //edge case
    ll contrib = (1<<(cnt[k][0]+cnt[k][1]-1));//2^n-1
    ans += contrib * (1 << k);
}
```

- Sum of Subset ANDs

- Sum of Subset ORs

- Number of Subarrays with XOR 0

<pre>
- convert to prefix xor
- p(l,r)-> p[r]^p[l-1]
</pre>

---
