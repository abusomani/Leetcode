class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size() , M = N ? matrix[0].size() : 0 , row = 0, col =  M-1;
        
        while(row < N and row >= 0 and col >= 0 and col < M) {
            if(matrix[row][col] == target)return true;
            else if(matrix[row][col] > target)col--;
            else if(matrix[row][col] < target)row++;
        }
        
        return false;
    }
};