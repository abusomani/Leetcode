class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& S, vector<vector<int>>& T, int duration) {
        // Input is not sorted
        sort(S.begin(), S.end());
        sort(T.begin(), T.end());
        vector<pair<int,int>> A;
        int N = S.size(), M = T.size(), i = 0, j = 0;
        while(i < N and j < M){
            if(S[i][1] < T[j][0])
                i++;
            else if(S[i][0] > T[j][1])
                j++;
            else
            {
                A.push_back({max(S[i][0], T[j][0]), min(S[i][1], T[j][1])});
                if(S[i][1] < T[j][1])
                    i++;
                else
                    j++;
            }
        }
        for(auto p: A)
            if(p.second - p.first >= duration)
                return {p.first, min(p.first+duration, p.second)};
        return {};
    }
};
/*
[[10,50],[60,120],[140,210]]
[[0,15],[60,70]]
8
[[10,50],[60,120],[140,210]]
[[0,15],[60,70]]
12
[[216397070,363167701],[98730764,158208909],[441003187,466254040],[558239978,678368334],[683942980,717766451]]
[[50490609,222653186],[512711631,670791418],[730229023,802410205],[812553104,891266775],[230032010,399152578]]
456085
*/