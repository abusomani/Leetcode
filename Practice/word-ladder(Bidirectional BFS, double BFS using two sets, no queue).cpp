class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end()), beginSet, endSet;
        if (!words.count(endWord))
            return 0;

        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int ladder = 1;
        while (!beginSet.empty() and !endSet.empty())
        {
            if (beginSet.size() > endSet.size()) // beginSet should be smaller always for fast nature
            {
                unordered_set<string> tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }

            unordered_set<string> newSet;
            for (auto word : beginSet)
            {
                words.erase(word); // visited so remove from words dict
                for (int i = 0; i < word.size(); i++)
                {
                    string tmp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        tmp[i] = ch;

                        if (endSet.find(tmp) != endSet.end()) // merge between lists, return
                            return ladder + 1;

                        if (words.count(tmp))
                            newSet.insert(tmp);
                    }
                }
            }

            beginSet = newSet;
            ladder++;
        }

        return 0;
    }
};