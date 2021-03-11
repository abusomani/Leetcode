class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> St;
        for(auto &num: nums) {
            St.insert(num%2 == 0 ? num : 2*num); // only insert even
        }
        int diff = *St.rbegin()-*St.begin(); // max difference
        while(*St.rbegin() % 2 == 0) { // until all numbers are odd loop
            int x = *St.rbegin();
            St.erase(x);
            St.insert(x/2);
            diff = min(diff, *St.rbegin()-*St.begin());
        }
        return diff;
    }
};