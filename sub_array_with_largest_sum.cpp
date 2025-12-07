//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <algorithm>
#include <iostream>
#include <vector>

int contiguousSubArrayWithLargestSum(const std::vector<int>& arr) {
    int res = arr[0];
    int maxEnding = arr[0];

    // iterate through the array
    // add the current number to the running sum
    // compare the result to the maxEnding - select max
    // compare the new maxEnding to the existing result - select max

    for (int i = 1; i < arr.size(); i++)
    {
        int sum = maxEnding + arr[i];
        maxEnding = std::max(arr[i], sum);

        res = std::max(res, maxEnding);
    }

    return res;
}

int main()
{
    const std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    const int res = contiguousSubArrayWithLargestSum(nums);

    std::cout << "The largest sum of the contiguous sub array is: " << res << std::endl;

    return 0;
}
