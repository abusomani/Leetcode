struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord = false;
};
class StreamChecker
{
private:
    TrieNode *root;
    deque<char> Dq;
    int maxLen = 0;

    void insert(string s)
    {
        TrieNode *curr = root;
        for (auto c : s)
        {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        maxLen = max(maxLen, (int)s.size());
    }

    void buildTrie(vector<string> &words)
    {
        for (auto word : words)
        {
            reverse(word.begin(), word.end());
            insert(word);
        }
    }

public:
    StreamChecker(vector<string> &words)
    {
        Dq.clear();
        root = new TrieNode();
        maxLen = 0;
        buildTrie(words);
    }

    bool query(char letter)
    {
        Dq.push_back(letter);
        if (Dq.size() > maxLen) // for space optimization
            Dq.pop_front();

        TrieNode *curr = root;
        for (int i = Dq.size() - 1; i >= 0; i--)
        {
            if (!curr->children.count(Dq[i]))
                return false;
            curr = curr->children[Dq[i]];
            if (curr->isEndOfWord)
                return true;
        }
        return false;
    }
};