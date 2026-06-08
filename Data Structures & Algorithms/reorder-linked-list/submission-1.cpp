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

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *prev = nullptr;
        slow->next = nullptr;
        while(curr) {
            ListNode * tp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tp;
        }
        
        ListNode *a = head, *b = head, *c = prev;
        while(b && c) {
            b = b->next;
            a->next = c;
            a = a->next;
            c = c->next;
            a->next = b;
            a = a->next;
        }
    }
};
