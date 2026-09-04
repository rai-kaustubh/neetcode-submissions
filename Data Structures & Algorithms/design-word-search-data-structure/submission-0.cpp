class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};
class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { this->root = new TrieNode(); }

    void addWord(string word) {
        auto curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }

    bool search(string word) { return dfs(0, root, word); }

    bool dfs(int index, TrieNode* root, string word) {
        TrieNode* curr = root;

        for (int i = index; i < word.size(); i++) {
            if (word[i] == '.') {
                if (word[i] == '.') {
                    for (auto& [c, child] : curr->children) {
                        if (dfs(i + 1, child, word)) {
                            return true;
                        }
                    }
                    return false;
                }
            } else {
                if (!curr->children.count(word[i])) {
                    return false;
                }
                curr = curr->children[word[i]];
            }
        }

        return curr->endOfWord;
    }
};
