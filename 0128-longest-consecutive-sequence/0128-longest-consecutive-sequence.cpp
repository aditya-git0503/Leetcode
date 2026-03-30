class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        int ans = 1;
        int len = 1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
            }
            else if(nums[i-1] != nums[i]){
                len = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};