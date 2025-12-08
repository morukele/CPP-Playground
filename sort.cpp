//
// Created by Oghenemarho Orukele on 08/12/2025.
//

#include <iostream>
#include <vector>

void mergeTwoArrays(const std::vector<int>& left, const std::vector<int>& right, std::vector<int>& originalArray)
{
    // index for the three arrays
    // i for left, j for right, and k for original array.
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            originalArray[k++] = left[i++]; // post increament is interesting
        } else
        {
            originalArray[k++] = right[j++];
        }
    }

    // check if there are remainders in left or right array
    while (i < left.size())
    {
        originalArray[k++] = left[i++];
    }

    while (j < right.size())
    {
        originalArray[k++] = right[j++];
    }
}

/**
 * A function to sort an array using the merge sort algorithm
 * @param arr array to sort
 */
void mergeSort(std::vector<int>& arr)
{
    // handle base case
    if (arr.empty() || arr.size() == 1)
    {
        return;
    }

    // find middle of array
    const int idxMid = arr.size() / 2;

    // split array in the middle
    std::vector<int> left(arr.begin(), arr.begin() + idxMid);
    std::vector<int> right(arr.begin() + idxMid, arr.end());

    // call recursively until we find base case
    mergeSort(left);
    mergeSort(right);

    // merge split array
    mergeTwoArrays(left, right, arr);
}

/**
 * Sort an array using the bubble sort algorithm, by bubbling the smallest to the top.
 * @param arr array to be sorted.
 */
void bubbleSort(std::vector<int>& arr)
{
    int const n = arr.size();
    if (arr.empty() || n == 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // conduct swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{
    std::vector<int> arr = {20, 10, 4, 5, 7, 0, -1};
    std::cout << "Original array : ";
    for (const auto& a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    mergeSort(arr);
    std::cout << "Sorted array : ";
    for (const auto& a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    // testing with another sort
    arr = {20, 10, 4, 5, 7, 0, -1};
    std::cout << "Original array : ";
    for (const auto& a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);
    std::cout << "Sorted array : ";
    for (const auto& a : arr)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;

}