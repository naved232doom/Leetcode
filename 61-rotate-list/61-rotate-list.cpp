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
        vector<int> tmp;
            ListNode* ans=head;
            while(head){
                    tmp.push_back(head->val);
                    head=head->next;
            }
            
            head=ans;
            int it=0;
            auto arr=tmp;
            int n=(tmp.size());
                for(int i=0;i<(int)(tmp.size());++i){
                        arr[i]=tmp[((i-k)%n+n)%n];
                }
            while(head){
                    head->val=arr[it++];
                    head=head->next;
            }
            return ans;
    }
};