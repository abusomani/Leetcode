class Solution
{
public:
    vector<string> getNeighbors(string word, unordered_set<string> &words)
    {
        vector<string> res;
        for (int i = 0; i < word.size(); i++)
        {
            string tmp = word;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (tmp[i] == ch)
                    continue;
                tmp[i] = ch;
                if (words.count(tmp))
                    res.push_back(tmp);
            }
        }

        return res;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!words.count(endWord))
            return result;

        words.insert(beginWord);
        unordered_set<string> visited;

        vector<string> path;
        path.push_back(beginWord);

        int minLevel = INT_MAX, level = 1;
        queue<vector<string>> Q;
        Q.push(path);
        while (!Q.empty())
        {
            vector<string> P = Q.front();
            Q.pop();

            if (P.size() > level) // kind of delimiter, first P with size bigger than level implies this is a new level
            {
                // reached a new level
                for (auto str : visited)
                    words.erase(str);
                visited.clear();

                if (P.size() > minLevel)
                    break;
                else
                    level = P.size();
            }

            for (auto neighbor : getNeighbors(P.back(), words))
            {
                vector<string> newP = P;
                newP.push_back(neighbor);
                visited.insert(neighbor);
                if (neighbor == endWord)
                {
                    minLevel = level;
                    result.push_back(newP);
                }
                else
                    Q.push(newP);
            }
        }
        return result;
    }
};