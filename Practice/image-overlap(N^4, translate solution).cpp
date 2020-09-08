//https://assets.leetcode.com/users/gatorboy/image_1588706215.png
class Solution
{
public:
    int compare(int Xshift, int Yshift, vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int cnt = 0;
        for (int i = Xshift; i < A.size(); i++)
            for (int j = Yshift; j < A[i].size(); j++)
                if (A[i][j] and A[i][j] == B[i - Xshift][j - Yshift])
                    cnt++;
        return cnt;
    }
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int ans = 0;
        for (int x = 0; x < A.size(); x++)
            for (int y = 0; y < A[x].size(); y++)
            {
                ans = max(ans, compare(x, y, A, B)); // shift left and up
                ans = max(ans, compare(x, y, B, A)); // shift down and right / translation
            }
        return ans;
    }
};