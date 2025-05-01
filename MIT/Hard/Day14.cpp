/*
This problem was asked by MIT.

Blackjack is a two player card game whose rules are as follows:

- The player and then the dealer are each given two cards.
- The player can then "hit", or ask for arbitrarily many additional cards, so long as their total does not exceed `21`.
- The dealer must then hit if their total is `16` or lower, otherwise pass.
- Finally, the two compare totals, and the one with the greatest sum not exceeding `21` is the winner.

For this problem, cards values are counted as follows: each card between `2` and `10` counts as their face value, face cards count as `10`, and aces count as `1`.

Given perfect knowledge of the sequence of cards in the deck, implement a blackjack solver that maximizes the player's score (that is, wins minus losses).

*/

#include <bits/stdc++.h>
using namespace std;

// Card values: 2-10 as is, J/Q/K as 10, A as 1
int cardValue(char c)
{
    if (c >= '2' && c <= '9')
        return c - '0';
    if (c == 'T' || c == 'J' || c == 'Q' || c == 'K')
        return 10;
    if (c == 'A')
        return 1;
    return 0;
}

// Compute all possible hand values (to handle Aces)
int handValues(const vector<char> &hand)
{
    int sum = 0, aces = 0;
    for (char c : hand)
    {
        if (c == 'A')
            aces++;
        sum += cardValue(c);
    }
    return sum;
}

// Dealer plays according to standard rules: hit until 16 or more
int dealerPlay(vector<char> deck, int &deckPos, vector<char> dealerHand)
{
    while (true)
    {
        auto best = handValues(dealerHand);
        if (best >= 16)
            return best;
        if (deckPos >= deck.size())
            break;
        dealerHand.push_back(deck[deckPos++]);
    }
    auto vals = handValues(dealerHand);
    return vals;
}

// DP memoization
struct State
{
    int deckPos, playerSum, playerSoft, dealerUp, playerHasAce;
};

// Returns max score difference from this state
int solve(vector<char> &deck, int deckPos, vector<char> playerHand, vector<char> dealerHand, map<vector<char>, int> &memo)
{
    // Memoization key: deckPos + playerHand + dealerHand
    vector<char> key = {char(deckPos)};
    key.insert(key.end(), playerHand.begin(), playerHand.end());
    key.push_back('|');
    key.insert(key.end(), dealerHand.begin(), dealerHand.end());
    if (memo.count(key))
        return memo[key];

    // Check if player busts
    auto playerBest = handValues(playerHand);
    if (playerBest > 21)
        return memo[key] = -1; // player busts

    // Option 1: Stand
    int dPos = deckPos;
    vector<char> dealerHandCopy = dealerHand;
    // Dealer draws second card if not already
    if (dealerHandCopy.size() == 1 && dPos < deck.size())
    {
        dealerHandCopy.push_back(deck[dPos++]);
    }
    int dealerScore = dealerPlay(deck, dPos, dealerHandCopy);
    int result = 0;
    if (playerBest > 21)
        result = -1;
    else if (dealerScore > 21 || playerBest > dealerScore)
        result = 1;
    else if (playerBest < dealerScore)
        result = -1;
    else
        result = 0;

    // Option 2: Hit (if cards remain)
    int best = result;
    if (deckPos < deck.size())
    {
        playerHand.push_back(deck[deckPos]);
        int hitResult = solve(deck, deckPos + 1, playerHand, dealerHand, memo);
        best = max(best, hitResult);
    }

    return memo[key] = best;
}

int blackjackSolver(const vector<char> &deck)
{
    // Initial deal: player gets 2, dealer gets 1 up
    if (deck.size() < 3)
        return 0;
    vector<char> playerHand = {deck[0], deck[2]};
    vector<char> dealerHand = {deck[1]};
    map<vector<char>, int> memo;
    return solve(const_cast<vector<char> &>(deck), 3, playerHand, dealerHand, memo);
}

int main()
{
    vector<char> deck = {'A', 'K', '5', '9', '2', '3', '4', 'T', 'J', 'Q'};
    int score = blackjackSolver(deck);
    cout << "Maximized score (wins - losses): " << score << endl;
    return 0;
}