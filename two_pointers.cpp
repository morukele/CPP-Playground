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

/**
 * A linked list is a cycle if a pointer exists that points to a previous values in the linked list.
 * If it is a cycle, we can use two pointers such that one moves at half the speed of the other,
 * eventually, they will be at the same position.
 * @param head head of linked list
 * @return true if cycle
 */
bool isCycle(ListNode *head)
{
    // base case
    if (head == nullptr || head->next == nullptr) {return false;}

    // use two pointer algorithm
    ListNode *fast = head;
    ListNode * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {return true;}
    }

    return false;
}

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

    if (__cplusplus == 202002L) std::cout << "C++20" << std::endl;
    else if (__cplusplus == 201703L) std::cout << "C++17" << std::endl;
    else if (__cplusplus == 201402L) std::cout << "C++14" << std::endl;
    else if (__cplusplus == 201103L) std::cout << "C++11" << std::endl;
    else if (__cplusplus == 199711L) std::cout << "C++98" << std::endl;

    return 0;
}