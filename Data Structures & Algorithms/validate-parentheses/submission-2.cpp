class Solution {
public:
    bool isValid(string s) {

        // Every opening bracket that hasn't been closed yet
        // is stored in the stack.
        stack<char> st;

        for (char c : s) {

            // If we encounter an opening bracket,
            // store it because it needs to be closed later.
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Otherwise, c is a closing bracket.
            else {

                // There must be an opening bracket available
                // to match this closing bracket.
                if (st.empty()) {
                    return false;
                }

                // The most recently opened bracket must be
                // the one that this closing bracket closes.
                if ((c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }

                // The opening bracket has now been correctly closed.
                st.pop();
            }
        }

        // If anything is left, those opening brackets were never closed.
        return st.empty();
    }
};