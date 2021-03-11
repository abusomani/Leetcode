class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if(target < matrix[0][0] or target > matrix[n-1][m-1])
            return false;
        int start = 0, end = m-1;
        while(start < n and end >= 0){
            if(matrix[start][end] == target)return true;
            else if(matrix[start][end] > target)
                end--;
            else
                start++;
        }
        return false;
    }
};