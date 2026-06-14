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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        ListNode* temp = head;
        ListNode* l_pos = head;
        ListNode* curr = temp;
        bool headNotFound = true;
        while(true) {
            int i = 0;
            while(temp && i<k) {
                temp = temp->next;
                i++;
            }
            if(i==k) {
                ListNode* prev = nullptr;
                ListNode* last = curr;
                while(curr && curr != temp) {
                    ListNode* tp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = tp;
                }
                if(headNotFound) {
                    head = prev;
                    headNotFound = false;
                }
                l_pos->next = prev;
                l_pos = last;
            }
            else break;
        }
        if(l_pos != head) l_pos->next = curr;
        return head;
    }
};
