// TC : O(n), SC : O(n)

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            if(i >= 0){
                carry += (a[i] - '0');
                i--;
            }

            if(j >= 0){
                carry += (b[j] - '0');
                j--;
            }

            ans = (carry % 2 == 0 ? '0' : '1') + ans;

            carry = carry/2;
        }

        return ans;
    }
};