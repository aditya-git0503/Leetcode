class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];

        if(n == 1){
            return s;
        }

        int start = 0;
        int maxlen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }

        for (int len = 3; len <= n; len++) {
            for(int i=0; i<=n-len; i++){
                int j = len -1 + i;

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;

                    if(len > maxlen){
                        start = i;
                        maxlen = len;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};