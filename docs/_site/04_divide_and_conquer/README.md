### Divide and Conquer

<pre>
Divide and Conquer follow three steps,
- Divide (break the given problem into subproblems of same type)
- Conquer (recursively solve these subproblems)
- Combine (appropriatly combine the answers)
</pre>

example:

- [abc293e_Geometric Progression](./abc293e_Geometric%20Progression.cpp)

  <pre>
  Given integers A, X, and M, find ∑(i=0->X−1)Ai, modulo M
  (1<=A,M<=1e9, 1<=X<=1e12) (m can be any number)
  
  a^0 + a^1 + a^2 ... a^n-1 (mod m) = (a<sup>x</sup>-1/a-1) % mod -> we can't use these formula because m can't always prime .. can be done using extentedgcd
  
  - when we have to do something in k times, then most probably use binary exponentiation(through recursion) to solve faster
  
  - use divide and conquer technique
  
  a<sup>0</sup> + a<sup>1</sup> + a<sup>2</sup> + a<sup>3</sup> + a<sup>4</sup>(a<sup>0</sup> + a<sup>1</sup> + a<sup>2</sup> + a<sup>3</sup>) -> x is odd   
  
  prev(same as odd) + a^x -> x is even 
  </pre>
