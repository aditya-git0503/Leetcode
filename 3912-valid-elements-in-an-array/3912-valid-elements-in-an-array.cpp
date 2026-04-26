class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n == 1 || n == 2){
            return nums;
        }

        vector<int> prev(n);
        vector<int> next(n);

        prev[0] = nums[0];
        prev[1] = nums[0];
        next[n-1] = nums[n-1];
        next[n-2] = next[n-1];
        
        ans.push_back(nums[0]);
        for(int i=2; i<n; i++){
            prev[i] = max(prev[i-1], nums[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            next[i] = max(next[i+1], nums[i+1]);
        }

        for(int i=1; i<n-1; i++){
            if((nums[i] > prev[i]) || (nums[i] > next[i]))
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};
