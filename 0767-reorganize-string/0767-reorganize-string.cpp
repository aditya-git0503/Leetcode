class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<pair<int, char>> freq;
        int alpha[26] = {};

        for (char ch : s) {
            alpha[ch - 'a']++;
        }

        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, alpha[i]);
        }

        if(maxFreq > (n+1)/2){
            return "";
        }

        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 0) {
                freq.push_back({alpha[i], 'a' + i});
            }
        }

        sort(freq.rbegin(), freq.rend());

        string ans(n,' ');
        int idx = 0;

        for(auto it : freq){
            while(it.first > 0){
                ans[idx] = it.second;
                idx += 2;

                if(idx >= n){
                    idx = 1;
                }
                it.first--;
            }
        }
        return ans;
    }
};