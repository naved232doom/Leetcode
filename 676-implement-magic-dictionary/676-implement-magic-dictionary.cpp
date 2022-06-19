class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode() {
        memset(next, NULL, sizeof next);
        is_word = 0;
    }
};

class MagicDictionary {
public:
  TrieNode *root;
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void insert(string &s) {
        TrieNode *here = root;
        for (int i = 0; i < s.length(); ++i) {
            if (!here->next[s[i] - 'a']) {
                here->next[s[i] - 'a'] = new TrieNode();
            }
            here = here->next[s[i] - 'a'];
        }
        here->is_word = 1;
    }
    bool search2(string &s) {
        auto here=root;
        
        for(int i=0;i<s.length();++i){
            int c_here=s[i]-'a';
            if(!here->next[c_here]) return false;    
            here= here->next[c_here];
        }
        return here&& here->is_word;
    }
    bool find(string &s) {
           
        for(int i=0;i<s.length();++i){
            for(int j=0;j<26;++j){
                int c_here= j +'a';
                if(c_here==s[i]) continue;
                char prev= s[i];
                s[i]=c_here;
                if(search2(s)) return true;
                s[i]=prev;
            }
        }
        return false;
       
    }
    void buildDict(vector<string> dic) {
        for (string w : dic) {
            insert(w);
        }
    }

    bool search(string searchWord) {
        return find(searchWord);
    }

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */