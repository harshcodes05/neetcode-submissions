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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        int carry = 0;
        while(l1 && l2) {
            int sum = (carry)?l1->val + l2->val + 1: l1->val + l2->val;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = (carry)?l1->val + 1: l1->val;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2) {
            int sum = (carry)?l2->val + 1: l2->val;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
            l2 = l2->next;
        }
        if(carry == 1) {
            ListNode* node = new ListNode(1);
            temp->next = node;
        }
        return dummy.next;
        
    }
};
