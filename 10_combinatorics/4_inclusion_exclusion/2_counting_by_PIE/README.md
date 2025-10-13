## Counting by Principle of Inclusion & Exclusion

https://cp-algorithms.com/combinatorics/inclusion-exclusion.html

- 2 types

![cpi1](cpi1.png)

- 3 types

![cpi2](cpi2.png)

- for multiple

![cpi3](cpi3.png)

- those equation is increasing very first. (after some we can't do it manually)

![cpi4](cpi4.png)

- examples:

> - how much english word whose length is 10? (26^10)
> - now 10 length words where it has atleast 1 a, atleast 1 b, atleast 1 c?

### Sometimes easier to count inverse

- reverse of (and -> or)

![cpi5](cpi5.png)
![cpi6](cpi6.png)
![cpi7](cpi7.png)

- for multiples

![cpi8](cpi8.png)
![cpi9](cpi9.png)

## Recap for Counting by PIE

![pie1](pie1.png)

- untill now conditions is similar
- now condition is not similar

examples1:

![pie2](pie2.png)

> 1 to n, which is divisible by at least one of those numbers?

![pie3](pie3.png)

> if divisible by multiple numbers then it also divisible by their lcm

![pie4](pie4.png)

> - 2^k terms has, where k is the size of a set; k<=20
> - like this problems -> we have to generate all possible subset of conditions

> generate all possible subset using bitmask

![pie5](pie5.png)

> we have to enclose left shift & right shift operator inside braces because it's precedence is too low

```cpp
int k; cin >> k;
vector<int> input(k);
for (int i = 0; i < k; i++) {
    cin >> input[i];
}
for (int mask = 0; mask < (1 << k); mask++) {
    vector<int> subset;
    //mask = 10 ? binary = 1010
    for (int i = 0; i < k; i++) { //checking each bit
        if ((1 << i)&mask) { //is ith bit on?
            subset.push_back(input[i]);
        }
    }
    for (auto x : subset) {
        cout << x << " ";
    }
    cout << endl;
}
```

```cpp
//for each subset
int y = lcm(subset);
if(subset.size()%2==0){
  ans -= n/y;
}else{
  ans += n/y;
}
```

> - for PIE size == even -> (-ve) otherwise (+ve)

examples2:
![pie6](pie6.png)

> 1 to L how much x, which is coprime to n?

![pie7](pie7.png)
![pie8](pie8.png)
![pie9](pie9.png)
![pie10](pie10.png)
![pie11](pie11.png)

### Mobius Function

> we can use meu function instead of bitmask
> https://codeforces.com/blog/entry/53925

![pie12](pie12.png)
