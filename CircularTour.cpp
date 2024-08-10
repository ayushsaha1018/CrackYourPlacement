class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int total = 0;
       int remaining = 0;
       int ans = 0;
       
       for(int i=0; i<n; i++){
           remaining += p[i].petrol - p[i].distance;
           total += p[i].petrol - p[i].distance;
           if(remaining < 0){
               ans = i+1;
               remaining = 0;
           }
       }
       
       if(total < 0)
         return -1;
       
       return ans;
    }
};
