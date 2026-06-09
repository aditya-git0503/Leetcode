class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        const int INF = n + 1;
        vector<int> dp(n,INF);

        dp[n-1] = 0;
        
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=nums[i] && j+i < n; j++){
                if(dp[i+j] != INF){
                    dp[i] = min(dp[i], 1 + dp[i+j]);
                }
            }
        }
        return dp[0];
    }
};