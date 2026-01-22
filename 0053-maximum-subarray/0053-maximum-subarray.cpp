class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();

        if(n == 1){
            return sum;
        }

        for(int i=0; i<n; i++){
            int test = 0;
            for(int j=i; j<n; j++){
                test += nums[j];
                if(test > sum){
                    sum = test;
                }
            }
            test = 0;
        }
        return sum;
    }
};