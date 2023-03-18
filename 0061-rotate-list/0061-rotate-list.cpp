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
        if(head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode *p = head;
        ListNode *q = head;
        while(q->next){
            q = q->next;
            len++;
        }
         q->next = head;
         k = k % len;
         k = len - k;
         int j = 1;
         while(k!=1){
             p = p->next;
             k--;
         }

         head = p->next;
         p->next = NULL;

         return head;
    }
};