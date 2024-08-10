class Solution {
public:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOperator(int a, int b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const auto& token : tokens) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(applyOperator(a, b, token));
            } else {
                st.push(std::stoi(token));
            }
        }

        return st.top();
    }
};