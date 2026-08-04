class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=nums[0]; i <= nums[n-1]; i++){
            bool add = true;
            for(int j : nums){
                if(j == i){
                    add = false;
                    break;
                }
            }
            if(add){
                ans.push_back(i);
            }
        }
        return ans;
    }
};