class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis,
            int m, int n, int dr[], int dc[]) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0 ||
            vis[r][c]) {
            return 0;
        }
        vis[r][c] = true;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            area += dfs(grid, nr, nc, vis, m, n, dr, dc);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans, dfs(grid, i, j, vis, m, n, dr, dc));
                }
            }
        }

        return ans;
    }
};