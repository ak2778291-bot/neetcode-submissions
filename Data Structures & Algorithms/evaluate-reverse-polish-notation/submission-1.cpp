class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (string token : tokens) {

            // If token is a number, convert it to int and push it.
            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                st.push(stoi(token));
            }

            // Otherwise, token is an operator.
            else {
                // The first value popped is the RIGHT operand.
                int right = st.top();
                st.pop();

                // The second value popped is the LEFT operand.
                int left = st.top();
                st.pop();

                int result;

                if (token == "+") {
                    result = left + right;
                }
                else if (token == "-") {
                    result = left - right;
                }
                else if (token == "*") {
                    result = left * right;
                }
                else {
                    result = left / right;
                }

                // The result becomes an operand for future operations.
                st.push(result);
            }
        }

        // The final result is the only value left in the stack.
        return st.top();
    }
};