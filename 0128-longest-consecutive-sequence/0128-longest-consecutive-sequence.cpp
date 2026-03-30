class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int ans = 1;
        set<int> st;
        for(int i : nums){
            st.insert(i);
        }

        for(auto it = st.begin(); it != st.end(); it++){  
            if(st.find(*it - 1) != st.end()){
                continue;
            }
            int len = 1;
            int curr = *it;

            while(st.find(curr+1) != st.end()){
                curr++;
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};