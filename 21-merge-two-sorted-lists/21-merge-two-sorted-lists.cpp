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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* ans_tmp = ans;

        while (list1 && list2) {
            int val1 = list1->val;
            int val2 = list2->val;
            if (val1 <= val2) {
                ans_tmp->next = list1;
                ans_tmp = ans_tmp->next;
                list1 = list1->next;
            }
            else {
                ans_tmp->next = list2;
                ans_tmp = ans_tmp->next;
                list2 = list2->next;
            }
        }
        while (list1) {
            ans_tmp->next = list1;
            ans_tmp = ans_tmp->next;
            list1 = list1->next;
        }
        while (list2) {
            ans_tmp->next = list2;
            ans_tmp = ans_tmp->next;
            list2 = list2->next;
        }


        return ans->next;
    }
};