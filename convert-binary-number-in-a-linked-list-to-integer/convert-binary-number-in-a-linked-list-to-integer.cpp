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
    int getDecimalValue(ListNode* head) {
        vector<int> values;
            while(head!=NULL){
                    values.push_back(head->val);
                    head=head->next;
            }
            int ans=0;
            int n=(int)(values.size());
            for(int i=0;i<n;++i){
                 int k=n-i-1;
                    ans+=(values[i]==1 ? (1<<k):0);
            }
            return ans;
    }
};