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
        ListNode *curr2 = head;
        ListNode *prev = nullptr;
        if(head == nullptr or head->next == nullptr)
            return nullptr;
        while(n) {
            curr = curr->next;
            n--;
        }
        if(!curr)
            return head->next;
        while(curr != nullptr) {
            curr = curr->next;
            prev = curr2;
            curr2 = curr2->next;
        }
        prev->next = curr2->next;
        return head;
    }
};