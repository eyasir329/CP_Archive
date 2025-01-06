#### Basic Staff Until cf rating<=1000

## Some Basics

https://codeforces.com/blog/entry/111099

#to be good at competitive programming, you have to know "what to think" and "how to think" when you try a problem.

"What to think":

<pre>
you have to know a decent amount of standard problems / techniques. Sometimes, a problem requires steps / observations that seem obvious if you've already seen them. Other times, you may solve a problem by reducing it to a well-known sub-problem. On the other hand, you may realize you've done something wrong if you "reduce" the problem to something that you know it's unsolvable under the given constraints. All this isn't possible if you don't know those standard problems.
</pre>

"How to think":

<pre>
it comes down to "building" a path to the solution. Sometimes, you need to find new insights / observations by analyzing the process in the statement, manipulating math equations, etc. Other times, you need to find a twist to a well-known technique. You can practice "how to think" by solving ad-hoc / non-standard problems.
</pre>

https://github.com/ShahjalalShohag/Competitive-Programming-A-Complete-Guideline?tab=readme-ov-file#problems-and-algorithms

### How to Read Problem Statements?

- Read the problem statement thoroughly. Try to understand what the problem is asking you to do.
- Identify the key information, constraints, and requirements.
- Break the problem down into smaller parts or subproblems.
- Pay attention to input-output limitations and samples provided in the statement.
- Analyze the sample test cases and try to understand the problem better.
- Check out the notes section of the problem statement. It may contain some useful information.
- Use pen and paper to draw stuff to better understand the problem.
- If you are still confused, try to read the problem statement again.

### How to Solve a Problem?

<details>
  <summary><strong>1. Understand the problem statement</strong></summary>
  <p>This is crucial. Make sure you understand what the problem is asking for, the constraints you have to work with, and the input and output formats. Misunderstanding any part of the problem can lead to a solution that doesn't work.</p>
</details>

<details>
  <summary><strong>2. Break It Down</strong></summary>
  <p>Most problems are easier to solve when broken down into smaller, manageable parts. Identify the different components of the problem and try to understand how they relate to each other.</p>
</details>

<details>
  <summary><strong>3. Make a Plan/Algorithm</strong></summary>
  <p>Once you've broken down the problem, you should have a better idea of how to solve it. Formulate a strategy for solving the problem. Use pen and paper to write down the steps you need to take to solve the problem. You should have a clear idea of your solution before you start writing the code for it.</p>
</details>

<details>
  <summary><strong>4. Write the Code</strong></summary>
  <p>Once you have a solid plan, you can start coding. Write your code carefully, keeping it as clean and clear as possible. This will make it easier to debug and improve later.</p>
</details>

<details>
  <summary><strong>5. Test Your Solution</strong></summary>
  <p>Once you've written your code, you should test it against the sample test cases provided in the problem statement. If your solution passes all the sample test cases, you can submit it. You can also try to come up with your own test cases to check your solution.</p>
</details>

<details>
  <summary><strong>6. Debug and Improve</strong></summary>
  <p>If your solution doesn't pass all the sample test cases, you should debug it. Go through your code line by line and check if it's doing what you expect it to do. If you find any bugs, fix them and test your solution again.</p>
  <code>Print and Check</code>
</details>

<details>
  <summary><strong>7. Optimize Your Code</strong></summary>
  <p>Once your code is working correctly, see if there's any way to make it more efficient. Can you reduce its time complexity? Can you use less memory? Optimizing your code is good practice.</p>
</details>

<details>
  <summary><strong>8. Submit Your Solution</strong></summary>
  <p>Once you're satisfied with your solution, you can submit it. Even if you're confident in your solution, be prepared for the possibility of it being rejected. If it is, use it as an opportunity to learn and improve.</p>
</details>

    # Always try to solve the problem using bruteforce.
    # Then optimize it.

    while(fail){
      - If previous approach fail then try another approaches.
      - Make algorithm first, code it later.
    }

### Verdicts

Once you submit your code, you will get a verdict based on multiple criteria. The most common verdicts are:#### Basic Geometry

<details>
  <summary><strong>Wrong Answer (WA)</strong></summary>
  <p>Your program gave an incorrect output for a specific test case. As a result, it wasn't executed on the remaining test set. Note that the test cases are hidden, so you won't be able to see the test case on which your program failed.</p>
</details>

<details>
  <summary><strong>Compilation Error (CE)</strong></summary>
  <p>Your code failed to compile, likely due to a syntactic error. Solve the error by testing your code locally. Make sure you've selected the correct compiler upon submission.</p>
</details>

<details>
  <summary><strong>Runtime Error (RE)</strong></summary>
  <p>A fault occurred during the execution of your program. This could be due to issues like accessing an out-of-bound array index, dividing by zero, and so on.</p>
</details>

<details>
  <summary><strong>Time Limit Exceeded (TLE)</strong></summary>
  <p>Your program took more time to run than the specified limit. Note that, the execution time is the maximum time taken by your program to run on any test case. So, if your program is taking too much time on a specific test case, then it will get a TLE verdict.</p>
</details>

<details>
  <summary><strong>Memory Limit Exceeded (MLE)</strong></summary>
  <p>Similar to TLE, your program used more memory than the allowed limit.</p>
</details>

<details>
  <summary><strong>Presentation Error (PE)</strong></summary>
  <p>Your program ran successfully, and the output is correct, but the <em>output format</em> is incorrect. This is usually due to a missing space, newline, or an extra space or newline.</p>
</details>

Note that your code first gets compiled and then gets executed. That's why you will get a CE verdict even before it gets executed.

#

### Useful Keyboard Shortcuts

Shortcuts for Windows / Mac are given side by side.

#### General

    1. `Ctrl + S` / `Cmd + S`: Save - Saves the current file or document.
    2. `Ctrl + Shift + S` / `Cmd + Shift + S`: Save As - Saves the current file with a different name or location.
    3. `Ctrl + C` / `Cmd + C`: Copy - Copies the selected text or item.
    4. `Ctrl + V` / `Cmd + V`: Paste - Pastes the copied or cut text or item.
    5. `Ctrl + X` / `Cmd + X`: Cut - Cuts the selected text or item.
    6. `Ctrl + Z` / `Cmd + Z`: Undo - Reverses the last action.
    7. `Ctrl + Y` / `Cmd + Y`: Redo - Reverses the last undo action.
    8. `Ctrl + F` / `Cmd + F`: Find - Opens a search bar to find text within the current document or page.
    9. `Ctrl + A` / `Cmd + A`: Select All - Selects all text or items in the current document or window.
    10. `Alt + Tab` / `Cmd + Tab`: Switch Application - Switches between open applications or windows.
    11. `Ctrl + O` / `Cmd + O`: Open File - Opens a file for editing.
    12. `Ctrl + N` / `Cmd + N`: New File - Creates a new file.

#### Sublime Text Specific

    1. `Ctrl + P` / `Cmd + P`: Go to File - Allows you to search for a file in the current project.
    2. `Ctrl + D` / `Cmd + D`: Multiple Selections - Selects the next occurrence of the current word or selection and allows you to edit them all at once!
    3. `Ctrl + /` / `Cmd + /`: Toggle Comment - Comments out the selected code or text.
    4. `Ctrl + F5` / `Cmd + B`: Build/Run - Builds or runs the current file.
    5. `Ctrl + Shift + D` / `Cmd + Shift + D`: Duplicate - Duplicates the selected text or line.
    6. `Ctrl + K + B` / `Cmd + K + B`: Toggle Sidebar - Shows or hides the sidebar.
    7. `Ctrl + Shift + Up Arrow` / `Cmd + Shift + Up Arrow`: Move Line Up - Moves the current line or selection up by one line.
    8. `Ctrl + Shift + Down Arrow` / `Cmd + Shift + Down Arrow`: Move Line Down - Moves the current line or selection down by one line.
    9. `Ctrl + Shift + N` / `Cmd + Shift + N`: New file - Creates a new file.

Note that you can change the shortcuts in sublime text by going to `Preferences > Key Bindings`.

- [Self-deception: maybe why you're still grey after practicing every day](https://codeforces.com/blog/entry/98621)
- [The Forcing Fallacy](https://codeforces.com/blog/entry/106346)

---

### Data Types, Conditions

https://usaco.guide/general/data-types?lang=cpp
![data_type](https://i.ibb.co.com/mCSZKPF/Screenshot-from-2024-10-02-23-41-19.png)

```
* floating point numbers are not exact.
* so it's generally a bad idea to compare two floating-point numbers for exact equality (==).
* Hence, we should always expect that floating point numbers are slightly o↵.

    if (abs(a-b) < 1e-9) {
        // a and b are equal
    }
```

- The usual floating point types in competitive programming are the 64-bit double
  and, as an extension in the g++ compiler, the 80-bit long double. In most cases,
  double is enough, but long double is **more accurate**.

- Some numbers cannot
  be represented accurately as floating point numbers, and there will be rounding
  errors.

* Note that while floating point numbers are inaccurate, integers up to a certain
  limit can still be represented accurately. For example, using double, it is possible to accurately represent all integers whose absolute value is at most 2<sup>53</sup>.

Booleans require 1 byte (8 bits) of storage, not 1 bit, wasting the other 7 bits of storage. To use less memory, one can use bitsets (std::bitset in C++ / BitSet in Java).

https://usaco.guide/CPH.pdf#page=16

```
long long x = 123456789123456789LL;

subtle error:
    int a = 123456789;
    long long b = a*a;
    cout << b << "\n"; // -1757895751
    solve it using (long long)a*a
```

Usually contest problems are set so that the type long long is enough. Still,
it is good to know that the g++ compiler also provides a 128-bit type \_\_int128_t
with a value range of −2<sup>127</sup> . . . 2<sup>127</sup> − 1 or about −10<sup>38</sup> . . . 10<sup>38</sup>. However, this type
is not available in all contest systems

- unsigned long long (range 0 -> 2^64-1 (1.8\*10<sup><b>19</b></sup>)), occupies 8 bytes of memory.

```cpp
//read, write function of 128 bit integer
#include <bits/stdc++.h>
using namespace std;

__int128 read() {
    string s; cin >> s;
    __int128 ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

string to_string(__int128 x) {
    string s;
    while (x > 0) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void write(__int128 x) {
    cout << to_string(x) << endl;
}

int32_t main() {
    __int128 x = read();
    write(x);
    return 0;
}
```

example:

- [lightoj_equal ju ncpc 23](./1_datatype_conditions/lightoj_equal.cpp)

---

### Large Numbers

<pre>
In Python:
- Arbitrary-Precision: int type can grow as large as memory allows.
- Memory constraints: Size is limited by available system memory.

In Java:
- Arbitrary Precision: BigInteger handles integers limited by available memory.
- Memory Limitation: Size is constrained by system memory, more memory needed for larger numbers.
- Efficiency: Operations on large BigIntegers take more time and memory.
- Practical Example: BigInteger with 100,000 digits works if system memory allows.
</pre>

- https://vjudge.net/problem/CodeForces-913A

```py
#using python
n = int(input())
m = int(input())
twon = 1 << n
print(m % twon)`
```

```java
//using java
import java.math.BigInteger;
import java.util.Scanner;

public class ModuloPower {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        BigInteger m = scanner.nextBigInteger();
        BigInteger twon = BigInteger.valueOf(2).pow((int) n);
        System.out.println(m.mod(twon));
        scanner.close();
    }
}
```

#### Some builtin function

- round, llround
- log -> natural log, log2, log10
- sqrt, cbrt -> cube root
- stoi, stoll, to_string
- is_sorted, rand -> random number (srand(time(0)) seed the random number generator-change everytime)
- isalpa, isdigit, islower, isupper, tolower, toupper

---

#### Other's Things\*

- better to use double instead of float to have more accuracy (not precious 100%)
- it's always better to use integer data type, use same type everywhere.
- we have to be careful to use (NEVER EVER DO, UNTILL HAVE TO DO)
- [Cautions for use inbuild functions](https://codeforces.com/blog/entry/107717)

      log2()->__lg()->give us floor (max set number),
            int ans = 0;
            while(n>1){//0(logn) but accurate
              ans++;
              n/=2;
            }
      pow()->round(pow()),
            int ans = 1;
            for(int i=0;i<b;i++){//log(b) but accurate
              ans*=a;
            }
      sqrt()->//similar to cubic root
            long long ans = sqrt(n);//sqrtl()
            while(ans*ans<=n)++ans;
            while(ans*ans>n)--ans;
            cout<<ans<<endl;

because that are return double values.

[Dhaka ICPC 24 Preli Three Quick Brown Foxes Jump Over a Lazy Chicken]()

- long double is more precise that double//but not use float

- compare two double

        if(a-b<1e-9){
        //they are equal
        }

- cout<<setprecision(10)<<num; //from starting//rounding last digit
- cout<<fixed<<setprecision(10)<<num; //from after dot

- program duration

        clock_t start,end;
        start = clock();//store clock tick (between 1e6)
        ....
        end = clock();
        cerr<<1.0*(end-start)/CLOCKS_PER_SEC<<" sec"<<endl;

- assert(condition) -> if true noting happened otherwise give runtime error. -- using for debugging purpose.

- Multiplying two different Data Types

      -> smaller type gets promoted to the larger type

- common mistakes

  https://codeforces.com/blog/entry/111217

- be careful in v.size()-1 -> because of unsigned int doesn't have negative number

- be careful in multiple test case (all variable need to be reinitialization)

- Constant Optimization

  <pre>
  - constant factors are the hidden constants in the time or space complexity of an algorithm.
  
  some tricks to reduce the hidden constants
  - use '\n' instead of endl
  - efficient i/o -> fastio
  - efficient data structures -> use arrays/vectors instead of deque -> use something that has lower constant factors
  - bit manipulation is faster than arithmetic operations
  - modulo is slower than other arithmetic operations
  - recursion is slower than iteration
  - float/double are slower than integer
  - const is faster than normal variable
  - big data type is slower than small data type
  - accessing big array is slower than small array
  </pre>

- Necessity and Sufficiency

  <pre>
  - a necessary condition is a condition that must be present for a event to occur (ex. prime number always odd)
  - a sufficient condition is a condition that, if present, guarantees that the event will occur (ex. all odd number can't be prime, it mustn't divide any number except(1,same number))
  </pre>

  https://codeforces.com/problemset/problem/1750/A

---

### End Of File (EOF)

Input untill end of file

    while(cin>>x){
      ans+=x;
    }

#

### stringstream

    - input from string

```cpp
string s = "12  13    24";
stringstream ss(s);
cout << ss.str << endl;
int a, b, c; ss >> a >> b >> c;
//alternate
while (ss >> n) {
        cout << n << endl;
}
//separate words from string
getline(cin, s);
stringstream ss(s);
while (ss >> n) {
        cout << n << endl;
}
```

---

### Fast Input & Output

https://usaco.guide/general/fast-io?lang=cpp

- input/output is slow operation

<code>ios::sync_with_stdio(false)</code>

This disables the synchronization between the C and C++ standard streams. By default, all standard streams are synchronized, which in practice allows you to mix C- and C++-style I/O and get sensible and expected results. If you disable the synchronization, then C++ streams are allowed to have their own independent buffers, which makes mixing C- and C++-style I/O an adventure.

<code>cin.tie(nullptr)</code>

This unties cin from cout. Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream.

By default cin is tied to cout to ensure a sensible user interaction.

- we have to use '\n' instead of endl;

      endl -> '\n'+flush(buffer clear)

---

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

      //using log product property
      double sum = 0;
      for(int i=1;i<=n;i++>{
        sum+=log10(i);
      })
      cout<<floor(sum)+1<<endl;

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

      //work byte by byte

      char s[10];
      memset(s,'a',5);//first five replace by 'a'//char need 1 byte
      s[5]='\0';
      cout<<s<<endl;

      //int 4 byte, ll 8 byte
      //initialize by (0/-1) in (int/long long) //accidentaly currect
      int a[10];
      memset(a,0,10*4);//a[0]=4byte
      ->in long long memset(a,0,10*8);//a[0]=8byte
      memset(a,0,a.sizeof(a));//also work in multi-dimension

<code>fill</code>

      //work for every number
      fill(a,a+n,x)

- memset is faster than fill, but both O(n)
- by default global variables is initialize by zero but local variables not
- declare large array globally//because it store in data segment, that are bigger in stack memory segment

#

### Basic Maths

- (num>0) positive number
- (num>=0) non-negative number

https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf
![notation](https://i.ibb.co.com/3ND4tTj/IMG-0043.jpg)

#### floor, ceil and round

    floor-> floor((double)a/b) ~ a/b... ex. floor(7.3)=7
    ceil-> ceil((double)a/b) ~ (a+b-1)/b... ex. ceil(7.3)=8 [(a-1)/b +1]
    round-> round(double(a)/b)... ex. round(7.3)=7, round(7.5)=8

- if num is divisible by 2, then ceil(num)==floor(num), because it has not any fraction.

#### Series

https://www.cuemath.com/summation-formulas/
![formula](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/correction-1718966351.jpg)

- arithmetic progression - difference beteen adjacent two numbers are same.

formula can generate by: n\*(first+last)/2;

- geometric progression - ratio between two consecutive numbers is constant.

r > 1 => s = a*(r<sup>n</sup>-1)/(r-1) <br>
r = 1 => s = na #ar<sup>n-1</sup> formula <br>
0 < r < 1 => s = a*(1-r<sup>n</sup>)/(1-r) <br>

<code>Notes : check overflow(if then apply as long long(1LL)), oterwise give wrong answer.
</code>

![useful math functions](https://miro.medium.com/v2/resize:fit:1023/1*gQ6RMxhKkPauq92rqFv9-Q.jpeg)

#### Harmonic Series

https://scipp.ucsc.edu/~haber/archives/physics116A10/harmapa.pdf
https://www.math.drexel.edu/~tolya/123_harmonic.pdf

<img src="https://steemitimages.com/640x0/http://i.imgur.com/vifeHmZ.png" alt="harmonic series" style="height: 60px;">

sum <= floor(log2(n)) + 1

    int n = 1e6;
    ll sum = 0; //O(N*N) not //O(NlogN) //because of j+=i
    for(int i=1;i<=n;i++){
      for(int j=i;j<=n;j+=i){//look like -> n*harmonic
        sum+=j;
      }
    }
    //also same for this
    for(int i=1;i<=n;i++){
      for(int j=1;i*j<=n;j++){ // j = n/i
        sum+=j;
      }
    }

https://codeforces.com/blog/entry/118001

#### Some formulas

<img src="https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/perimeter-formulas-1622782913.png" alt="Perimeter Formulas" height="839">

- [Triangles](https://www.cuemath.com/geometry/triangles/)
- [Median & Centroid](https://www.khanacademy.org/math/geometry-home/triangle-properties/medians-centroids/v/triangle-medians-and-centroids)

      sum of natural numbers = (n * (n + 1)) / 2;
      sum of square of natural numbers = (n * (n + 1) * ((2 * n) + 1)) / 6;
      sum of cubes of natural numbers = ((n * n) * (n + 1) * (n + 1)) / 4;
      nth term of an arithmetic sequence = a + ((n - 1) * d);
      sum of arithmetic series (number of terms * average of first and last item) = (n * ((2 * a) + ((n - 1) * d))) / 2;
      nth term of geometric sequence = a * pow(r, n - 1);[a = first_term, r = common ration];
      sum of geometric sequence = (a * (pow(r, n) - 1)) / (r - 1);[r != 1];
      sum of an infinite geometric sequence = a / (1 - r);[r < 1];

      area:

      semi perimeter (triangle)s = 1/2 * (a + b + c);
      area(triangle) = (1/2 * base * height) = (1/2*a*b*sin(C)) = sqrt(s * (s - a) * (s - b) * (s - c));
      area(right triangle) = (1/2 * a * b);
      area(equilateral triangle) = (a^2 * sqrt(3)) / 4; [a = side_length]
      area(equilateral triangle) = (h^2 * sqrt(3)) / 3; [h = altitude, height]
      area(rectangle) = base  * height;
      area(square) = base^2 = (1/2 * diagonal^2);
      area(parallelogram) = (base * height) = a*b*sin(C);
      area(rhombus) = (1/2 * d1 * d2); [d1 = diagonal1, d2 = diagonal2]
      area(trapezoid) = (1/2 * h * (b1 + b2)); [b1 and b2 are two parallel side, h = distance between d1 and d2]
      area(regular polygon) = (1/2 * a * p) [a (apothem)= the distance from the center to the midpoint of one of its side, p = perimeter]
      area(circle) = (pi * r^2) = (pi * d^2) / 4; [d = diameter = 2 * r];
      area(sector of circle) = ((n/360) * pi * r^2);[n = measure of the central angle]

      circumference / perimeter
      circumference(circle) = (2 * pi * r);
      length of an arc of a circle = ((n/360) * 2 * pi * r);

---

#### Divisors, Multiple, Modulo

##### Modulo

<pre>
- make sure after each operation, the result is between 0 and m-1
- keep eyes in overflow.
- do not work in division in general ways.
- bitwise operation do not work with modular arithmetic.
</pre>

<pre>
    (x + y) mod m = (x mod m+ y mod m) mod m
    (a - b) mod m = (a mod m - b mod m + m) mod m
    (x · y) mod m = (x mod m· y mod m) mod m
    x^n mod m = (x mod m)^(n mod m-1)
</pre>

example:

- Find a closed form for the remainder of a ÷ m, where a, m ∈ Z+

  <pre>
  Because finding the remainder directly does not seem like an easy task, we first look for the quotient q. Because the quotient is the greatest number of times m goes into a, it is the integer part of a/m . But how do we truncate the fractional part? Apply the floor function! 
  
  q =⌊a/m⌋
  Our remainder becomes a − mq = <b>a − m⌊a/m⌋</b> <-- a % m
  </pre>

##### Divisors

```cpp
for(int i=1;i<=n;i++){
  if(n%i==0){
    cout<<i<<" ";
  }
}
```

- (b | a) -> b divide a

example:

- [2029A_Set]()
- One of the first 1234567 positive integers is chosen at random. Compute the
  probability that it is divisible by 3?

  <pre>
  -> Pattern Identification:
    Every third number in the sequence of positive integers is divisible by 3:
    - Example: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, ...
    - From this pattern, it's clear that every package of three numbers contains exactly **one** divisible by 3.
  
  -> Count Numbers Divisible by 3:
      To find how many numbers in the first 1234567 are divisible by 3: floor(1234567/3)
  
  -> Calculate Probability:
      The probability of selecting a number divisible by 3 is:
      P = Numbers Divisible by 3 / Total Numbers = 411522 / 1234567 ≈ 0.33333306
  
  -> Result:
      This matches the expected approximation of 1/3, derived from the pattern of divisibility.
  
  - The probability `P ≈ 1/3` arises naturally from the definition of divisibility.
  - The slight deviation from `1/3` comes from the truncation during integer division.
  
  This method demonstrates how understanding divisibility patterns simplifies complex calculations.
  </pre>

- Find all integers x for which it can be said that the positive integer 2x + 9 divides the positive integer 3x + 4?

  <pre>
  From the problem statement, we can extract the following requirements:
  x ∈ Z
  2x + 9 ∈ Z+ =⇒ x ∈ Z≥−4
  3x + 4 ∈ Z+ =⇒ x ∈ Z≥−1
  3x + 4 ≥ 2x + 9 =⇒ x ∈ Z≥5
  Additionally, we require
  (3x + 4)/(2x + 9) = 1 + (x − 5)/(2x + 9) =⇒ (x − 5)/(2x + 9) ∈ Z≥0.
  This secondary requirement means that either x = 5 or
  x − 5 ≥ 2x + 9 =⇒ x ∈ Z≤−14.
  The second case is clearly impossible due to the strict x ∈ Z≥5 requirement from earlier, so the only valid integer x is 5 .
  </pre>

---

#### Primes

example:

- Prove that, for all primes p, the smallest positive integer whose factorial is divisible by p is p itself.

  <pre>
  It is trivial by inspection that p satisfies this condition. Let the smallest positive such
  integer be k. For the sake of contradiction, assume that k < p and p|k!. Then, k! is the product of all positive integers less than p and p is present in the prime factorization of k!. Some of the positive integers in this product are themselves primes less than p, while others are less than p and have unique prime factorizations involving only primes less than p by the fundamental theorem of arithmetic. Thus, p cannot be present in prime factorization of k!, establishing contradiction. This means that k = p. 
  </pre>

#### GCD, LCM

[Properties of GCD function](https://codeforces.com/blog/entry/95694)

<pre>
lcm(a,b) = (a*b)/gcd(a,b)
</pre>

example:

https://aryansh-s.github.io/assets/pdf/The_Art_of_Modular_Arithmetic.pdf p29_sol

- What is the largest positive integer that divides 40 and 78(gcd(a,b))? What about the smallest positive integer divisible by 40 and 78(lcm(a,b))?

  <pre>
  - Greedily, if we want to find the largest positive integer that divides 40 an 78, we need to selectively multiply together the largest power of each prime divisor common to both.
  - To find the smallest positive integer divisible by both 40 and 78, we again take a greedy approach: selectively multiply together the smallest power of each prime divisor that satisfies the divisibility requirement. 
  </pre>

- [AOPS_1951 AHSME Problems/Problem 19](https://artofproblemsolving.com/wiki/index.php/1951_AHSME_Problems/Problem_19)

  <pre>
  A six place number is formed by repeating a three place number; for example, 256256 or 678678, etc. Any number of this form is always exactly divisible by(gcd of all numbers of this forms)?
  
  -> The number abcabc can be rewritten as 1000abc + abc (constructively, think of shifting the second abc three places to the right to make room for the first abc). Therefore, it is just 1001abc, and since nothing more can be said about abc, the answer is 1001 .
  </pre>

---

### Array

<pre>
- each element takes 4 bytes (on most systems).

- int a[n][n], memory required -> Memory required (bytes) = n<sup>2</sup>×4
  n = 512 (since 512<sup>2</sup>×4=1MB), n = 1000 (4MB), n = 10000 (400MB)

General Guidelines
  - Use dynamic allocation for large arrays to avoid stack overflow.
  - Ensure you have enough physical memory (RAM) to support the desired size.
  - Avoid unnecessarily large arrays; consider using sparse matrix representations if the array contains many zeros.
</pre>

```cpp
// stack allocation
int n = 500; // Works fine on most systems
int a[500][500]; // Requires 1 MB memory (approx.)

int m = 1000; // May cause stack overflow
int b[1000][1000]; // Requires 4 MB memory (approx.)
```

```cpp
//heap allocation (dynamic memory)
int main() {
    int n = 10000; // Larger sizes possible with heap
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // Use the array (example: initialize with 0)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

```cpp
//std::vector
int main() {
    int n = 10000; // Works for large n if enough memory is available
    vector<vector<int>> a(n, vector<int>(n, 0)); // Initialize with 0

    // Access elements
    a[0][0] = 1;
    a[n-1][n-1] = 2;

    cout << a[0][0] << " " << a[n-1][n-1] << endl;
    return 0;
}
```

#### Something on Pair-Wise

<pre>
- total number of pair (n*(n-1))/2

- we can fixed i or j(one), then calculate -> in pair/triple type of problems
</pre>

_example:_

- find the total sum of a<sub>i</sub>\*a<sub>j</sub>, where 1<=i, j<=n, n=1e5

  <pre>
  # we have to do it in one loop (fixing i)
  
  for 1 to n: sum += ai * total_sum
  </pre>

- find the total sum of a<sub>i</sub>\*a<sub>j</sub>, where 1<=i<j<=n, n=1e5

  <pre>
  # we have to do it in one loop (fixing j)
  
  for 1 to n: sum += aj * preSum[j-1]
  </pre>

#### Subarray

<pre>
- total number of subarray -> n*(n+1)/2
</pre>

```cpp
const int N = 1e6 + 9;
int a[N];

void print(vector<int>&v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int32_t main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    vector<int>v;
    for (int j = i; j <= n; j++) {
      v.push_back(a[j]);
      print(v);
    }
    cout << endl;
  }
  return 0;
}
```

_example:_

- num of subarray whose sum is divisible by k

  <pre>
  in [l,r] subarray : (p[r]-p[l-1])%k=0
                     => p[r]%k-p[l-1]%k=0
                     => p[r]%k=p[l-1]%k
  </pre>

- num of subarray whose xor = 0

  <pre>
  in [l,r] subarray : (p[r]^p[l-1]) = 0
                  => p[r] = p[l-1] (using xor property)                  
  </pre>

#### Subsequence

#### Subset

- total number of subset -> 2<sup>n</sup>-1

---

### String

<pre>
s = s + 'a' -> O(N) -> access whole string
s += 'a' -> O(1) -> not accesssing whole string
</pre>

#### Input with spaces

- cin.getline(s,n);
- using getline() instead of get()

      char c[100];
      int n; cin>>n;
      //cin.get(); //without these we find n-1 getline()..
      //because n '\n'..counted as first line. upto '\n' it count a line
      //char ch = getchar();//alternative
      cin.ignore();
      while(n--){
        cin.getline(c,100);
      }

<code>string(int, char)</code> n=3, c='a' => "aaa"

<code>char c = num + '0'</code>
<code>int num = 'c' - '0'</code>

https://www.geeksforgeeks.org/cpp-string-functions/

#### Binary String

- [2029B_Replacement]()
- [1971D_Binary Cut]()
- [1913B_Swap and Delete]()
- [1837C_Best Binary String]()
- [2030C_A TRUE Battle]()

---

### Loops, Sorting

---

### Balanced Bracket

example:

- [1860A_Not a Substring]()

---

### Some Technique

#

- Sort the Distance from Origin

- Sort 5D Points
- String Sort
- Balanced Bracket
- Sliding Window Technique
- Kth Smallest in Each Prefix
- Unique Elements
- Remove B from A
- Word Frequency
- Occurrences
- Update and Remove Query
- Number of Pair of Strings such that d(a,b)<=k in Binary String

#
