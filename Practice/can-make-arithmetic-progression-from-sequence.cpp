class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> St;
        for(int i=1; i<arr.size(); i++)
            St.insert(arr[i]-arr[i-1]);
        return St.size() == 1;
    }
};