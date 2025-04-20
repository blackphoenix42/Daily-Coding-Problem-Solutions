# Daily-Coding-Problem

Questions and Solutions in cpp to problems from the daily mails of the [DailyCodingProblem](https://www.dailycodingproblem.com)

The below Problem Headings also tells us the level of the question and the company.

---

### Problem 1 - Hard - Google

Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],<br>
 [2, 6, 9, 14, 22, 25],<br>
 [3, 8, 10, 15, 25, 30],<br>
 [10, 11, 12, 23, 30, 35],<br>
 [20, 25, 30, 35, 40, 45]]<br>
And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers in the matrix smaller than 6 or greater than 23.

[Solution](./Google/Hard/Day1.cpp)

---

### Problem 2 - Medium - Facebook

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split it up into two subsets that add up to the same sum.

[Solution](./Facebook/Medium/Day2.cpp)

---
