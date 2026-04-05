class Solution {
public:
    bool judgeCircle(string moves) {
        int a = 0;
        int b = 0;

        for(char ch : moves){
            if(ch == 'R')
                a++;
            else if(ch == 'L')
                a--;
            else if(ch == 'U')
                b++;
            else if(ch == 'D')
                b--;
        }
        return (a == 0 && b == 0);
    }
};