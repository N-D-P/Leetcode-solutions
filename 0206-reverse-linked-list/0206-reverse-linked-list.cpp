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
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, nullptr);
    }
    
    ListNode* reverseList(ListNode *head, ListNode *newHead) {
        if(head == nullptr)
            return newHead;
        ListNode *next = head->next;
        head->next = newHead;
        return reverseList(next,head);
    }
};