class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        if(sum & 1){
            return false;
        }

        int target = sum/2;
        vector<bool> dp(target+1);
        dp[0] = true;

        for(int i : nums){
            for(int j=target; j >= 0; j--){
                if(dp[j] && j + i < target + 1){
                    dp[j + i] = true;
                }
            }
        }
        return dp[target];
    }
};