// TC : O(log26n), SC : O(n)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            columnNumber--;
            int rem = columnNumber % 26;
            ans = char(rem + 'A') + ans;
            columnNumber = columnNumber/26;
        }

        return ans;
    }
};