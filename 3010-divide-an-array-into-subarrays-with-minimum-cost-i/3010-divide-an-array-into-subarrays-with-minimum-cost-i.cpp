class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n == 3){
            return (nums[0] + nums[1] + nums[2]);
        }

        int ans = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());
        ans += nums[0] + nums[1];
        return ans;
    }
};