//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <iostream>

/*
 * A prime number is any number greater than 1 that is only divisible by 1 and itself
 */
bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;
    }

    // check if any number between 2 and n can divide it
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0) return false; // not a prime if it can be divided (whole) by any number between the range.
    }

    return true;
}

std::vector<int> findGap(int gap, int a, int b)
{
    int start = (a % 2 == 0 ? a + 1 : a);
    for (int i = start; i <= b; i++)
    {
        if (isPrime(i))
        {
            int second = i + gap;
            if (second > b) break; // ensure second is within the range.
            // check if second is prime too
            if (isPrime(second))
            {
                return {i, second};
            }
        }
    }

    return {}; // if nothing found
}

/*
 * Using Sieve of Eratosthenes.
 * Build a prime sieve up to n.
 * A prime number is any number greater than 1 that is only divisible by 1 and itself
 */
std::vector<bool> buildSieve(const int n)
{
    // for the sieve, we assume that all numbers are prime numbers
    std::vector<bool> isPrime(n + 1, true); // n+1 to have n inclusive
    isPrime[0] = isPrime[1] = false; // set 0 and 1 as not prime

    for (int i = 2; i * i <= n; i++) // check up to the square too of n;
    {
        if (isPrime[i])
        {
            // If the number is marked as prime, then we mark all the multiples as not prime.
            // This is because those numbers can be divided by other numbers apart from 1 and itself.
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    // returns a sieve containing prime numbers as true and others as false.
    return isPrime;
}

std::vector<int> findGapSieve(const int gap, const int a, const int b)
{
    int start = (a % 2 == 0 ? a + 1 : a);
    if (b < a || b - a < gap) return {};

    const auto sieve = buildSieve(b);
    for (int i = start; i + gap <= b; i++)
    {
        // directly index the sieve at that point
        if (sieve[i] && sieve[i + gap])
        {
            return {i, i + gap};
        }
    }
    return {};
}

int main()
{
    const auto res = findGapSieve(4, 130, 200);
    if (!res.empty())
    {
        std::cout << "res is [" << res[0] << ", " << res[1] << "]" << std::endl;
    } else
    {
        std::cout << "No solution found" << std::endl;
    }
    return 0;
}