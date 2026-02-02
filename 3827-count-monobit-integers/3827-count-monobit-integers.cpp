class Solution {
public:
    int countMonobit(int n) {
        // set<int> st;
        // st.insert(0);
        // for(int i=1; i<=9; i++){
        //     int d = pow(2,i)-1;
        //     st.insert(d);
        // }

        // int ans = 0;
        // for(int i=0; i<=n; i++){
        //     if(st.find(i) != st.end()){
        //         ans++;
        //     }
        // }
        // return ans;
        if(n == 0 || n == 1){
            return (n+1);
        }
        int ans = 2;
        for(int i=2; i<=9; i++){
            if(n >= (pow(2,i)-1)){
                ans++;
            }
        }
        return ans;
    }
};