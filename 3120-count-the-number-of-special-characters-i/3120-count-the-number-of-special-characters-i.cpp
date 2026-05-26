class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26,0);
        vector<bool> upper(26,0);
        int ans = 0;
        for(char ch : word){
            if(ch>='a' && ch<='z')
                lower[ch-'a'] = 1;
            if(ch>='A' && ch<='Z')
                upper[ch-'A'] = 1;
        }

        for(int i=0;i<26;i++){
            if(upper[i] && lower[i])
                ans++;
        }
        return ans;
    }
};