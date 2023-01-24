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
        int carry = 0;
        int x,y,z;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while(l1 or l2) {
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            z = x + y+carry;
            carry = z/10;
            z = z%10;
            ans->next = new ListNode(z);
            ans = ans->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if(carry != 0) {
            ans->next = new ListNode(carry);
        }
        return dummy->next;
    }
};