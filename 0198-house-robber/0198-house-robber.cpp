class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = 0;

        for(int i : nums){
            int curr = max(prev1, i+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};