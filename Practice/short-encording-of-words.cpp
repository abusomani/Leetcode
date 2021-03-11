struct TrieNode
{
    TrieNode *children[26];
};
class Solution
{
private:
    TrieNode *root;
    int insert(string word)
    {
        int diff = INT_MAX;
        TrieNode *curr = root;
        for (auto &c : word)
        {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode(), diff = (int)word.size() + 1;
            curr = curr->children[c - 'a'];
        }
        return diff == INT_MAX ? 0 : diff;
    }

public:
    int minimumLengthEncoding(vector<string> &words)
    {
        root = new TrieNode();
        for (auto &word : words)
            reverse(word.begin(), word.end());
        sort(words.begin(), words.end());
        int N = words.size(), res = 0;
        for (int i = N - 1; i >= 0; i--)
            res += insert(words[i]);
        return res;
    }
};