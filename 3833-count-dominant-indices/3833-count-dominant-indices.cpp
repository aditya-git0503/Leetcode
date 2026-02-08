class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<float> a(n-1);

        for(int i=0; i<n-1; i++){
            int sum = 0;
            int count = 0;
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                count++;
            }
            a[i] = (float)(sum/count);
        }

        for(int i=0; i<n-1; i++){
            if(nums[i] > a[i]){
                ans++;
            }
        }
        return ans;
    }
};