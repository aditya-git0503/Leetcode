class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0)
            return false;
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            else{
                if(st.empty()){
                    return false;
                }

                char c1 = st.top();
                st.pop();
                if((c1 == '(' && ch != ')') || (c1 == '{' && ch != '}') || (c1 == '[' && ch != ']')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};