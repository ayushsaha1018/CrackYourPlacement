// TC : O(nlogn), SC : O(1)

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        
        long long ans = LLONG_MAX;
        for(int i=0; i<a.size()-m+1; i++){
            ans = min(ans, a[i+m-1] - a[i]);
        }
        
        return ans;
    
    }   
};