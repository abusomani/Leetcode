class Solution {
public:
    bool closeStrings(string A, string B) {
        int N = A.size(), M = B.size();
        if(N != M)
            return false;
        unordered_set<char> ASt, BSt;
        unordered_map<char,int> AMp, BMp;
        for(auto &c : A)
            ASt.insert(c), AMp[c]++;
        for(auto &c : B)
            BSt.insert(c), BMp[c]++;
        if(ASt != BSt)
            return false;
        vector<int> AV, BV;
        for(auto &i: AMp)AV.push_back(i.second);
        for(auto &i: BMp)BV.push_back(i.second);
        sort(AV.begin(), AV.end());
        sort(BV.begin(), BV.end());
        return AV == BV;
    }
};