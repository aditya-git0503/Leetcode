class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        }

        map<char, int> mpp;
        for(char ch : s){
            mpp[ch]++;
        }

        string left = "", mid = "";
        for(auto it : mpp){
            left += string(it.second/2, it.first);
            if(it.second & 1){
                mid += it.first;
            }
        }
        string ans = left + mid; 
        reverse(left.begin(), left.end());
        ans += left;
        return ans;
    }
};