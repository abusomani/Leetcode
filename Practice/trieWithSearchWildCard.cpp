class TrieNode
{
public:
    map<char, TrieNode *> Mp;
    bool isEndOfWord = false;
};
class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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
        return search(word, 0, root);
    }

private:
    TrieNode *root;

    bool search(const string &word, int pos, TrieNode *root)
    {
        if (pos == word.size())
            return (root and root->isEndOfWord);
        if (word[pos] != '.')
        {
            if (root and root->Mp.find(word[pos]) == root->Mp.end())
                return false;
            return search(word, pos + 1, root->Mp[word[pos]]);
        }
        for (auto i = root->Mp.begin(); i != root->Mp.end(); i++)
            if (search(word, pos + 1, i->second))
                return true;
        return false;
    }
};
