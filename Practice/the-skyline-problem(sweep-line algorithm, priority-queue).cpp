class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vector<pair<int, int>> walls;                  // first: x, second: height
        vector<vector<int>> ans;
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) {
            if (w.second < 0) {                             // it's a left wall, insert the height
                leftWallHeights.insert(-w.second);
            } else {                                        // it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            
            if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                ans.push_back({w.first, top = *leftWallHeights.rbegin()});
            }
        }
        
        return ans;
    }
};