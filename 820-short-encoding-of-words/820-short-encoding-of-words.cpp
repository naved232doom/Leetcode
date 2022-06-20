class TrieNode{
  public:
    TrieNode *next[26];
    int is_word;
    TrieNode(){
        memset(next,NULL,sizeof next);
        is_word=0;
    }
};
class Solution {
public:
    TrieNode *root;
    void insert(string &s,int index){
        int n=(int)(s.length());
        auto node=root;
        reverse(s.begin(),s.end());
        bool ok=1;
        int ans_here=0;
        for(int i=0;i<n;++i){
            int c_here=s[i]-'a';
            if(!node->next[c_here]){
                ans_here++;
                node->next[c_here]=new TrieNode();
            }
            else{
                if(node->is_word) node->is_word=0;
            }
            node=node->next[c_here];
        }
        node->is_word=1;
        
    }
    int go(){
        int ans=0;
        TrieNode *node=root;
       f(node,ans);
        return ans;
    }
    int f(TrieNode *node,int &ans,int len=0){
        
        int u=1;
        int cnt=0;
        for(int i=0;i<26;++i){
            if(node->next[i]){
                f(node->next[i],ans,len+1);
                cnt++;
            }
        }
        if(!cnt) ans+=(1+len);
        return u;
    }
    int minimumLengthEncoding(vector<string>& w) {
        root=new TrieNode();
        int ans=0;
        int it=0;
        sort(w.begin(),w.end(),[](string a,string b){
            return a.length()<b.length();
        });
        for(auto p:w){
            insert(p,it++);
        }
        return go();
    }
};