class Solution {
public:
    vector<int> dp;

    bool solve(int i, string s, vector<string>& wordDict) {
        int n = s.size();
        if (i == n) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        for (string word : wordDict) {
            int len = word.size();
            if ((i + len <= n) && (s.substr(i, len) == word)) {
                if (solve(i + len, s, wordDict)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) { 
        int n = s.size();
        dp.assign(n, -1);
        return solve(0, s, wordDict);
    }
};