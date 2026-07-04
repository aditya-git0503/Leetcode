class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& image,
             int color, int drow[], int dcol[], int ini) {
        ans[r][c] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && image[nrow][ncol] == ini && ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, color, drow, dcol, ini);
            } 
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int vis[n][m];
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        dfs(sr, sc, ans, image, color, drow, dcol, ini);
        return ans;
    }
};