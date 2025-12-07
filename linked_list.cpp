//
// Created by Oghenemarho Orukele on 07/12/2025.
//
/*
 * Linked lists are data structure that contains a value, and a pointer to the next value.
 * It is usually represented as a node structure.
 * It is useful because we don't have to assign contiguous memory on the stack.
 */

#include <iostream>
#include <ostream>

class ListNode
{
public:
    ListNode() : value{0}, next{nullptr} {}; // default constructor
    ListNode(const ListNode&); // copy constructor
    // constructor that uses data
    explicit ListNode(const int data)  :  value{data}, next{nullptr} {}

    int value;
    ListNode* next;
};

class LinkedList
{
public:
    explicit LinkedList() : head{nullptr}
    {

    }

    ListNode* head;

    void insertAtEnd(const int value)
    {
        // create new list node for the value
        auto* newNode = new ListNode(value);

        // if there are no nodes in the linked list, set the new node as the head
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // A temp variable for the current
        ListNode* current = head;

        // iterate to the end
        while (current->next != nullptr)
        {
            current = current->next; // move the current pointer forward
        }

        // append the new value at the end of the list
        current->next = newNode;
    }
};

/*
 * A function to print a linked list.
 * Take in a linked list and displays the value to std::out.
 */
void printLinkedList(const LinkedList* list)
{
    auto* current = list->head;

    while (current != nullptr)
    {
        std::cout << "[" << current->value << "] -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
};

/*
 * A function to merge two sorted linked list.
 */
LinkedList mergeTwoSortedLinkedList(LinkedList l1, LinkedList l2)
{
    const auto temp = new ListNode();
    // we us current to track position
    // return the dummy as opposed to current.
    auto current = temp;

    while (l1.head && l2.head)
    {
        if (l1.head->value > l2.head->value)
        {
            // set current next to head
            current->next =  l2.head;
            // move l2 forward
            l2.head = l2.head->next;
        } else
        {
            current->next = l1.head;
            l1.head = l1.head->next;
        }
        // move current regardless
        current = current->next;
    }

    // if there is residue in l1 and l2, add them to the list
    if (l1.head) {current->next = l1.head;}
    if (l2.head) {current->next = l2.head;}


    // create new linked list
    // set the head to the temp and then return it
    auto mergedList = LinkedList();
    mergedList.head = temp->next;
    delete temp; // to avoid memory leak
    return mergedList;
}


int main()
{
    // create linked list
    auto l1 = LinkedList();
    l1.insertAtEnd(5);
    l1.insertAtEnd(10);
    l1.insertAtEnd(15);
    l1.insertAtEnd(20);

    // print out linkedlist
    printLinkedList(&l1);

    // create second list
    auto l2 = LinkedList();
    l2.insertAtEnd(1);
    l2.insertAtEnd(2);
    l2.insertAtEnd(3);
    l2.insertAtEnd(4);
    l2.insertAtEnd(5);

    printLinkedList(&l2);

    // merge list
    const auto mergedList = mergeTwoSortedLinkedList(l1, l2);
    printLinkedList(&mergedList);

    // return 0
    return 0;
}