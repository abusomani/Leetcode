class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (auto c : word)
        {
            if (temp->Mp.find(c) == temp->Mp.end())
                temp->Mp[c] = new TrieNode();
            temp = temp->Mp[c];
        }
        temp->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (auto c : word)
        {
            if (temp->Mp.find(c) == temp->Mp.end())
                return false;
            temp = temp->Mp[c];
        }
        return temp->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (auto c : prefix)
        {
            if (temp->Mp.find(c) == temp->Mp.end())
                return false;
            temp = temp->Mp[c];
        }
        return true;
    }

private:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> Mp;
        bool isEndOfWord = false;
    };
    TrieNode *root;
};
