class TrieNode {
public:
    const int MX = 27;
    TrieNode* next[27];
    int word_end = 0;
    int idx = -1;
    TrieNode() {
        for (int i = 0; i < 27; ++i) {
            next[i] = NULL;
        }
        word_end = 0;
    }

};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    // insert
    void insert(string s, int index) {
        //cout<<s<<endl;
        TrieNode *p = root;
        int n = (int)(s.length());
        // cba
        for (int i = 0; i < n; ++i) {
            p->idx = index;
            if (s[i] == '$') {
                int here = 26;
                if (p->next[26] == NULL) {
                    p->next[26] = new TrieNode();
                }
                p = p->next[26];
            }
            else {
                if (p->next[s[i] - 'a'] == NULL) {
                    p->next[s[i] - 'a'] = new TrieNode();
                }
                p = p->next[s[i] - 'a'];
            }
        }
        p->word_end = 1;
        p->idx=index;
    }
    // search
    int find(string s) {
        TrieNode* p = root;
        for (int i = 0; i < s.length(); ++i) {
            if (p==NULL) return -1;
            if (s[i] == '$') {
                p = p->next[26];
            }
            else
                p = p->next[s[i] - 'a'];
        }
        if (p) return p->idx;
        return -1;
    }


};
class WordFilter {
public:
    Trie root;
    WordFilter(vector<string>& words) {
        for (int i = 0; i < (int)(words.size()); ++i) {
            int len = words[i].length();
            string here = '$' + words[i];
            root.insert(here, i);
            for (int j = len - 1; j >= 0; --j) {
                here = words[i][j] + here;
                root.insert(here, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        string to_find = suffix + '$' + prefix;
        //cout<<"to_find: "<<to_find<<endl;
        return root.find(to_find);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */