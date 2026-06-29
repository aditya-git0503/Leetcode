class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.rbegin(), nums.rend());
        int check = min(k, mul-1);
        int idx = 0;
        int n = nums.size();
        for(int i=1; i<=check && idx < n; i++){
            ans += 1LL * nums[idx] * mul;
            mul--;
            k--;
            idx++;
        }

        if(idx == n){
            return ans;
        }

        while(k && idx < n){
            ans += nums[idx];
            idx++;
            k--;
        }
        return ans;
    }
};