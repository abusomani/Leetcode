class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = accumulate(data.begin(), data.end(), 0), res = INT_MAX, cnt = 0;
        for(int i=0; i<k; i++)
            cnt += data[i] == 0;
        for(int i=k; i<= data.size(); i++){
            res = min(res, cnt);
            cnt -= data[i-k] == 0;
            if(i < data.size())
                cnt += data[i] == 0;
        }
        return res;
    }
};