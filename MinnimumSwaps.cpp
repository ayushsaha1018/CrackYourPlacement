// TC : O(nlogn), SC : O(n)

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> t(n);
	    for(int i=0; i<n; i++)
	        t[i] = {nums[i], i};
	    
	    sort(t.begin(), t.end());
	    
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        while(t[i].second != i){
	            ans++;
	            swap(t[i], t[t[i].second]);
	        }
	    }
	    
	    return ans;
	}
};