class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        if(n == 1){
            return strs[0];
        }

        int x = strs[0].length();
        string test = strs[0];
        string word = "";
        for(int i=0; i<x; i++){
            word += test[i];
            for(int j=1; j<n; j++){
                if(!strs[j].starts_with(word))
                    return ans;   
            }
            ans = word;
        }
        return ans;
    }
};