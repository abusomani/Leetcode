class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int expected = k, i = 0, N = arr.size();
        while(i < N and arr[i] <= expected) {
            expected++;
            i++;
        }
        return expected;
    }
};