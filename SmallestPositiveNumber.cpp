// TC : O(n), SC : O(1)

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        bool contains1 = false;
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                contains1 = true;
            }
            
            if(arr[i] <= 0 || arr[i] > n){
                arr[i] = 1;
            }
        }
        
        if(!contains1)
            return 1;
        
        for(int i=0; i<n; i++){
            int num = abs(arr[i]);
            int idx = num - 1;
            
            if(arr[idx] < 0)
                continue;
            
            arr[idx] *= -1;
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] > 0)
                return i+1;
        }
        
        return n+1;
    } 
};