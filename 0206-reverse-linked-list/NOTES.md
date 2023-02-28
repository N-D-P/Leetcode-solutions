```
ListNode* reverseList(ListNode* head) {
ListNode *curr=head,*prev = NULL,*next;
while(curr!=NULL)
{
next = curr->next; //save next
curr->next = prev; //reverse
prev = curr; //advance prev
curr = next; //advance curr
}
return prev;   //new head at the end
}
//recursive
ListNode* reverseList(ListNode* head) {
if(head == NULL or head->next == NULL) return head;
ListNode *newhead = reverseList(head->next); //down down down
head->next->next = head; // reverse
head->next = NULL; //reverse
return newhead; //up
}
```
​