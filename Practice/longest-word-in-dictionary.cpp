class Solution
{
private:
    struct TrieNode
    {
        bool isEndOfWord = false;
        unordered_map<char, TrieNode *> Mp;
    };
    TrieNode *root;
    string answer;
    void add(string &s)
    {
        bool isValid = true;
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (!curr->Mp.count(c))
                curr->Mp[c] = new TrieNode();
            curr = curr->Mp[c];
            // do this after previous step, because for root, isEndOfWord is always false
            if (i != s.size() - 1)
                isValid &= curr->isEndOfWord;
        }

        curr->isEndOfWord = true;
        if (isValid and s.size() > answer.size())
            answer = s;
    }

public:
    string longestWord(vector<string> &words)
    {
        root = new TrieNode();
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() == b.size() ? a < b : a.size() < b.size();
        });
        for (auto word : words)
            add(word);

        return answer;
    }
};