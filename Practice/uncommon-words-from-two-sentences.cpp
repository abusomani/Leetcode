class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        unordered_map<string, int> Mp;
        string tmp;
        stringstream sa(A), sb(B);
        while(getline(sa, tmp, ' ')){
            if(!tmp.empty())
                Mp[tmp]++;
        }
        while(getline(sb, tmp, ' ')){
            if(!tmp.empty())
                Mp[tmp]++;
        }
        for(auto p: Mp)
            if(p.second == 1)
                res.push_back(p.first);
        return res;
    }
};