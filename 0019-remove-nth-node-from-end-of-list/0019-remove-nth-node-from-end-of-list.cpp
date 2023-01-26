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
        ListNode *curr = head;
        ListNode *prev = head;
        ListNode *pprev = head;
        
        while(n--) {
            curr = curr->next;
        }
        
        if(curr == nullptr)
            return head->next;
        
        while(curr) {
            pprev = prev;
            prev = prev->next;
            curr = curr->next;
        }
        
        pprev->next = prev->next;
        return head;
    }
};