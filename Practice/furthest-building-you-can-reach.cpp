class Solution {
public:
    int furthestBuilding(vector<int>& H, int bricks, int ladders) {
        int N = H.size();
        priority_queue<int, vector<int>, greater<int>> PQ;
        for(int i=0; i<N-1; i++){
            int climb = H[i+1]-H[i];
            if(climb <= 0)continue;
            PQ.push(climb);
            if(PQ.size() <= ladders)continue;
            bricks -= PQ.top(); PQ.pop();
            if(bricks < 0)
                return i;
        }
        return N-1;
    }
};