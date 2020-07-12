class MagicDictionary
{
private:
    struct TrieNode
    {
        bool isEndOfWord = false;
        unordered_map<char, TrieNode *> Mp;
    };
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new TrieNode();
    }

    void add(string &s)
    {
        TrieNode *curr = root;
        for (auto &c : s)
        {
            if (!curr->Mp.count(c))
                curr->Mp[c] = new TrieNode();
            curr = curr->Mp[c];
        }
        curr->isEndOfWord = true;
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (auto &word : dict)
            add(word);
    }

    bool searchInTrie(string &s)
    {
        TrieNode *curr = root;
        for (auto &c : s)
        {
            if (!curr->Mp.count(c))
                return false;
            curr = curr->Mp[c];
        }
        return curr->isEndOfWord;
    }

    // generic find for word with exactly K differences
    bool approxFind(string word, int pos, int k, TrieNode *curr)
    {
        if (k < 0)
            return false;
        if (pos == word.size())
            return (k == 0 and curr and curr->isEndOfWord);

        bool found = false;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (curr->Mp.count(ch))
            {
                if (word[pos] == ch) // k remains same as no change
                    found |= approxFind(word, pos + 1, k, curr->Mp[ch]);
                else // k decreases by 1
                    found |= approxFind(word, pos + 1, k - 1, curr->Mp[ch]);
            }
        }
        return found;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        // brute force search all possible combinations
        TrieNode *curr = root;
        string temp;
        for (int i = 0; i < word.size(); i++)
        {
            temp = word;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (temp[i] == ch)
                    continue;
                swap(temp[i], ch);
                if (searchInTrie(temp))
                    return true;
                swap(temp[i], ch); // very important to make the string same again
            }
        }
        return false;

        //return approxFind(word, 0, 1, root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */