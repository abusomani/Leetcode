class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int baseColor, int newColor){
        if(r < 0 or r >= image.size() or c < 0 or c >= image[0].size() or image[r][c] != baseColor)
            return;
        image[r][c] = newColor;
        dfs(image, r+1, c, baseColor, newColor);
        dfs(image, r-1, c, baseColor, newColor);
        dfs(image, r, c+1, baseColor, newColor);
        dfs(image, r, c-1, baseColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) //same color then no point
            return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};