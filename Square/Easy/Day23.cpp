/*
This problem was asked by Square.

The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N. The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark [4, 6, 8, ...] (multiples of two), then [6, 9, 12, ...] (multiples of three), and so on. Once we have done this for all primes less than N, the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely (that is, without taking N as an input).
*/

#include <bits/stdc++.h>
using namespace std;

class PrimeGenerator
{
    int current;

public:
    PrimeGenerator() : current(2) {}

    int next()
    {
        while (true)
        {
            if (is_prime(current))
            {
                return current++;
            }
            current++;
        }
    }

    bool is_prime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};

vector<int> sieve_of_eratosthenes(int n)
{
    vector<int> primes;
    vector<int> vec(n + 1, 1);
    vec[0] = 0;
    vec[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (vec[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
                vec[j] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (vec[i] == 1)
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    int n = 100;
    vector<int> primes = sieve_of_eratosthenes(n);
    cout << "Primes less than " << n << ": ";
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
    cout << endl;

    // Bonus
    // PrimeGenerator p;
    // int i = 0;
    // while (i < INT_MAX)
    // {
    //     cout << p.next() << " ";
    // }

    return 0;
}
