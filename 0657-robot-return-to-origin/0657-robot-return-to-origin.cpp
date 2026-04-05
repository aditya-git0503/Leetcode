class Solution {
public:
    bool judgeCircle(string moves) {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;

        for(char ch : moves){
            if(ch == 'R')
                a++;
            else if(ch == 'L')
                b++;
            else if(ch == 'U')
                c++;
            else if(ch == 'D')
                d++;
        }
        if((a == b) && (c == d))
            return true;
        return false;
    }
};