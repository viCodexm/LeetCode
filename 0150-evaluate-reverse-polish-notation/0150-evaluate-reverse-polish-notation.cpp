class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/")
                st.push(stoi(s));
            else {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                if (s == "+")
                    st.push(y + x);
                else if (s == "-")
                    st.push(y - x);
                else if (s == "*")
                    st.push(y * x);
                else if (s == "/")
                    st.push(y / x);
            }
        }
        return st.top();
    }
};