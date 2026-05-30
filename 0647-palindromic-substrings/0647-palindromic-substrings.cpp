class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        bool dp[n][n];

        if (n == 1) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = len - 1 + i;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};