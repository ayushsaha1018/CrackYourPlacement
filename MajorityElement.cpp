// TC : O(n), SC : O(1)

class Solution {
public:
    int majorityElement(vector<int>& v) {
        int cnt = 0;
        int el;

        for(int i=0; i<v.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = v[i];
            }
            else if(el == v[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        cnt = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] == el)
                cnt++;
        }

        if(cnt > v.size()/2){
            return el;
        }

        return -1;
    }
};