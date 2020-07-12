class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Mp;
        for(auto str : strs) {
            string orig = str;
            Mp[strSort(str)].push_back(orig);
        }
        vector<vector<string>> res;
        for(auto i : Mp)
            res.push_back(i.second);
        
        return res;
    }
private:
    string strSort(string s){
        int n = s.size(), counter[26] = {0};
        for(auto i : s) {
            counter[i - 'a']++;
        }
        string t;
        for(int i=0;i<26;i++)
            t += string(counter[i], i + 'a');
        return t;
    }
};