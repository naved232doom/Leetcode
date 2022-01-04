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
        int len=0;
            ListNode* tmp=head;
            while(tmp){
                    len++;
                    tmp=tmp->next;
            }
            int n_left=len-n+1;
            int cur_pos=0;
            tmp=head;
            ListNode* prev=new ListNode(0);
            prev->next=head;
            ListNode* ans=prev;
            // prev=prev->next;
            for(int i=0;i<n_left-1;++i){
                    prev=prev->next;
            }
            prev->next=prev->next->next;
            return ans->next;
            
    }
};