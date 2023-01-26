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
        if(curr->next == nullptr) {
            if(n == 0)
                return curr;
            else if(n == 1)
                return curr->next;
        }
        while(n--) {
            curr = curr->next;
        }
        if(curr == nullptr)
            head = head->next;
        while(curr) {
            pprev = prev;
            prev = prev->next;
            curr = curr->next;
        }
        cout<<pprev->val;
        pprev->next = prev->next;
        return head;
    }
};