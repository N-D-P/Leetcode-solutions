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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ogHead = new ListNode();
        ogHead->next = head;
        ListNode* last = head;
        ListNode* curr = head;
        int cnt = 1;
        if(head == nullptr or head->next == nullptr)
            return head;
        while(last->next!=nullptr) {
            cnt++;
            last=last->next;
        }
        cnt = cnt/2;
        cout<<"Cnt : "<<cnt/2<<endl;
        // while(curr) {
        //     cout<<curr->val;
        //     curr = curr->next;
        // }
        while(cnt--) {
            last->next = new ListNode(curr->next->val);
            curr->next = curr->next->next;
            curr = curr->next;
            last = last->next;
        }
        
        return ogHead->next;
        
        
        
        
        
        
        
    }
};