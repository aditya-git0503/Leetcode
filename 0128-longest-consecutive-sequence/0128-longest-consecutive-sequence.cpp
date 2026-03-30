class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        // int ans = 1;
        // set<int> st;
        // for(int i : nums){
        //     st.insert(i);
        // }

        // for(auto it = st.begin(); it != st.end(); it++){  
        //     if(st.find(*it - 1) != st.end()){
        //         continue;
        //     }
        //     int len = 1;
        //     int curr = *it;

        //     while(st.find(curr+1) != st.end()){
        //         curr++;
        //         len++;
        //     }
        //     ans = max(ans, len);
        // }
        // return ans;

        int ans = 1;
        int len = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
            }
            else if(nums[i-1] != nums[i]){
                len = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};