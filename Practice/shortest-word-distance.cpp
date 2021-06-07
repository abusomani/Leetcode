class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = INT_MAX, i = 0;
        unordered_map<string, int> Mp;
        for(auto s: wordsDict){
            Mp[s] = i++;
            if(Mp.count(word1) and Mp.count(word2))
                res = min(res, abs(Mp[word1] - Mp[word2]));
        }
        return res;
    }
};