class WordDictionary
{
private:
    struct TrieNode
    {
        TrieNode *children[26];
        bool isEndOfWord;
    };
    TrieNode *root;
    bool dfs(string word, int idx, TrieNode *curr)
    {
        if (!curr)
            return false;
        if (idx == word.size())
            return curr->isEndOfWord;
        if (word[idx] != '.')
            return dfs(word, idx + 1, curr->children[word[idx] - 'a']);
        else
        {
            for (int i = 0; i < 26; i++)
                if (dfs(word, idx + 1, curr->children[i]))
                    return true;
        }
        return false;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
        for (int i = 0; i < 26; i++)
            root->children[i] = nullptr;
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *curr = root;
        for (auto &c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return dfs(word, 0, root);
    }
};
