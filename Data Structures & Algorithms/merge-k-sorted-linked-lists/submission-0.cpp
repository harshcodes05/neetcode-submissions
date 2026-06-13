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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(l1 && l2) {
            if(l1->val<=l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummy.next;
    }
    ListNode* mergesort(vector<ListNode*>& lists, int low, int high) {
        if(low >= high) return lists[low];
        int mid = low + (high-low)/2;
        ListNode* l1 = mergesort(lists, low, mid);
        ListNode* l2 = mergesort(lists, mid+1, high);
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergesort(lists, 0, lists.size()-1);     
    }
};
