class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        vector<int> ans;
        stack<int> st;
        
        for(int i : s){
            if(i > 0){
                st.push(i);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(i)){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(i)){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(i);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        //TC = O(2n), SC = O(n)
    }
};