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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
            while(head){
                    arr.push_back(head->val);
                    head=head->next;
            }
            sort(arr.begin(),arr.end());
            ListNode* ans=new ListNode(1e8);
            ListNode* tmp=ans;
            for(int v:arr){
                    tmp->next=new ListNode(v);
                    tmp=tmp->next;
            }
            
            return ans->next;
    }
};