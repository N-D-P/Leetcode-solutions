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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        int size = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            curr=curr->next;
            size++;
        }
        k = k%size;
        
        if(k == 0)
            return head;
        
        int k_ = size-k;
        curr = head;
        while(k_!=1) {
            curr=curr->next;
            k_--;
        }
        ListNode *newHead = curr->next;
        ListNode *curr1 = curr->next;
        curr->next = nullptr;
        while(k!=1) {
            cout<<curr1->val;
            curr1=curr1->next;
            k--;
        }
        curr1->next = head;
        return newHead;
    }
};