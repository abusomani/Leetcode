class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // ascending by end first and then descending on begin
        // this is done because i want the end time to be increasing
        // if end time is equal i want the shorter interval first.
        // this is arranging by end time + increasing length of interval
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
           return (a[1] < b[1]) or (a[1] == b[1] and a[0] > b[0]);
        });
        int ans = 0, p1 = -1, p2 = -1, N = intervals.size();
        for(int i=0;i<N;i++) {
            vector<int> interval = intervals[i];
            
            if(p1 >= interval[0])continue; // p1 and p2 will suffice for this interval
            
            if(p2 < interval[0]) { // this is a new big interval, select more two values
                ans += 2;
                p2 = interval[1];
                p1 = p2-1;
            }
            
            if(p2 >= interval[0] and p1 < interval[0]) { // one value matches
                ans++;
                p1 = p2;
                p2 = interval[1];
            }
        }
        
        return ans;
    }
};