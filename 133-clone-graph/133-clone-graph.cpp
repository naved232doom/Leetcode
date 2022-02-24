/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
        private:
        map<int,Node*> visited;
        Node* dfs(Node* node){
              if(node==NULL) return NULL;
                Node* cur=new Node(node->val);
                visited[node->val]=cur;
                vector<Node*> N;
                for(auto v:node->neighbors){
                        if(visited.find(v->val)!=visited.end()) {                                                       N.push_back(visited[v->val]);
                        }
                        else
                        N.push_back(dfs(v));
                }
                cur->neighbors=N;
                return cur;
        }
public:
        
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};