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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return head->next; 
        int l = 0;
        ListNode *temp = head, *prev = nullptr;
        while(temp) {
            l++;
            temp = temp->next;
        }
        int idx = l-n;
        int i = 0;
        temp = head;
        while(temp && i<idx) {
            i++;
            prev = temp;
            temp = temp->next;
        }
        if(temp == head) return head->next;
        prev->next = temp->next;
        return head;
    }
};
