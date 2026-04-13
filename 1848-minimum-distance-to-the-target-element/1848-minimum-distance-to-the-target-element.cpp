class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            if(nums[l] == target){
                ans = min(ans, abs(l - start));
            }
            if(nums[r] == target){
                ans = min(ans, abs(r - start));
            }

            if(ans == 0)
                return ans;

            l++;
            r--;
        }
        return ans;
    }
};