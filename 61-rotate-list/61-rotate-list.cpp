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
            if(head==NULL) return head;
        ListNode* tail=head;
            int len=0;
            while(tail->next){
                    tail=tail->next;
                    len++;
            }
            tail->next=head;
            tail=head;
            for(int i=0;i<len-(k%(len+1));++i){
                    tail=tail->next;
            }
            head=tail->next;
            tail->next=NULL;
            return head;
    }
};