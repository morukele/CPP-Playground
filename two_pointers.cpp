//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <iostream>
#include <string>

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool isPalindrome(const std::string& s)
{
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
    {
        while (l < r && !isalnum(s[l])) l += 1;
        while (l < r && !isalnum(s[r])) r -= 1;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++;
        r--;
    }
    return true;
}

int main()
{
    const auto s = std::string("A man, a plan, a canal: Panama");
    const bool res = isPalindrome(s);
    if (res)
    {
        std::cout << s << "is a palindrome" << std::endl;
    } else
    {
        std::cout << s << "is not a palindrome" << std::endl;
    }
    return 0;
}