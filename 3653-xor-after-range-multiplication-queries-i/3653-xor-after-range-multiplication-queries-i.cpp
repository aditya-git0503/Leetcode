class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        const int MOD = 1e9 + 7;

        for(int i=0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;
            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }

        }

        int ans = 0;
        for(int i : nums){
            ans = ans ^ i;
        }
        return ans;
    }
};