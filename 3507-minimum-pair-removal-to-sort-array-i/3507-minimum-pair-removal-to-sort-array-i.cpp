class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        if (check(nums)) {
            return 0;
        }
        int ans = 0;

        while (!check(nums)) {
            int n = nums.size();
            int idx = 0;
            int sum = nums[0] + nums[1];

            for(int i=1; i<n-1; i++){
                int curr = nums[i] + nums[i+1];
                if(curr < sum){
                    sum = curr;
                    idx = i;
                }
            }
            nums[idx] = sum;
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }
        return ans;
    }
};