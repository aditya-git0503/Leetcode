class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0;
        int b = 0;
        int c = 0;
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i] == 5){
                a++;
            }
            else if(bills[i] == 10){
                b++;
                if(a == 0){
                    return false;
                }
                a--;
            }
            else{
                c++;
                if(a == 0){
                    return false;
                }
                if((a*5 + b*10) < 5){
                    return false;
                }

                if(b > 0){
                    b--;
                    a--;
                }
                else{
                    if(a < 3){
                        return false;
                    }
                    else{
                        a = a - 3;
                    }
                }
            }
        }
        return true;
    }
};