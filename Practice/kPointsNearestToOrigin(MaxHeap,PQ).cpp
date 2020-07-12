typedef long long ll;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       priority_queue<vector<int>,vector<vector<int>>,compare> MxHp;
       for(auto point : points)
       {
           MxHp.push(point);
           if(MxHp.size() > K)
               MxHp.pop();
       }

        vector<vector<int>>result;
        while(K--){
            result.push_back(MxHp.top());
            MxHp.pop();
        }
        return result;
    }
    
    struct compare{
      bool operator()(const vector<int>&a, const vector<int> &b){
          return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
      }  
    };
};