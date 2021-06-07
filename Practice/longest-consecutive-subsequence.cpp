class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> St(nums.begin(), nums.end());
        int res = 0;
        for(auto n: St){
            if(St.count(n-1))continue;
            int cnt = 1, i = n;
            while(St.count(i+1))
                cnt++, i++;
            res = max(res, cnt);
        }
        return res;
    }
};