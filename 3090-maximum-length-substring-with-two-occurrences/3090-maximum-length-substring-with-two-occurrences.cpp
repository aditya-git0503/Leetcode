class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int n = s.size();
        int len;
        unordered_map<int, int> mpp;
        int l = 0;
        for(int r=0; r<n; r++){
            mpp[s[r]]++;
            while(mpp[s[r]] > 2){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};