//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <iostream>
#include <vector>

int subArraySumFixed(const std::vector<int>& nums, const int k)
{
    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += nums[i];
    }
    int largest = window_sum;
    for (int r = k; r < nums.size(); r++)
    {
        const int l = r - k;
        window_sum -= nums[l]; // remove the left element
        window_sum += nums[r]; // add the right element
        largest = std::max(largest, window_sum); // compare to get the largest
    }
    return largest;
}

int lenghtOfLongestSubstringWithoutRepeatingCharacters(std::string& s)
{
    int l = 0;
    int r = 0;
    int longest = 0;
    auto counter = std::unordered_map<char, int>(); // track occurrence

    // Iterate through all numbers in the string using the right pointer
    for (int r = 0; r < s.length(); r++)
    {
        counter[s[r]] += 1; // add character to the hashmap, and increase count
        while (counter[s[r]] > 1) // if any character has count higher than 1
        {
            counter[s[l]] -= 1; // drop left most element from the window
            l++; // move the left bound of the window.
        }
        longest = std::max(longest, r - l + 1); // plus 1 to account for 0 based index
    }
    return longest;
}

int main()
{
    std::string string = std::string("abccabcabcc");
    const auto res = lenghtOfLongestSubstringWithoutRepeatingCharacters(string);
    std::cout << res << std::endl;
    return 0;
}