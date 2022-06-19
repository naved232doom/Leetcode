class TrieNode {
public:
    int word_end=0;
    TrieNode *next[26];

    TrieNode() {
        memset(next, NULL, sizeof next);
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &s) {
        TrieNode* node_here = root;
        for (int i = 0; i < s.length(); ++i) {
            if (!node_here->next[s[i] - 'a']) {
                node_here->next[s[i] - 'a'] = new TrieNode();
                //node_here->next[s[i] - 'a'] = 1;
            }
            node_here = node_here->next[s[i] - 'a'];
        }
        node_here->word_end = 1;
    }
    // should be recursive
    bool search(string &s) {
        TrieNode *root_here=root;
        return find(s, root_here);
    }
bool find(string &s, TrieNode *root_here, int idx = 0) {
    if(idx==s.length()) return root_here&&root_here->word_end;
    
    for (int i = idx; i < s.length() && root_here; ++i) {
        if (s[i] == '.') {
                TrieNode* here=root_here;
            for (int j = 0; j < 26; ++j) {
                //root_here=here->next[j];
    if (root_here && find(s, root_here->next[j], i + 1) ) return true;
                }
            return false;
            }
            else {
                //if (!root_here->next[s[i] - 'a']) return false;
                root_here = root_here->next[s[i] - 'a'];
            }
        }
        return root_here&&root_here->word_end;
    }

};
class WordDictionary {
public:
    Trie node;
    WordDictionary() {

    }

    void addWord(string word) {
        node.insert(word);
    }

    bool search(string word) {
        return node.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */