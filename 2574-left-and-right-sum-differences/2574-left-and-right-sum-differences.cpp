class Solution {
public:

    int left_sum(vector<int>& nums, int j){
        if(j == 0)
            return 0;
        int l = 0;
        for(int i=0; i<j; i++){
            l += nums[i];
        }
        return l;
    }

    int right_sum(vector<int>& nums, int j){
        int n = nums.size();
        int r = 0;
        if(j == n - 1)
            return 0;
        for(int i=n-1; i>j; i--){
            r += nums[i];
        }
        return r;
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ls;
        vector<int> rs;
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            ls.push_back(left_sum(nums,i));
            rs.push_back(right_sum(nums,i));

            int a = abs(ls.back() - rs.back());
            ans.push_back(a);
        }
        return ans;
    }
};