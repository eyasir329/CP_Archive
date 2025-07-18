### BitMasks

#### Total Combination + Total Subset

```cpp
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
```

- <code>You are given N≤20 numbers, each up to 10<sup>9</sup>. Is there a subset with sum equal to given goal S?</code>

```cpp
for (int mask = 0; mask < (1 << n); mask++) { //O(2<sup>n</sup>*n)
    long long sum_of_this_subset = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            sum_of_this_subset += a[i];
        }
    }
    if (sum_of_this_subset == S) {
        puts("YES");
        return 0;
    }
}
puts("NO");
```

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