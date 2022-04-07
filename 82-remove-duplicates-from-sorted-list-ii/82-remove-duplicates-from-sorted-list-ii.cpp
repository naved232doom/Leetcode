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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* ans=new ListNode(-200);
        ans->next=head;
        ListNode* prev=ans;
        ListNode* now=ans->next;
        ListNode* nxt;
        // -200 1 2     3 3 4 4 5
        // -200 -> 1...
        // -200-> 1->2...
        // -200->1->2->
        // -200     1   1   1
        //  prev    now nxt 
        while(now!=NULL){
            nxt=now->next;
            if(nxt!=NULL&&(now->val==nxt->val)){
                int v=now->val;
                while(now!=NULL&&now->val==v){
                    now=now->next;
                }
                if(now==NULL){
                    prev->next=now;
                    break;
                }
            }
            else{
                prev->next=now;
                prev=prev->next;
                now=now->next;
                
            }
        }
        
        return ans->next;
    }
};