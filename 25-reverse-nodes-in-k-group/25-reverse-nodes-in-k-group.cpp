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
    ListNode* reverse(ListNode* begin,ListNode* end){
        ListNode* cur=begin->next;
        ListNode* prev=begin;
        ListNode* first= begin->next;
        while(cur!=end){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        begin->next=prev;
        first->next=cur;
        return first;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // -1->1->2->3->4->5
        // -1->2 <-1<-2    3->4->5
                   // prev  cur     
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* ans=dummy;
        ListNode* begin=dummy;
        int it=0;
        while(head!=nullptr){
            it++;
            if(it%k==0){
                begin=reverse(begin,head->next);
                head=begin->next;
            }
            else head=head->next;
        }
        return ans->next;
    }
};