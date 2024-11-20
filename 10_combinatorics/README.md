## Combinatorics

### Counting

Two Rule of Basic Counting

      - Rule of Sum

      - Rule of Product
      (Total Way = prev way * next way, ex. contribution technique)

#### factorial

      n! is te number of ways to arrange n distinct objects in a line.

#### combinations

      # order don't matter
      nCr is the number of ways to choose r objects from n distinct objects.
      nCr = n!/(r!(n-r)!)

#### permutations

- order matter

- nPr is the number of ways to choose r objects from n distinct objects and arrange them in line.

- one elements appear exactly one time in each permutation

- nPr = n!/(n-r)!

- It's a arrangement of elements in specific order

- Total number of permutation of sequence with distinct elements of lengths n is n!
<pre>
- next_permutation -> gives immediate next permutation(lexicographical order)
- prev_permutation -> gives immediate previous permutation(lexicographical order)

# also return boolean(have or not)

</pre>

##### Generate all possible permutations

```cpp
int main(){
      int a[] = {1,2,3};
      // if we need all permutation, then we have to sort it
      sort(a,a+n);
      do{
            for(int i=0;i<a.size();i++){
                  cout<<a[i]<<" ";
            }
            cout<<endl;
      }while(next_permutation(a,a+n));
      return 0;
}
```
