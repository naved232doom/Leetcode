class StreamChecker {
public:
        // we want to check if a suffix matches a given word
        
    StreamChecker(vector<string>& words) {
                
        for(auto s:words) {
               trie.insert(s);
                longestWord=max(longestWord,(int)s.length());
        }
           
    }
    
    bool query(char letter) {
        queries=letter+queries;
            if(queries.length()>longestWord) queries.pop_back();
                Trie* cur=&trie;
            for(int i=0;i<queries.length();++i){
                    if(cur->isWord) return 1;
                    if(cur->children[queries[i]-'a']==NULL) return false;
                    cur=cur->children[queries[i]-'a'];
            }
            return cur->isWord;
    }
private:

class Trie{
  public:
        Trie *children[26];
        bool isWord=0;
        Trie(){
                this->isWord=0;
                for(int i=0;i<26;++i) this->children[i]=NULL;
        }
        void insert(string w){
                reverse(w.begin(),w.end());
                Trie *cur=this;
                int n=w.length();
                for(char c:w){
                        if(cur->children[c-'a']==NULL)
                                cur->children[c-'a']=new Trie();
                        cur=cur->children[c-'a'];
                }
                cur->isWord=1;
        }
};
         Trie trie;
         string queries="";
        int longestWord=0;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */