class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string str = "";
        for(char ch : s){
            if(ch != ' '){
                str += ch;
            }
            else{
                if(!str.empty()){
                    words.push_back(str);
                    str.clear();
                }
            }
        }
        if(!str.empty()){
            words.push_back(str);
        }
        
        reverse(words.begin(), words.end());
        string ans = "";
        for(string s : words){
            ans += s + " ";
        }
        return ans.substr(0, ans.length() - 1);
    }
};