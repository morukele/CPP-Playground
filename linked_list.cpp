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

    ~LinkedList()
    {
        ListNode* current = head;
        while (current)
        {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
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
void displayLinkedList(const ListNode* head)
{
    auto* current = head;

    while (current != nullptr)
    {
        std::cout << "[" << current->value << "] -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
};

/**
 * A function to display the linked node to std::out
 * @param node The node of the linked list to display
 */
void displayListNode(const ListNode* node)
{
    if (node != nullptr)
    {
        std::cout << "[" << node->value << "]" << std::endl;
    } else
    {
        std::cout << "input node is null" << std::endl;
    }
}

/*
 * A function to merge two sorted linked list.
 */
ListNode* mergeTwoSortedLinkedList(ListNode* head1, ListNode* head2)
{
    ListNode temp;
    // we us current to track position
    // return the dummy as opposed to current.
    auto current = &temp;

    while (head1 && head2)
    {
        if (head1->value > head2->value)
        {
            // set current next to head
            current->next =  head2;
            // move l2 forward
            head2 = head2->next;
        } else
        {
            current->next = head1;
            head1 = head1->next;
        }
        // move current regardless
        current = current->next;
    }

    // if there is residue in l1 and l2, add them to the list
    if (head1) {current->next = head1;}
    if (head2) {current->next = head2;}

    return temp.next;
}

/**
 * A function to return the middle element of a linked list using fast and slow pointer.
 * @param head The head of the linked list to return the middle node
 * @return ListNode of the middle element
 */
ListNode* findMiddleOfLinkedList(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev; // Node before the middle
}

/**
 * A function to merge sort a linked list
 * @param head - the head of the linked list to sort
 * @return - the head of the sorted linked list
 */
ListNode* sortLinkedList(ListNode* head)
{
    // handle base case: if the list is null or the next element is null
    // return the list as is.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // split linked list into two halves
    ListNode* midPrev = findMiddleOfLinkedList(head);
    ListNode* right = midPrev->next;
    midPrev->next = nullptr; // effectively splitting the list, to create the self.
    ListNode* left = head;

    left = sortLinkedList(left);
    right = sortLinkedList(right);

    return mergeTwoSortedLinkedList(left, right);
}


int main()
{
    // create linked list
    auto l1 = new LinkedList();
    l1->insertAtEnd(10);
    l1->insertAtEnd(5);
    l1->insertAtEnd(3);
    l1->insertAtEnd(20);

    // print out linkedlist
    std::cout << "unsorted L1: " << std::endl;
    displayLinkedList(l1->head);

    // sort L1
    ListNode* s1 = sortLinkedList(l1->head);
    l1->head = s1;
    std::cout << "sorted L1: " << std::endl;
    displayLinkedList(l1->head);

    // create second list
    auto l2 = new LinkedList();
    l2->insertAtEnd(1);
    l2->insertAtEnd(25);
    l2->insertAtEnd(3);
    l2->insertAtEnd(50);
    l2->insertAtEnd(5);

    // print out L2
    std::cout << "unsorted L2: " << std::endl;
    displayLinkedList(l2->head);

    // sort L2
    ListNode* s2 = sortLinkedList(l2->head);
    l2->head = s2;
    std::cout << "sorted L2: " << std::endl;
    displayLinkedList(l2->head);

    // merge list
    const auto mergedList = mergeTwoSortedLinkedList(l1->head, l2->head);
    std::cout << "merged list: " << std::endl;
    displayLinkedList(mergedList);

    // get middle element
    const auto middle = findMiddleOfLinkedList(mergedList);
    std::cout << "middle element in merged linked list: " << std::endl;
    displayListNode(middle);

    // handle memory leaks
    delete l1;
    delete l2;

    // return 0
    return 0;
}