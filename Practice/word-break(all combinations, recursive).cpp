/*
DP is a 2D int vector which is of length N and each element corresponds to starting from this index what word length can I take. 
For example, if a string is "abcd" and the dict has "bc" and "bcd" then dp[1] would be a vector of {2,3}.

We iterate from index j from N to 0. At each index, we check if the DP at that index is empty, if it is that means no word can start on that index so we just keep going. 
If it isn't empty then we try each unique word size backwards so s.substr(i - word_size, word_size) to see if it is in the dict. 
If it is then we update dp[i-word_size] to include word_size.

Since we are working backwards, the values at index i are the only possible length of words we can take forward by the time we get to it.


*/
class Solution
{
public:
    void convertLenToStr(int i, string s, string curr, vector<vector<int>> &dp, vector<string> &res)
    {
        if (i == s.size())
        {
            res.push_back(curr);
            return;
        }

        for (const int word_size : dp[i])
        {
            string word = s.substr(i, word_size);
            string new_curr = curr.empty() ? word : curr + " " + word;
            convertLenToStr(i + word_size, s, new_curr, dp, res);
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int N = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        set<int> word_sizes;

        for (const string word : dict)
            word_sizes.insert(word.size());

        vector<vector<int>> dp(N + 1, vector<int>{});
        dp[N].push_back(INT_MAX);

        for (int j = N; j >= 0; j--)
        {
            if (dp[j].empty())
                continue;
            for (const int word_size : word_sizes)
            {
                if (j - word_size < 0)
                    break;
                string word = s.substr(j - word_size, word_size);
                // we store at dp[j-word_size] the word_size if it is a valid word and it ends at a valid index
                // dp[j] isn't empty
                if (dict.count(word))
                {
                    dp[j - word_size].push_back(word_size);
                }
            }
        }

        vector<string> res;
        convertLenToStr(0, s, "", dp, res);
        return res;
    }
};