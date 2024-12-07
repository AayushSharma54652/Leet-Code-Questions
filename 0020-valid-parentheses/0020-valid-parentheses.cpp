class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to store opening brackets
        for (auto it : s) {
            if (it == '(' || it == '[' || it == '{') {
                st.push(it); // Push opening brackets onto the stack
            } else {
                if (st.empty()) return false; // If stack is empty, invalid sequence
                char ch = st.top();
                st.pop();
                // Check if the top of the stack matches the current closing bracket
                if ((it == ')' && ch != '(') || 
                    (it == '}' && ch != '{') || 
                    (it == ']' && ch != '[')) {
                    return false;
                }
            }
        }
        // If the stack is empty, all brackets matched correctly
        return st.empty();
    }

};