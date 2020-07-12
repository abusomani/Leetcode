class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Mp;
        for(auto str : strs) {
            string orig = str;
            sort(str.begin(),str.end());
            Mp[str].push_back(orig);
        }
        vector<vector<string>> res;
        for(auto i : Mp)
            res.push_back(i.second);
        
        return res;
    }
};