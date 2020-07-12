class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord))
            return 0;

        words.insert(beginWord);
        words.insert(endWord);
        queue<string> Q;
        int ans = 0;
        Q.push(beginWord);
        while (!Q.empty())
        {
            int N = Q.size();
            ans++;
            while (N--)
            {
                string word = Q.front();
                Q.pop();

                words.erase(word);

                if (word == endWord)
                    return ans;

                for (int i = 0; i < word.size(); i++)
                {
                    string tmp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        tmp[i] = ch;
                        if (words.count(tmp))
                            Q.push(tmp);
                    }
                }
            }
        }

        return 0;
    }
};