/*
This problem was asked by Facebook.

Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
*/
#include <bits/stdc++.h>
using namespace std;

// Reservoir Sampling Technique

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int selectRandomFromStream(istream &stream)
{
    int result = -1;
    int count = 0;
    int x;

    while (stream >> x)
    {
        count++;

        // Replace result with probability 1/count
        int i = rand();
        cout << i << " " << count << " " << i % count  << endl;
        if (i % count == 0)
        {
            result = x;
        }
    }

    return result;
}

int main()
{
    srand(time(0));

    stringstream stream("10 20 30 40 50 60 70 80 90");

    int randomElement = selectRandomFromStream(stream);
    cout << "Randomly selected element: " << randomElement << endl;

    return 0;
}
