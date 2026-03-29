class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = n;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1)){
                    mini = min(mini, abs(j-i));
                }
            }
        }
        if(mini == n)
            return -1;
        return mini;
    }
};