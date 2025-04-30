/*
This problem was asked by Google.

A cryptarithmetic puzzle is a mathematical game where the digits of some numbers are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY
may have the solution:

{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}

Given a three-word puzzle like the one above, create an algorithm that finds a solution.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the puzzle is solvable with the given character assignments
bool solvePuzzleHelper(const string &a, const string &b, const string &sum,
                       int pos, int carry, unordered_map<char, int> &charToDigit, bitset<10> &usedDigits)
{

    // Base case: if we have processed all digits
    if (pos >= sum.size())
    {
        return carry == 0;
    }

    // Calculate sum at current position
    int sumVal = carry;
    if (pos < a.size() && charToDigit.count(a[a.size() - 1 - pos]))
    {
        sumVal += charToDigit[a[a.size() - 1 - pos]];
    }
    if (pos < b.size() && charToDigit.count(b[b.size() - 1 - pos]))
    {
        sumVal += charToDigit[b[b.size() - 1 - pos]];
    }

    char sumChar = sum[sum.size() - 1 - pos];

    // If sumChar is already assigned, check if it matches
    if (charToDigit.count(sumChar))
    {
        if (charToDigit[sumChar] != sumVal % 10)
        {
            return false;
        }
        return solvePuzzleHelper(a, b, sum, pos + 1,
                                 sumVal / 10, charToDigit, usedDigits);
    }

    // Ensure digit is not already used
    if (usedDigits[sumVal % 10])
    {
        return false;
    }

    // Assign the digit to sumChar
    charToDigit[sumChar] = sumVal % 10;
    usedDigits[sumVal % 10] = 1;

    // Recur for next position
    if (solvePuzzleHelper(a, b, sum, pos + 1,
                          sumVal / 10, charToDigit, usedDigits))
    {
        return true;
    }

    // Backtrack if assignment fails
    charToDigit.erase(sumChar);
    usedDigits[sumVal % 10] = 0;
    return false;
}

// Function to assign digits to unique characters and check if assignment is valid
bool assignDigits(const string &a, const string &b, const string &sum, int index,
                  const string &order, unordered_map<char, int> &charToDigit, bitset<10> &usedDigits)
{

    // Base case: If all characters are assigned
    if (index == order.size())
    {
        return solvePuzzleHelper(a, b, sum, 0, 0, charToDigit, usedDigits);
    }

    char ch = order[index];

    // Try assigning each digit to the character
    for (int digit = 0; digit < 10; digit++)
    {
        if (!usedDigits[digit])
        {
            charToDigit[ch] = digit;
            usedDigits[digit] = 1;
            if (assignDigits(a, b, sum, index + 1, order, charToDigit, usedDigits))
            {
                return true;
            }
            // Backtrack if unsuccessful
            usedDigits[digit] = 0;
            charToDigit.erase(ch);
        }
    }
    return false;
}

// Main function to solve Cryptarithmetic puzzle
vector<string> solvePuzzle(string a, string b, string sum)
{
    unordered_map<char, int> charToDigit;
    bitset<10> usedDigits;
    unordered_set<char> uniqueChars;
    string order;

    // Identify unique characters in the input strings
    for (char ch : a + b + sum)
    {
        if (uniqueChars.insert(ch).second)
        {
            order += ch;
        }
    }

    // Assign digits to characters and check validity
    if (assignDigits(a, b, sum, 0, order, charToDigit, usedDigits))
    {
        string x, y, z;
        for (char ch : a)
            x += '0' + charToDigit[ch];
        for (char ch : b)
            y += '0' + charToDigit[ch];
        for (char ch : sum)
            z += '0' + charToDigit[ch];
        return {x, y, z};
    }
    return {"-1"};
}

int main()
{
    string a = "SEND", b = "MORE", sum = "MONEY";
    vector<string> ans = solvePuzzle(a, b, sum);
    for (const auto &res : ans)
    {
        cout << res << " ";
    }
    return 0;
}