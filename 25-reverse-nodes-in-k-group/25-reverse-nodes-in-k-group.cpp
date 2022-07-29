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
    ListNode* rev(ListNode* beg,ListNode* end){
        ListNode* prev=beg;
        ListNode* cur=beg->next;
        ListNode* first=beg->next;
        while(cur!=end){
            ListNode* nxt= cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        beg->next=prev;
        first->next=cur;
        return first;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* ans=dummy;
        int it=0;
        // -1 <- 1<- 2 3 ->4 ->5
        // dummy   prev cur  
        while(head!=NULL){
            it++;
            if(it%k==0){
              dummy=rev(dummy,head->next);
                head=dummy->next;
            }
            else{
                head=head->next;
            }
        }
        return ans->next;
    }
};