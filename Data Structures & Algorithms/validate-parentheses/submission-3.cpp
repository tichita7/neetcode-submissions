class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;

        for(auto& ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch); //only insert opening brackets
            } else{
                if(st.empty()) return false;

                if( (ch == ')' && st.top() != '(') ||
                        (ch == '}' && st.top() != '{') ||
                        (ch == ']' && st.top() != '[') ){
                            return false;
                }
                st.pop(); //if valid then keep popping
            }
            
        }
        return st.empty();
    }
};
