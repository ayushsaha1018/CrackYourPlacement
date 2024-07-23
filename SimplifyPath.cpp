// TC : O(n), SC : O(n)

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        int n = path.length();
        int i = 0;
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                continue;
            }

            string t = "";
            while (i < n && path[i] != '/') {
                t += path[i];
                i++;
            }

            if (t == ".")
                continue;
            else if (t == "..") {
                if (!st.empty())
                    st.pop();
            } else
                st.push(t);
        }

        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans.length() == 0)
            return "/";
        return ans;
    }
};