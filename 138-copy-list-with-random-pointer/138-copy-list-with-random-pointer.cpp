/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       // 1->2->3->4
       // 1->1->2->2->3->3->4->4
            //1. tmp->next->random=tmp->random->next
            Node* tmp=head;
            // duplicate nodes;
            while(tmp){
                    Node* front=tmp->next;
                    // if(front==NULL){
                    //         tmp->next=NULL;
                    //         break;
                    // }
                    Node* new_node=new Node(tmp->val);
                    tmp->next=new_node;
                    new_node->next=front;
                    tmp=front;
            }
            // assign the random pointers
            
            tmp=head;
            while(tmp){
                    Node* front=tmp->next;
                    if(tmp->random==NULL){
                            front->random=NULL;
                    }
                    else
                    front->random=tmp->random->next;
                    tmp=front->next;
            }
            
            // extract the copy linked list
            const int inf=1e9;
            Node* copy=new Node(inf);
            Node *ans=copy;
            tmp=head;
            while(tmp){
                    Node* front= tmp->next;
                    Node* front_nxt=front->next;
                    tmp->next=front_nxt;
                    copy->next=front;
                    copy=copy->next;
                    tmp=front_nxt;
            }
            
            return ans->next;
 
    }
};