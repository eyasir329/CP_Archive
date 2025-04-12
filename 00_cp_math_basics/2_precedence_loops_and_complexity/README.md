- [Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

  ![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjDm_FtxeGKfyUhd-byPJ8Y34EKecgA7GwKXuF_IxJPrE4TKqzOsdZKybAkHC42NM7rs74hUzIklDTlhFCzq1RdLJm4sonfEEuA6fFSbP9SDXUfCicb2HO2kFimKV58CGr9Rx3RYsXR04Ie/s1600/untitled_thumb.png)

---

### Exponential and Logarithmic Functions

- a<sup>k</sup> = x -> log<sub>a</sub>(x) = k;

|  x  |  2<sup>x</sup>  | log<sub>2</sub>(Y)</br> (Where Y=2<sup>x</sup>) |
| :-: | :-------------: | :---------------------------------------------: |
| 20  | 10<sup>6</sup>  |                      19.9                       |
| 30  | 10<sup>9</sup>  |                      29.9                       |
| 60  | 10<sup>18</sup> |                      59.8                       |

- some number, everytime divide it by 2(k) until became 1, how much operation need? (floor(log<sub>k</sub>N))

[2020A_Find Minimum Operations](./5_basic_maths/divisors_modulo/2020A_Find%20Minimum%20Operations.cpp)

https://www.cuemath.com/log-formulas/

![log properties](https://mathgotserved.com/x/cdn/?https://storage.googleapis.com/wzukusers/user-19977666/images/5866e108c1fb01HOWam7/Logarithm-properties-ultimate-cheat-sheet-formula-product-quotient-power-root-inverse-identity-zero-change-equality-reciprocal_d600.PNG)

- log<sub>3</sub>100 = log2(100)/log2(3)
- number of digit in other number system :- floor(log<sub>k</sub>N))+1 (k base)
- how much digit in n! (n<=1e5)

```cpp
//using log product property
double sum = 0;
for (int i = 1; i <= n; i++ > {
sum += log10(i);
})
cout << floor(sum) + 1 << endl;
```

#

### Time and Space Complexity

https://usaco.guide/bronze/time-comp?lang=cpp

- Big O notation, which expresses
  worst-case time complexity as a function of
  $n$
  as
  $n$
  gets arbitrarily large.

![Time Complexity](https://miro.medium.com/v2/resize:fit:1400/1*xq73u1N7ZsTE2MJ9jsj0CA.png)

- 1s <--> 10<sup>8</sup> Operations

        - bool of array -> n*1byte (1MB -> byte/1e6)(8 time slower than bool of vector)
        - bool of vector/bitset -> n*1bit
        - int of vector -> n*4byte (1byte->8bit)
        - 256MB memory limit, maxsize of my array?
                4x/1e6 = 256
                -> x = 6.4e7// bitset can be 1e9+

### Algorithm Complexity Table

https://usaco.guide/PAPS.pdf#page=99

![maxn](https://i.ibb.co.com/gJcN1Q4/Screenshot-from-2024-10-11-00-22-26.png)

https://usaco.guide/bronze/time-comp?lang=cpp

### Common Complexities and Constraints

- Mathematical formulas that just calculate an answer: **O(1)**
- Binary search: **O(log⁡n)**
- Sorted set/map or priority queue: **O(log⁡n)** per operation

- Prime factorization of an integer, or checking primality or compositeness of an integer naively: **O(n)**
- Reading in n items of input: **O(n)**
- Iterating through an array or a list of nn elements: **O(n)**
- Sorting: usually O(nlog⁡n) for default sorting algorithms (mergesort, Collections.sort, Arrays.sort)
- Java Quicksort Arrays.sort function on primitives: **O(n<sup>2</sup>)**

- Iterating through all subsets of size k of the input elements: **O(n<sup>k</sup>)**. For example, iterating through all triplets is **O(n<sup>3</sup>)**
- Iterating through all subsets: **O(2<sup>n</sup>)**~(1<<n)
- Iterating through all permutations: **O(n!)**

---

#### Memory Initialization

<code>memset</code>

```cpp
//work byte by byte

char s[10];
memset(s, 'a', 5); //first five replace by 'a'//char need 1 byte
s[5] = '\0';
cout << s << endl;

//int 4 byte, ll 8 byte
//initialize by (0/-1) in (int/long long) //accidentaly currect
int a[10];
memset(a, 0, 10 * 4); //a[0]=4byte
->in long long memset(a, 0, 10 * 8); //a[0]=8byte
memset(a, 0, a.sizeof(a)); //also work in multi-dimension
```

<code>fill</code>

      //work for every number
      fill(a,a+n,x)

- memset is faster than fill, but both O(n)
- by default global variables is initialize by zero but local variables not
- declare large array globally//because it store in data segment, that are bigger in stack memory segment

#
