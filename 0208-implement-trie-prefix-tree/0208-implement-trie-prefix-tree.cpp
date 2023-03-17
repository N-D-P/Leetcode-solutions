class TrieNode {
    
    public:
    
        TrieNode* child[26];
        bool islastword;
    
        TrieNode() {
            for(int i=0; i<26; i++)
                child[i] = nullptr;
            islastword = false;
        }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*curr = root;
        for(int i=0; i<word.length(); i++) {
            int k = word[i]-'a';
            if(curr->child[k]==nullptr)
                curr->child[k] = new TrieNode();
            curr=curr->child[k];
        }
        curr->islastword = true;
    }
    
    bool search(string word) {
        TrieNode*curr = root;
        for(int i=0; i<word.length(); i++) {
            int k = word[i]-'a';
            if(curr->child[k]==nullptr)
                return false;
            curr=curr->child[k];
        }
        return curr->islastword;
    }
    
    bool startsWith(string word) {
        TrieNode*curr = root;
        for(int i=0; i<word.length(); i++) {
            int k = word[i]-'a';
            if(curr->child[k]==nullptr)
                return false;
            curr=curr->child[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */