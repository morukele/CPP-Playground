//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> nums, int target)
{
    // to store <number, index>
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (hashMap.find(complement) != hashMap.end() && hashMap[complement] != i)
        {
            return {i, hashMap[complement]};
        }
        hashMap[nums[i]] = i;
    }

    return {};
}

int main()
{
    const std::vector<int> nums = {3, 3};
    const int target = 6;

    auto res = twoSum(nums, target);

    if (!res.empty())
    {
        std::cout << "Results: [" << res[0] << ", " << res[1] << "]" << std::endl;
    }

    return 0;
}
