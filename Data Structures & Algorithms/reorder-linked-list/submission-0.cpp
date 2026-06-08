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
        int l = 0;
        ListNode* temp = head;
        while(temp) {
            l++;
            temp = temp->next;
        }
        int idx = (l%2)?l/2:l/2-1;
        ListNode *n2 = head, *p = nullptr;
        for(int i = 0; i <= idx; i++) {
            p = n2;
            n2 = n2->next;
        }
        p->next = nullptr;
        ListNode *curr = n2, *prev = nullptr;
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
