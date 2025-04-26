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

### Problem 3 - Hard - Amazon

Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".

[Solution](./Amazon/Hard/Day3.cpp)

---

### Problem 4 - Easy - Amazon

You are given a list of data entries that represent entries and exits of groups of people into a building. An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}

This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}

This means that 2 people exited the building. timestamp is in [Unix time](https://en.wikipedia.org/wiki/Unix_time).

Find the busiest period in the building, that is, the time with the most people in the building. Return it as a pair of (start, end) timestamps. You can assume the building always starts off and ends up empty, i.e. with 0 people inside.

[Solution](./Amazon/Easy/Day4.cpp)

---

### Problem 5 - Easy - Stripe

Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.

[Solution](./Stripe/Easy/Day5.cpp)

---

### Problem 6 - Easy - Microsoft

Implement a URL shortener with the following methods:

- shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
- restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?

[Solution](./Microsoft/Easy/Day6.cpp)

---

### Problem 7 - Medium - Epic

The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1<br>
11<br>
21<br>
1211 <br>
111221 <br>

As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.

[Solution](./Epic/Medium/Day7.cpp)

---

### Problem 8 - Easy - Google

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

[Solution](./Google/Easy/Day8.cpp)

---

### Problem 9 - Hard - Uber

Given an array of integers, return a new array such that each element at index `i` of the new array is the product of all the numbers in the original array except the one at `i`.

For example, if our input was `[1, 2, 3, 4, 5]`, the expected output would be `[120, 60, 40, 30, 24]`. If our input was `[3, 2, 1]`, the expected output would be `[2, 3, 6]`.

Follow-up: what if you can't use division?

[Solution](./Uber/Hard/Day9.cpp)

---

### Problem 10 - Medium - Microsoft

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

[Solution](./Microsoft/Medium/Day10.cpp)

---
