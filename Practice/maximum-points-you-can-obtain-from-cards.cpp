class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0), ans = INT_MAX;
        int res = 0;
        k = cardPoints.size()- k;
        for(int i=0; i<k; i++)
            res += cardPoints[i];
        for(int i=k; i<=cardPoints.size(); i++)
        {
            ans = min(ans, res);
            if(i == cardPoints.size())break;
            res -= cardPoints[i-k];
            res += cardPoints[i];
        }
        return total-ans;
    }
};