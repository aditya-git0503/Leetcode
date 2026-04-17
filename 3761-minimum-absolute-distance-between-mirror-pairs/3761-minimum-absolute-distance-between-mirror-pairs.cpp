class Solution {
public:

    int reverse(int num){
        int ans = 0;
        while(num != 0){
            int d = num % 10;
            ans = ans * 10 + d;
            num /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(mpp.find(nums[i]) != mpp.end()){
                ans = min(ans, i - mpp[nums[i]]);
            }

            int rev = reverse(nums[i]);
            mpp[rev] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};