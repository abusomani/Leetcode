class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> res;
        set<string> words(wordList.begin(), wordList.end());

        set<string> start;
        start.insert(beginWord);
        bool found = false;

        // use hashMap to store all possible route ending at key
        map<string, vector<vector<string>>> Mp;
        vector<string> init;
        init.push_back(beginWord);
        Mp.insert({beginWord, vector<vector<string>>()});
        Mp[beginWord].push_back(init);

        while (!words.empty() && !found && !start.empty())
        {
            // eliminate all previous layer words from dict
            for (auto str : start)
                words.erase(str);
            // use another set to record next layers' words
            set<string> newStart;

            // iterate through all new starts
            for (string s : start)
            {
                vector<vector<string>> endPath = Mp[s];
                for (int i = 0; i < s.size(); i++)
                {
                    // randomly change a character
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (s[i] == ch)
                            continue;

                        char tmp = s[i];
                        s[i] = ch;
                        string word = s;
                        //check if it is in the dict, if so new start found, extending all routes
                        if (words.count(word))
                        {
                            newStart.insert(word);
                            for (vector<string> path : endPath)
                            {
                                vector<string> nextPath(path);
                                nextPath.push_back(word);
                                if (!Mp.count(word))
                                    Mp[word] = vector<vector<string>>();

                                Mp[word].push_back(nextPath);
                                if (word == endWord)
                                {
                                    found = true;
                                    res.push_back(nextPath);
                                }
                            }
                        }

                        s[i] = tmp;
                    }
                }
                Mp.erase(s);
            }

            // clear the previous layers words and update
            start.clear();
            start = newStart;
        }

        return res;
    }
};