/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         ListNode *temp = head;

//         while(fast!=nullptr and fast->next!=nullptr) {
//             fast = fast->next->next;
//             slow = slow->next;
//             if(fast == slow) {
//                 fast = temp;
//                 while(fast != slow) {
//                     fast = fast->next;
//                     slow = slow->next;
//                 }
//                 return slow;
//             }
//         } 
        
//         return nullptr;
                ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    
    }
};