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
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* p=prev;
        for(int it=1;it<left;++it){
            p=p->next;
        }
        ListNode* tail=p->next;
        for(int it=0;it<right-left;++it){
            ListNode* temp=p->next;
            p->next= tail->next;
           tail->next=tail->next->next;
            p->next->next=temp;
        }
        return prev->next;
    }
};