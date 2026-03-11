class Solution {
public:
    int bitwiseComplement(int n) {
        int num = 1;
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 0;
        }

        do{
            num *= 2;
        }while(num <= n);

        return (num - n - 1);
    }
};