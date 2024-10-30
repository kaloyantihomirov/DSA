#include <iostream>

using namespace std;

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
    ListNode* removeElementsNaive(ListNode* head, int val) 
    {
        ListNode* current = head;
        ListNode* previous = nullptr;

        while (current)
        {
            if (current->val == val)
            {
                if (previous)
                {
                    previous->next = current->next;
                    current = current->next;
                }
                else
                {
                    ListNode* temp = head;
                    head = current->next;
                    delete temp;
                    current = head;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        return head;
    }

    ListNode* removeElementsWithDummyHeadApproach(ListNode* head, int val)
    {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* current = head;
        ListNode* previous = dummyHead;

        while (current)
        {
            if (current->val == val)
            {
                ListNode* temp = current;
                previous->next = current->next;
                current = current->next;
                delete temp;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        ListNode* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}