typedef long long ll;
class Solution {
public:
    static bool compareInterval(const vector<int> a, const vector<int> b){
        ll aS = (a[0]*a[0] + a[1]*a[1]);
        ll bS = (b[0]*b[0] + b[1]*b[1]);
        
        return (aS < bS);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        sort(points.begin(), points.end(), compareInterval);
        int i = 0;
        while(K--){
            result.push_back(points[i++]);
        }
        
        return result;
    }
};