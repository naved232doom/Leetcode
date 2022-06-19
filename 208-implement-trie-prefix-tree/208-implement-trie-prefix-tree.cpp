class TrieNode{
    public:
    TrieNode *next[26];
    int is_word;
    TrieNode(){
        memset(next,NULL,sizeof next);
        is_word=0;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *here=root;
        for(int i=0;i<word.length();++i){
            if(!here->next[word[i]-'a']){
                here->next[word[i]-'a']= new TrieNode();
            }
            here=here->next[word[i]-'a'];
        }
        here->is_word=1;
    }
    
    bool search(string word) {
        TrieNode *here=root;
        for(int i=0;i<word.length();++i){
            if(!here) return false;
            here=here->next[word[i]-'a'];
        }
        return here&&here->is_word;
    }
    
    bool startsWith(string word) {
        TrieNode *here=root;
        for(int i=0;i<word.length();++i){
            if(!here) return false;
            here=here->next[word[i]-'a'];
        }
        return (here ? true:false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */