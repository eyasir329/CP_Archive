#### Basic Staff Until cf rating <=1300

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

#### Input with spaces

- cin.getline(s,n);
- using getline() instead of get()

```cpp
      char c[100];
      int n; cin>>n;
      //cin.get(); //without these we find n-1 getline()..
      //because n '\n'..counted as first line. upto '\n' it count a line
      //char ch = getchar();//alternative
      cin.ignore();
      while(n--){
        cin.getline(c,100);
      }
```

### End Of File (EOF)

Input untill end of file

```cpp
  while(cin>>x){
    ans+=x;
  }
```
