//
// Created by Oghenemarho Orukele on 05/12/2025.
//

#include <iostream>
#include <ostream>

class Node
{
public:
    int data;
    Node *next;
    explicit Node (int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int* linkedListToArray(Node* l1, int n1)
{
    auto arr1 = new int[n1];

    Node* curr1 = l1;
    while (curr1 != nullptr)
    {
        for (int i = 0; i < n1; i++)
        {
            arr1[i] = curr1->data;
            curr1 = curr1->next;
        }
    }

    delete curr1;
    return arr1;
}

int main()
{
    auto n1 = Node(1);
    auto n2 = Node(2);
    n1.next = &n2;

    auto res = linkedListToArray(&n1, 2);

    for (int i = 0; i < 2; i++)
    {
        std::cout << res[i] << std::endl;
    }

    delete res;

    return 0;
}