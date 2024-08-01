// TC : O(nlogn), SC : O(1)

class Solution {
public:
    bool isPossible(int n, int k, vector<int> &stalls, int mid){
        int cows = 1;
        int prev = 0;
        for(int i=1; i<n; i++){
            if(stalls[i] - stalls[prev] >= mid){
                cows++;
                prev = i;
            }
        }
        
        return cows >= k;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int st = 0;
        int en = stalls[n-1] - stalls[0];
        
        int ans = -1;
        while(st <= en){
            int mid = (st + en)/2;
            
            if(isPossible(n, k, stalls, mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
        }
        
        return ans;
    }
};