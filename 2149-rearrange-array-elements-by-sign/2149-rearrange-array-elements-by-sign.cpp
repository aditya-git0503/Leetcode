class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s);

        int p = 0;
        int n = 1;

        for(int i : nums){
            if(i > 0){
                ans[p] = i;
                p += 2;
            }
            else{
                ans[n] = i;
                n += 2;
            }
        }
        return ans;
    }
};