/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    ListNode* rev(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

public:
    // Time Complexity: O(n), Space Complexity: O(1)
    void reorderList(ListNode* head) 
    {
        ListNode* s = head, *f = head;

        while(true)
        {
            if(!f || !f->next) break;

            f = f->next->next;
            s = s->next;
        }

        ListNode* second = s->next;
        s->next = nullptr;
        second = rev(second);

        while(head && second)
        {
            ListNode* nextS = second->next;
            ListNode* nextF = head->next;
            head->next = second;
            second->next = nextF;
            head = nextF;
            second = nextS;
        }
    }
};