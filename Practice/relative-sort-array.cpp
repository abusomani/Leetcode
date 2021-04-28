class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        map<int,int> Mp;
        for(auto num : A)Mp[num]++;
        vector<int> res;
        for(auto num : B){
            while(Mp[num])
                res.push_back(num), Mp[num]--;
        }
        for(auto p: Mp)
            while(p.second)
                res.push_back(p.first), p.second--;
        return res;
    }
};