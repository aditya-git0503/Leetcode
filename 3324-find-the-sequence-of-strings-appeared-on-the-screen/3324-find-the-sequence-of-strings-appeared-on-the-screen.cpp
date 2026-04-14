class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";
        int n = target.size();

        for(int i=0; i<n; i++){
            for(char ch = 'a'; ch <= target[i]; ch++){
                ans.push_back(temp + ch);
            }
            temp = temp + target[i];
        }
        return ans;
    }
};