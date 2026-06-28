class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() % 2) return false;
        unordered_map<char, char> left = {{'(', ')'}, {'{' , '}'}, {'[' , ']'}};
        for (int i = 0; i < s.size(); ++i) {
            if (left.count(s[i])) {
                st.push(s[i]);
            } else {
                if (st.size() == 0) return false;
                char lft = st.top();st.pop();
                if (s[i] != left[lft]) return false;
            }
        }
        return (st.size() == 0);
    }
};
