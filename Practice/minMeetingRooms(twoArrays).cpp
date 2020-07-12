class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int N = intervals.size();
        if(N == 0)return 0;
        
        // does not matter which meeting, rooms matter
        vector<int> starting, ending;
        for(auto interval : intervals){
            starting.push_back(interval[0]);
            ending.push_back(interval[1]);
        }
        
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        
        int l_ptr = 0, e_ptr = 0, rooms = 0;
        
        while(l_ptr < N)
        {
            if(starting[l_ptr] >= ending[e_ptr]) {
                e_ptr++;
                rooms--;
            }
            l_ptr++;
            rooms++;
        }
        
        return rooms;
    }
};