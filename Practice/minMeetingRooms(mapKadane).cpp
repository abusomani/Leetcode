class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> Mp;
        for(auto interval : intervals){
            Mp[interval[0]] += 1;
            Mp[interval[1]] -= 1;
        }
        int rooms = 0, maxRooms = 0;
        for(auto change : Mp){
            maxRooms = max(maxRooms, rooms += change.second);
        }
        
        return maxRooms;
    }
};