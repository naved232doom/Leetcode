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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp=head;
        ListNode* prev1=new ListNode(-1);
        auto dummy=prev1;
        auto prev=prev1;
        prev1->next=tmp;
        for(int i=0;i<left-1;++i){
            tmp=tmp->next;
            prev1=prev1->next;
        }
        // 1-> NULL<-2 <- 3 <- 4 5
         ListNode* p= NULL;
        int cnt=left;
        while(cnt<=right){
            ListNode* nxt= tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=nxt;
            cnt++;
        }
        // 1->2 , 
        prev1->next->next=tmp;
        prev1->next=prev;
        return dummy->next;
    }
};