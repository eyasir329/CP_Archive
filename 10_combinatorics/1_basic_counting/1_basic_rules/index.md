---
title: "1 basic rules"
nav_order: 1
---


<pre>
- How to solve Counting problem?

  firstly - breakdown the problem
  then - how much (choice/option/select) for each part
</pre>

### Two Rule of Basic Counting

<pre>
- Rule of Sum (either/or)
- Rule of Product (and)

(Total Way = prev way * next way, ex. contribution technique)
</pre>

#### <u>Rule of Sum</u> (one event, multiple ways)

<pre>
- If a task can be done in either one of n1 ways <b>or</b> in one of n2 ways, where the two sets of ways are disjoint, then there are n1+n2 ways to complete the task.

- If A and B are two disjoint sets (i.e., A∩B=∅),the total number of elements in their union is given by:∣A∪B∣=∣A∣+∣B∣
</pre>

example:

<pre>
- A. A woman has decided to shop at one store today, either in the north part of town or the south part of town. If she visits the north part of town, she will shop at either a mall, a furniture store, or a jewelry store. If she visits the south part of town then she will shop at either a clothing store or a shoe store. How many possible shops are there?ore or a shoe store. How many possible shops are there?

-> 2 + 3 = 5

- B. computer science instructor has two colleagues. One colleague has three textbooks on the analysis of algorithms and the other has 5 textbooks. If n denotes the maximum number of different books on this topic that this instructor can borrow, give the possible value(s) for n.

-> min: 5, max: 8
</pre>

<pre>
- how many number with at most 4 digit? -> (9*10*10*10)+(9*10*10)+(9*10)+9
</pre>

---

#### <u>Rule of Product</u> (2 events (or more))

<pre>
- If there are m ways that one event can occur and n ways that another event can occur, then there are m x n ways that both events can occur.

- If A1, A2, ... ,Am are finite sets, then the number of elements in the Cartesian product of these sets is the product of the number of elements of each set.
</pre>

example:

<pre>
- A. During a local campaign, three republican and two democratic candidates are nominated for president of the school board. How many possibilities exist for a pair of candidates (one from each party) to oppose each other for the eventual election.

-> 3*2 = 6

A student ID is made of 3 upper-case letters followed by two digits.
B. How many possible IDs exist?
   26 * 26 * 26 * 10 * 10 = 1,757,600

C. How many IDs are possible if duplicate letters or numbers aren't allowed?
   26 * 25 * 24 * 10 * 9 = 1,404,000

D. How many student IDs are possible with an even number of "A"s?
   - For 0 "A"s:
     25 * 25 * 25 * 10 * 10 = 1,562,500
   - For 2 "A"s:
     3 * (25 * 25 * 10 * 10) = 1,562,500 + 3 * 2,500 = 1,570,000
</pre>

<pre>
- 4 digit number how many? -> 9 * 10 * 10 * 10
- 4 digit even number? -> 9 * 10 * 10 * 5 
- 4 digit even palindrome number? -> 4 * 10 * 1 * 1
- 5 digit palindrome number? -> 9 * 10 * 10 * 1 * 1
- how many 4 digit number with unique digit? -> 9 * 9 * 8 * 7
</pre>

- https://cses.fi/problemset/task/1617

---

- <u>The Complement Rule and Complex Counting Problems</u> <br>
(at least -> Complement of none)
<pre>
- Sometimes when dealing with enumeration problems, it is easier to answer the opposite problem. That is, we can find all outcomes for which our condition isn't true, then subtract that total from our sample space, or total number of outcomes.

- IDs with Repetition = Sample space - no repeats => (26^3*10^2) - (26*25*24*10\*9)
</pre>

example:
![p1](https://i.ibb.co.com/XtfkHYX/IMG-0223.jpg)

<pre>
Determine the number of 6 digit integers (no leading zeros) in which:
A. Digis may be repeated
-> 9*10*10*10*10*10 = 900,000

B. No digit may be repeated
-> 9*9*8*7*6*5 = 136,080

C. No digit may be repeated, even number
-> last digit 0 or (2,4,6,8) => (9*8*7*6*5*1) + (8*8*7*6*5*4) = 68,800 

D. Digits may be repeated, even number
-> 9*10*10*10*10*5 = 450,000

E. No digit may be repeated, divisible by 5 
-> last digit 0 or 5 => (9*8*7*6*5*1) + (8*8*7*6*5*1) = 28,560

F. No digit may be repeated, divisible by 4 
-> last m=2(2^m) digit is divisible by 4 => (last two digit -> have one 0 or not zero) => (8*7*6*5*6(0X|X0)) + (7*7*6*5*16(24-6-2(44,88))) = 33,600
</pre>

<pre>
- 4 digit number which have at least one 0? (total - no zero) -> 9*10*10*10 - 9*9*9*9 
- 4 digit number which have at least two consecutive digits are same? -> 9*10*10*10 - 9*9*9*9
</pre>

---

### The Subtraction and Division Rules

#### <u>The Subtraction Rule - a.k.a. Principle of Inclusion-Exclusion</u>

<pre>
- If a task can be done in either n1 ways or n2 ways, then the total number of ways to do the task is n1+n2 minus the number of ways to do the task that were counted in both n1 and n2. 

A ∪ B = A + B − A ∩ B
</pre>

example:

<pre>
A. How many bit strings of length 7 either start with "1" bit or end with the 3 bit "000"?
-> (1*2*2*2*2*2*2) + (2*2*2*2*1*1*1) - (1*2*2*2*1*1*1) = 64 + 16 - 8 = (64-8)56 + (16-8)8 + 8 = 72

B. A software company receives 200 applications from collage graduations for a job planning a new ed.tech application. If 107 of the applicants majored in web development, 116 majored in computer science, and 23 majored in something else, how many applicants majored in both web development and computer science?
-> 200 - 23 = 107 + 116 - A ∩ B
</pre>

---

#### <u>The Division Rule</u>

<pre>
- There are n/d ways to do a task if it can be done using a procedure that can be carried out in n ways, where there are d corresponding outcomes per group.

- Or, If the finite set A is the union of n pairwise disjoint subsets each with d elements, then n = |A|/d

- In terms of functions: If f is a function from A to B, where both are finite sets, and for every value y belongs to B there are exactly d values x belongs to A such that f(x)=y, then |B|=|A|/d
</pre>

example:
![dr](https://i.ibb.co.com/F5VVn5h/IMG-0224.jpg)

<pre>
The arrangement (ABCD) is same as (BCDA,CDAB,DABC) because each person has the same left and right neighbors. Since there are 4 possible rotations for any seating order(one for each person being first), every unique circular arrangement is counted 4 times in the linear arrangement. To find the number of unique circular arrangements, we divide the total linear arrangements by the number of rotations.
-> 24/4 = 6  
</pre>

---

## Basic Counting Problems

https://flexbooks.ck12.org/cbook/ck-12-college-precalculus/section/14.2/primary/lesson/counting-with-permutations-and-combinations-c-precalc/

<pre>
- Probability is a mathematical way of calculating how likely an event is to occur.

P(event) = (# of favorable outcomes)/total outcomes

- The method of calculating the number of total outcomes can be stated as a general rule called the Counting Principle.
- The Counting Principle states that the number of choices or outcomes for two independent events.

Total outcomes for A and B = (# outcomes for A)*(# outcomes for B)
</pre>

- <u>The Counting Principle</u>
<pre>
Consider choice A with 3 options (A1,A2,A3), and choice B with 2 options (B1,B2). If you had to choose an option from A and then an option from B, the overall total number of options would be 3⋅2=6. The options are A1B1,A1B2,A2B1,A2B2,A3B1,A3B2.


- A decision tree is a graph that models the options possible at each stage of an experiment.
</pre>
![cp](https://i.ibb.co.com/hf4GG3w/Screenshot-from-2025-01-08-19-08-27.png)

---
