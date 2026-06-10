/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* temp = head;
        Node* curr = dummy;
        unordered_map<Node*,Node*> mp;
        while(temp) {
            Node* node = new Node(temp->val);
            curr->next = node;
            curr = curr->next;
            mp[temp] = node;
            temp = temp->next;
        }
        curr->next = nullptr;
        temp = head;
        curr = dummy->next;
        while(temp) {
            if(mp.find(temp->random) == mp.end()) curr->random = nullptr;
            else {
                curr->random = mp[temp->random];
            }
            curr = curr->next;
            temp = temp->next;
        }
        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
