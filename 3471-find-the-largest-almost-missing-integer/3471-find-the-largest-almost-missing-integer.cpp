class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1){
            unordered_map<int, int> mpp;
            for(int i : nums){
                mpp[i]++;
            }
            int ans = -1;
            for(int i : nums){
                if(mpp[i] == 1){
                    ans = max(ans, i);
                }
            }
            return ans;
        }

        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }

        int a = 0, b = 0;
        for(int i : nums){
            if(i == nums[0]){
                a++;
            }
            if(i == nums[n-1]){
                b++;
            }
        }

        int ans = -1;
        if(a == 1){
            ans = max(ans, nums[0]);
        }
        if(b == 1){
            ans = max(ans, nums[n-1]);
        }
        return ans;
    }
};