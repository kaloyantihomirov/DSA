// reverseKGroup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* currStart = head;
        ListNode* end = currStart;
        bool preliminary = false;
        ListNode* lastFromPrevIt = nullptr, *firstFromLastIter = nullptr;

        while (true)
        {
            for (int i = 0; i < k; i++)
            {
                if (!end)
                {
                    preliminary = true;
                    break;
                }
                end = end->next;
            }

            if (end)
            {
                ListNode* prev = nullptr;
                ListNode* curr = currStart;
                while (curr != end)
                {
                    ListNode* nextNode = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextNode;
                }

                if (lastFromPrevIt)
                {
                    lastFromPrevIt->next = prev;
                }

                lastFromPrevIt = currStart;
                firstFromLastIter = prev;

                currStart = end;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
