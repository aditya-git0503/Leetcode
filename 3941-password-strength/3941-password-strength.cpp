class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        map<char, int> mpp;

        for(char ch : password){
            if(isalpha(ch)){
                if(islower(ch))
                    mpp[ch] = 1;
                else
                    mpp[ch] = 2;
            }

            else if(isdigit(ch))
                mpp[ch] = 3;
            else
                mpp[ch] = 5;
        }

        for(auto it : mpp){
            ans += it.second;
        }
        return ans;
    }
};