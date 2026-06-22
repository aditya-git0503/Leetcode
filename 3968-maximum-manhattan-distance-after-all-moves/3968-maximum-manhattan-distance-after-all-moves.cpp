class Solution {
public:
    int maxDistance(string moves) {
        int hor = 0;
        int ver = 0;
        int count = 0;

        for(char ch : moves){
            if(ch == 'U'){
                ver++;
            }
            else if(ch == 'D'){
                ver--;
            }
            else if(ch == 'L'){
                hor--;
            }
            else if(ch == 'R'){
                hor++;
            }
            else{
                count++;
            }
        }

        int ans = abs(hor) + abs(ver);
        return ans + count;
    }
};