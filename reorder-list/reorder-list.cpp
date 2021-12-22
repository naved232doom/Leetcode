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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
            ListNode* slow=head;
            while(fast&&fast->next&&slow){
                    fast=fast->next->next;
                    slow=slow->next;
            }
            // we have the middle of the linked list
            // we want to reverse everything ahead of middle
            //cout<<slow->val<<endl;
        ListNode* cur=slow;
            ListNode* prev=NULL;
            //tmp=slow;
            while(cur!=NULL){
                    ListNode* nxt=cur->next;
                    cur->next=prev;
                        prev=cur;
                    cur=nxt;
                 }
            //assert(slow==NULL);
            slow->next=NULL;
           
            
            //cout<<slow->val<<endl;
            while(head!=NULL&&prev!=NULL){
                   //cout<<head->val<<" "<<prev->val<<endl;
                    ListNode* nextLeft=head->next;
                    ListNode* nextRight=prev->next;
                    if(nextLeft==NULL) break;
                    head->next=prev;
                    if(nextRight==NULL) break;
                    prev->next=nextLeft;
                    head=nextLeft;
                    prev=nextRight;
            }
    }
};