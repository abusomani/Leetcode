typedef long long ll;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       priority_queue<vector<int>,vector<vector<int>>,compare> MnHp;
       for(auto point : points)
           MnHp.push(point);

        vector<vector<int>>result;
        while(K--){
            result.push_back(MnHp.top());
            MnHp.pop();
        }
        return result;
    }
    
    struct compare{
        bool operator()(const vector<int>&a, const vector<int>&b){
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        }
    };
};