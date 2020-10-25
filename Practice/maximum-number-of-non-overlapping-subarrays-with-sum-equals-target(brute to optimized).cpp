class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b) {
        return (a.second == b.second) ? a.first > b.first : a.second < b.second;
    }
    int maxOverlappingIntervals(vector<pair<int,int>> &V) {
        sort(V.begin(), V.end(), comp);
        int start = INT_MIN, end = INT_MIN, ans = 0;
        for(auto &p : V) {
            if(p.first > end) { // new interval
                ans++;
                start = p.first;
                end = p.second;
            }
        }
        return ans;
    }
    int maxNonOverlappingMostOptimized(vector<int>& nums, int target) {
        int sum = 0, idx = 0;
        unordered_map<int, int> Mp;
        int start = INT_MIN, end = INT_MIN, ans = 0;
        Mp[0] = {-1};
        for(auto &num : nums) {
            sum += num;
            if(Mp.count(sum - target))
            {
                int S = Mp[sum-target] + 1, E = idx; // from S+1 to end
                if(S > end) {
                    ans++;
                    start = S; 
                    end = E;
                }
            }
            idx++;
            Mp[sum] = idx;
        }
        
        return ans;
    }
    int maxNonOverlappingOptimized(vector<int>& nums, int target) {
        int sum = 0, idx = 0;
        unordered_map<int, int> Mp;
        Mp[0] = {0};
        vector<pair<int,int>> intervals;
        for(auto &num : nums) {
            sum += num;
            if(Mp.count(sum - target)) // find the last index where we got this sum
                intervals.push_back({Mp[sum-target], idx});
            idx++;
            Mp[sum] = idx;
        }
        
        return maxOverlappingIntervals(intervals);
    }
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum = 0, idx = 0;
        unordered_map<int, vector<int>> Mp;
        Mp[0] = {0};
        vector<pair<int,int>> intervals;
        for(auto &num : nums) {
            sum += num;
            if(Mp.count(sum - target))
            {
                for(auto &index : Mp[sum-target]) { //from that index till here
                    intervals.push_back({index, idx});
                }
            }
            idx++;
            Mp[sum].push_back(idx);
        }
        
        // for(auto &p: intervals) {
        //     cout << p.first << " " << p.second << endl;
        // }
        
        return maxOverlappingIntervals(intervals);
    }
};
/*
[-1,3,5,1,4,2,-9]
6
[1,1,1,1,1]
2
[-2,6,6,3,5,4,1,2,8]
10
[0,0,0]
0
*/