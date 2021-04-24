class Solution {
public:
    vector<int> constructArray(int n, int k) {
         vector<int> beautiful(n);
        int i = 0, l = 1, r = n;
        while (k-- >= 1) {
            beautiful[i++] = (i % 2 == 0) ? l++ : r--;
        }
        bool isR = i%2 == 0;
        while (l <= r)
            beautiful[i++] = isR ? r-- : l++;
        return beautiful;
    }
};
