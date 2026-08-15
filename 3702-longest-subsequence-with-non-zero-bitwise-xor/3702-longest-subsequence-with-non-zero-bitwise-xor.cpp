class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        for(int i : nums){
            x = x ^ i;
        }
        if(x != 0){
            return nums.size();
        }
        for(int i : nums){
            if(i != 0){
                return nums.size() - 1;
            }
        }
        return 0;
    }
};