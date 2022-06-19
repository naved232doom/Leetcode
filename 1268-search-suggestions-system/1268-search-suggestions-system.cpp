class TrieNode {
public:
    TrieNode *next[26];
    vector<int> pos;
    int is_word;
    TrieNode() {
        memset(next, NULL, sizeof next);
        is_word = 0;
        pos.clear();
    }
};
class Solution {
public:
    TrieNode *root;
    void insert(string &s, int idx) {
        int len = s.length();
        auto p = root;
        for (int i = 0; i < len; ++i) {
            int c_here = s[i] - 'a';
            if (!p->next[c_here]) {
                p->next[c_here] = new TrieNode();
            }
            p = p->next[c_here];
            (p->pos).push_back(idx);
        }
        p->is_word = 1;
    }
    void search(vector<vector<string>> &ans,string &s,vector<string> &pr){
        auto p =root;
        for(int i=0;i<s.length()&&p;++i){
            vector<string> ans_here;
            int c_here=s[i]-'a';
            p=p->next[c_here];
            if(!p) break;
            auto cur=p->pos;
            int len =(int)(cur.size());
            for(int j=0;j<min(3,len);++j){
                ans_here.push_back(pr[cur[j]]);
            }
            ans.push_back(ans_here);
        }
        int s_len=s.length();
        int len=(int)ans.size();
        for(int i=0;i<s_len-len;++i) ans.push_back({});
    }
    vector<vector<string>> suggestedProducts(vector<string>& pr, string sw) {
        sort(pr.begin(), pr.end());
        root = new TrieNode();
        int n = (int)(pr.size());
        for (int i = 0; i < n; ++i) {
            auto P = pr[i];
            insert(P, i);
        }
        vector<vector<string>> ans;
        search(ans,sw,pr);
        return ans;
    }
};