class Solution {
public:
    string makeGood(string s) {
        stack<char> st; st.push(' ');
        for (char c : s)
            if (c - 32 == st.top() || c + 32 == st.top())
                st.pop();
            else st.push(c);
        string ans;
        while (st.size() > 1) {
            ans.push_back(st.top());
            st.pop();
        }
        return string(ans.rbegin(), ans.rend());
    }
};