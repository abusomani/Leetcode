class Solution
{
public:
    vector<vector<string>> result;
    unordered_map<string, unordered_set<string>> neighbors; // to preprocess the neighbors of each string
    unordered_map<string, int> dist;                        // process the minimum distance from beginWord
    int minDist;
    void addNeighbors(string word, unordered_set<string> &words) // & is very important for time saving
    {
        for (int i = 0; i < word.size(); i++)
        {
            string tmp = word;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch == tmp[i])
                    continue;

                tmp[i] = ch;
                if (words.count(tmp))
                    neighbors[word].insert(tmp);
            }
        }
    }
    int bfs(const string &beginWord, const string &endWord, unordered_set<string> &words)
    {
        queue<pair<string, int>> Q;
        Q.push({beginWord, 0});
        while (!Q.empty())
        {
            int N = Q.size();
            while (N--)
            {
                pair<string, int> Pword = Q.front();
                string word = Pword.first;
                Q.pop();

                if (word == endWord)
                    return Pword.second;

                words.erase(word);
                addNeighbors(word, words);

                for (auto neighbor : neighbors[word])
                {
                    if (!dist.count(neighbor)) // visited check ( very important )
                    {
                        dist[neighbor] = Pword.second + 1;
                        Q.push({neighbor, dist[neighbor]});
                    }
                }
            }
        }

        return -1;
    }
    void dfs(string &word, string &endWord, int distance, vector<string> &path)
    {
        path.push_back(word);
        if (word == endWord)
            result.push_back(path);
        for (auto s : neighbors[word])
        {
            if (dist[s] == distance + 1)
                dfs(s, endWord, distance + 1, path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord))
            return result;
        words.insert(beginWord);
        minDist = bfs(beginWord, endWord, words);
        if (minDist == -1)
            return result;
        vector<string> path;
        dfs(beginWord, endWord, 0, path);
        return result;
    }
};