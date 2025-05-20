/*
This problem was asked by Two Sigma.

Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability, implement a function rand5() that returns an integer from 1 to 5 (inclusive).

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// returns an integer from 1 to 7
int rand7()
{
    return rand() % 7 + 1;
}

int rand5()
{
    int num;
    do
    {
        num = rand7();
    } while (num > 5);
    return num;
}

int main()
{
    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        cout << rand5() << " ";
    }

    return 0;
}
