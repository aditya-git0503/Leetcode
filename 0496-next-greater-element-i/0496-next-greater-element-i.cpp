class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1, -1);
        unordered_map<int,int> mpp;
        for(int i=0; i<n1; i++){
            mpp[nums1[i]] = i; 
        }

        stack<int> st;

        for(int i=0; i<n2; i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                int v = nums2[st.top()];
                if(mpp.contains(v)){
                    ans[mpp[v]] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};