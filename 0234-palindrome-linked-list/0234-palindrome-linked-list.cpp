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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *slo = head;
        if(head == nullptr or head->next == nullptr)
            return true;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *curr = reverse(slow);
        slow = head;
        
        while(curr) {
            if(curr->val != slo->val)
                return false;
            curr = curr->next;
            slo = slo->next;
        }
        return true;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next;
        while(curr) {
            cout<<curr->val;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};