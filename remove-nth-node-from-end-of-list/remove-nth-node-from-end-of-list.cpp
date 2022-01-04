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
        int len = 0;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* tmp_ans = ans;
        ListNode* tmp_head = head;
        
        for (int i = 0; i < n ; i++) {
            tmp_head = tmp_head->next;
        }
        //cout<<tmp_head->val<<endl;
        while(tmp_head!=NULL) {
                tmp_head=tmp_head->next;
                tmp_ans=tmp_ans->next;
        }
         tmp_ans->next=tmp_ans->next->next;   
        ans = ans->next;
        return ans;

    }
};