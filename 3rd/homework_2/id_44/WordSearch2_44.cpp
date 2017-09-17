class Trie {
    struct TrieNode{
        bool is_end_;
        vector<TrieNode*> children_;
        TrieNode() : is_end_(false), children_(26, nullptr) {}
    };
    TrieNode* root {nullptr};
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
            return;
        auto p_node = root;
        for(auto ch: word) {
            auto idx = ch - 'a';
            auto& p_child = p_node->children_[idx];
            if (!p_child) {
                p_child = new TrieNode();
            }
            p_node = p_child;
        }
        p_node->is_end_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty())
            return true;
        auto p_node = root;
        for (auto ch: word) {
            auto idx = ch - 'a';
            auto p_child = p_node->children_[idx];
            if (!p_child)
                return false;
            p_node = p_child;
        }
        return p_node->is_end_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty())
            return true;
        auto p_node = root;
        for (auto ch: prefix) {
            auto idx = ch - 'a';
            auto p_child = p_node->children_[idx];
            if (!p_child)
                return false;
            p_node = p_child;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
