class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string A = "", B = "";
        for(auto &s : word1)A += s;
        for(auto &s : word2)B += s;
        return A == B;
    }
};