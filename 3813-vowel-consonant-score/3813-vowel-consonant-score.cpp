class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        int score = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else if(isalpha(ch))
                c++;
        }
        if(c > 0){
            score = (int)floor(v/c);
        }
        else{
            score = 0;
        }
        return score;
    }
};