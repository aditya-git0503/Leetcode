class Solution {
public:

    string func(string num){
        int ans = 0;
        string s = "";
        int n = num.size();
        for(int i=0; i<n; i++){
            if(num[i] == '0' || num[i] == '1' || num[i] == '8')
                s += num[i];
            else if(num[i] == '2')
                s += '5';
            else if(num[i] == '5')
                s += '2';
            else if(num[i] == '6')
                s += '9';
            else if(num[i] == '9')
                s += '6';
            else
                return "invalid";
        }
        return s;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            string str = to_string(i);
            if(func(str) == "invalid")
                continue;
            else if(str != func(str)){
                ans++;
                cout<<str<<endl;
            }
        }
        return ans;
    }
};