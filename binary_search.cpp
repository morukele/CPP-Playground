//
// Created by Oghenemarho Orukele on 04/12/2025.
//

#include <iostream>
/*
 * Binary search is also useful for finding the boundary of a Monotonic problem.
 */
/*
 * To quickly find a target value in a sorted array of numbers
 */
int binarySearch(std::vector<int> array, int target)
{
    int L = 0;
    int R = array.size() - 1;
    while (L <= R)
    {
        // compute the mid for each step of the iteration.
        int mid = L + (R - L) / 2; // left plus the gap
        if (array[mid] == target)
        {
            return mid;
        }
        if (array[mid] < target)
        {
            L = mid + 1;
        } else
        {
            R = mid - 1;
        }
    }

    return -1;
}

bool binarySearchIsSquare(int x)
{
    // make an array
    std::vector<int> array(x + 1);
    for (int i = 0; i <= x; i++)
    {
        array.push_back(i);
    }

    int L = 0, R = array.size() - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        int square = array[mid] * array[mid];
        if ( square == x)
        {
            return true;
        }
        if (square < x)
        {
            L = mid + 1;
        } else
        {
            R = mid - 1;
        }
    }

    return false;
}

float binarySearchSquareRoot(int x)
{
    float L = 0.0, R = static_cast<float>(x);
    while (R - L > 0.0001)
    {
        float mid = L + ( R - L) / 2;
        if (mid * mid < x)
        {
            L = mid;
        }
        else
        {
            R = mid;
        }
    }
    return L + (R - L) / 2;
}

int main()
{
    const std::vector<int> array = {-1};
    const int target = 2;
    const auto b = binarySearch(array, target);

    std::cout << "Index of target (" << target << ") is: " << b << std::endl;

    int num1 = 16;
    int num2 = 20;

    std::cout << "is " << num1 << " a square?: " << binarySearchIsSquare(num1) << std::endl;
    std::cout << "is " << num2 << " a square?: " << binarySearchIsSquare(num2) << std::endl;

    int num3 = 4;
    float res = binarySearchSquareRoot(num3);
    std::cout << "square root of " << num3 << " is: " << res << std::endl;

}