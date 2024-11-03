#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (left == right) return head;
        ListNode dummyHead(0, head);
        ListNode *prevLeft = &dummyHead;
        for (int i = 0; i < left - 1; i++) prevLeft = prevLeft->next;
        ListNode *curr = prevLeft->next, *prev = nullptr;
        for (int i = 0; i < right - left + 1; i++) 
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        prevLeft->next->next = curr;
        prevLeft->next = prev;
        return dummyHead.next;
    }
};