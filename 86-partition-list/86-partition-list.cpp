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
    ListNode* partition(ListNode* head, int x) {
        vector<int> pre, post;
        ListNode* node = head;
        while (node) {
            int y = node->val;
            if (y >= x) {
                post.push_back(y);
            }
            else pre.push_back(y);
            node = node->next;
        }
        node = head;
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        for (int v : pre) {
            node->val = v;
            node = node->next;
        }
        for (int v : post) {
            node->val = v;
            //ans->next=new ListNode(v);
            node = node->next;
        }

        return head;
    }
};