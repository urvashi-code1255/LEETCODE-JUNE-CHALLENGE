 class Solution {
public:
    int arrangeCoins(int n) 
    {
        long long start = 0 , end = n , mid , res , temp=0;
        
        while(start <= end )
        {
            mid = start + (end - start)/2 ;
            temp = (mid * (mid+1 ))/2;
            
            if(temp == n)
                return mid;
            
            else if (temp < n)
            {
                res = mid;
                start = mid + 1;
                
            }
            
            else
                end = mid - 1;
        }
        return res;
    }
    
    
};
