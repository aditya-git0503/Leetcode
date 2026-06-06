class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int sum = 0;
        for(int i : nums){
            sum += i;
        }

        int pref = 0;
        ans[0] = sum - nums[0];
        ans[n-1] = sum - nums[n-1];

        for(int i=1; i<n-1; i++){
            pref += nums[i-1];
            ans[i] = abs((pref) - (sum - pref - nums[i]));
        }
        return ans;
    }
};