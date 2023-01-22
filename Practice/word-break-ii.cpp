class Solution
{
private:
    vector<vector<int>> dp; // from index i, all possible valid lengths
public:
    void init(int N)
    {
        dp.resize(N);
    }
    bool isPossibleWordBreak(string &s, unordered_set<string> &words, set<int> &word_sizes)
    {
        const int N = s.size();
        dp[N].push_back({INT_MAX});
        for (int i = N - 1; i >= 0; i--)
        {
            for (auto &size : word_sizes)
            {
                if (size + i <= N and !dp[size + i].empty())
                {
                    string sub = s.substr(i, size);
                    if (words.count(sub))
                        dp[i].push_back(size);
                }
            }
        }

        return !dp[0].empty();
    }
    void process(int idx, int N, string &s, vector<string> &result, string current)
    {
        if (idx == N)
        {
            result.push_back(current);
            return;
        }

        for (auto &size : dp[idx])
        {
            string sub = s.substr(idx, size);
            string newCurr = current.empty() ? sub : current + " " + sub;
            process(idx + size, N, s, result, newCurr);
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        const int N = s.size();
        init(N + 1); // length N+1

        unordered_set<string> words(wordDict.begin(), wordDict.end());
        set<int> word_sizes;
        for (auto &word : wordDict)
            word_sizes.insert(word.size());

        vector<string> wordBreaks;
        if (!isPossibleWordBreak(s, words, word_sizes))
            return wordBreaks;

        process(0, s.size(), s, wordBreaks, "");
        return wordBreaks;
    }
};