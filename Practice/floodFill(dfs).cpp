class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor) // if new is same as old no point of coloring
            return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void dfs(vector<vector<int>> &image, int x, int y, int baseColor, int newColor)
    {
        if (x < 0 or x >= image.size() or y < 0 or y >= image[0].size() or
            image[x][y] != baseColor)
            return;

        image[x][y] = newColor;
        dfs(image, x + 1, y, baseColor, newColor);
        dfs(image, x, y + 1, baseColor, newColor);
        dfs(image, x - 1, y, baseColor, newColor);
        dfs(image, x, y - 1, baseColor, newColor);
    }
};