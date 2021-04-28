class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = accumulate(distance.begin(), distance.end(), 0), sm = 0;
        for(int i=min(start,destination); i<max(start,destination); i++)
            sm += distance[i];
        return min(sm, total-sm);
        
    }
};