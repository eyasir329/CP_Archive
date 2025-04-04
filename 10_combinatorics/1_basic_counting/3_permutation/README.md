### <u> Permutations</u>

<pre>
- <b>order matter</b>
- nPr is the number of ways to choose r objects from n distinct objects and arrange them in line.
- one elements appear exactly one time in each permutation
- nPr = n!/(n-r)!
- It's a arrangement of elements in specific order
- Total number of permutation of sequence with distinct elements of lengths n is n!
</pre>

![perm1](https://i.ibb.co.com/MsQSS3f/IMG-0234.jpg)
![perm2](https://i.ibb.co.com/d20XP5f/IMG-0235.jpg)
![perm3](https://i.ibb.co.com/njVNnGK/IMG-0237.jpg)
![perm4](https://i.ibb.co.com/kcMdRjn/IMG-0236.jpg)
![perm5](https://i.ibb.co.com/ggwvmYV/IMG-0238.jpg)

---

### <u>Permutations with Indistinguishable Objects</u>

![pr1](https://i.ibb.co.com/QJ8rJWj/IMG-0271.jpg)
![pr2](https://i.ibb.co.com/NY61W8R/IMG-0272.jpg)
![pr3](https://i.ibb.co.com/KNHMm4w/IMG-0273.jpg)
![pr4](https://i.ibb.co.com/vDW25vF/IMG-0274.jpg)
![pr5](https://i.ibb.co.com/6YVbC4r/IMG-0275.jpg)

example:

- [300C_Beautiful_Numbers](./300C_Beautiful_Numbers.cpp)

    <pre>Vitaly is a very weird man. He's got two favorite digits a and b. Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b. Vitaly calls a good number excellent, if the sum of its digits is a good number.
  
    Now Vitaly is wondering, how many excellent numbers of length exactly n are there. As this number can be rather large, he asks you to count the remainder after dividing it by 1000000007 (1^9 + 7).
  
    sum_of_digits = i * a + (n - i) * b;</pre>

- https://www.codechef.com/problems/NWAYS

---

<pre>
- next_permutation -> gives immediate next permutation(lexicographical order)
- prev_permutation -> gives immediate previous permutation(lexicographical order)

# also return boolean(have or not)
</pre>

- <u>Generate all possible permutations</u>

```cpp
int main() {
    int a[] = {1, 2, 3};
    // if we need all permutation, then we have to sort it
    sort(a, a + n);
    do {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}
```
