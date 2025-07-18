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
