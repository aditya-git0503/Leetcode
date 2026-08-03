class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int l = 0;
        int r = n - 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                int a = piles[l] - dp[l + 1][r];
                int b = piles[r] - dp[l][r - 1];
                dp[l][r] = max(a, b);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};