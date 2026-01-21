class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> freq;
        string word = "";

        s1 += " ";
        s2 += " ";

        for(char ch : s1){
            if(ch != ' '){
                word += ch;
            }
            else{
                freq[word]++;
                word = "";
            }
        }

        for(char ch : s2){
            if(ch != ' '){
                word += ch;
            }
            else{
                freq[word]++;
                word = "";
            }
        }

        for(auto it : freq){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};