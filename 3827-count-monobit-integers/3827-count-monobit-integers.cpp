class Solution {
public:
    int countMonobit(int n) {
        set<int> st;
        st.insert(0);
        for(int i=1; i<=9; i++){
            int d = pow(2,i)-1;
            st.insert(d);
        }

        int ans = 0;
        for(int i=0; i<=n; i++){
            if(st.find(i) != st.end()){
                ans++;
            }
        }
        return ans;
    }
};