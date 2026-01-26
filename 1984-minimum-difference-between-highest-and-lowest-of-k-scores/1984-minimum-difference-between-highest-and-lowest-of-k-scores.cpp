class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)
            return 0;
        
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = k-1;
        int n = nums.size();
        int ans = INT_MAX;
        while(r < n){
            ans = min(ans, nums[r] - nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};