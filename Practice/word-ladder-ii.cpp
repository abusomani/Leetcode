class Solution
{
private:
    vector<vector<string>> ladder;

public:
    vector<string> getNewWords(string s, unordered_set<string> &words)
    {
        vector<string> res;
        for (int i = 0; i < s.size(); i++)
        {
            string word = s;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                // original character is s[i]
                if (ch == s[i])
                    continue;
                word[i] = ch;
                if (words.count(word))
                    res.push_back(word);
            }
        }
        return res;
    }
    void BFS(unordered_set<string> &words, string begin, string end)
    {
        queue<vector<string>> Q;
        Q.push({begin});
        int minDist = INT_MAX;
        while (!Q.empty())
        {
            int sz = Q.size();
            unordered_set<string> visited;
            while (sz--)
            {
                vector<string> V = Q.front();
                Q.pop();

                if (V.size() > minDist)
                    continue;

                if (V.back() == end)
                {
                    ladder.push_back(V);
                    continue;
                }

                string word = V.back();
                visited.insert(word);
                for (auto &newWord : getNewWords(word, words))
                {
                    visited.insert(newWord);
                    V.push_back(newWord);
                    Q.push(V);
                    if (newWord == end)
                        minDist = min(minDist, (int)V.size());
                    V.pop_back();
                }
            }
            for (auto &v : visited)
                if (words.count(v))
                    words.erase(v);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord))
            return ladder;
        BFS(words, beginWord, endWord);
        return ladder;
    }
};