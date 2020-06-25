class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int n=citations.size(); // size of array
        int left=0,right=n-1;     //applying binary search
        
        while(left<=right)
        {
            int mid=(left+right)/2; 
            
            if(citations[mid]<n-mid) 
                left=mid+1;
            else 
                right=mid-1;
        }
        return n-left;
    }
};
