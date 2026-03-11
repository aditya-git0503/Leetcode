class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m1;
        for(char ch : s){
            m1[ch]++;
        }

        vector<pair<char,int>> v;
        for(auto it : m1){
            v.push_back({it.first,it.second});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans = "";
        for(auto it : v){
            ans += string(it.second, it.first); 
        }

        return ans;
    }
};
