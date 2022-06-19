class TrieNode {
public:
    TrieNode *next[26];
    int is_word;
    TrieNode() {
        memset(next, NULL, sizeof next);
        is_word = 0;
    }
};
class Solution {
public:
    TrieNode *root;
    void insert(string &s) {
        auto here = root;
        for (int i = 0; i < s.length(); ++i) {
            int c_here = s[i] - 'a';
            if (!here->next[c_here]) {
                here->next[c_here] = new TrieNode();
            }
            here = here->next[c_here];
        }
        here->is_word = 1;
    }
    // searh
    bool search(string &s) {
        auto here = root;
        for (int i = 0; i < s.length(); ++i) {
            int c_here = s[i] - 'a';
            if (!here->next[c_here] || !here->next[c_here]->is_word) {
                // cout<<here->next[c_here]<<endl;
                // cout<<c_here<<endl;
                // cout<<s<<endl;
                // cout<<i<<endl;
                return false;
            }
            // if(!here->is_word){
            //     cout<<"here->is_word "<<here->is_word<<endl;
            //     cout<<c_here<<endl;
            //     cout<<s<<endl;
            //     cout<<i<<endl;
            //     return false;
            // }
            //cout<<here->is_word<<endl;
            here = here->next[c_here];
        }
        return here && here->is_word;
    }
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (auto w : words) {
            insert(w);
        }
        string ans = "";
        for (auto w : words) {
            if (search(w)) {
                //cout<<w<<endl;
                if (ans.empty()) {
                    ans = w;
                }
                else {
                    if ((w.length() > ans.length()) || (w.length() == ans.length() && w < ans)) ans = w;
                }
            }
        }
        return ans;
    }
};