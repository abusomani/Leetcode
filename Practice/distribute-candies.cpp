class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> St(candyType.begin(), candyType.end());
        int N = candyType.size();
        return min((int)N/2, (int)St.size());
    }
};