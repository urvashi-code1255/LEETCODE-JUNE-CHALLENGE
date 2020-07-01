class Solution {
public:
    int arrangeCoins(int n) 
    {
        return (sqrt((long long )8*n + 1) - 1) / 2 ;
    }
    
    /* as to form a triangle the pattern will be : *
                                                   *  *
                                                   *  *  *
      which means no of coins in row-0 = 1 , row-1 = 2 , row-2 = 3 ....
      
      1
      2
      3
      4
      .
      .
      .
      .
      
      sum of this pattern is 1+2+3+4........+k
      where k is no of rows so 
      1+2+3+4.....+k < = n
      k*(k+1)/2 < = n
      for maximum rows 
      k*(k+1)/2 = n
      k^2 + k = 2n
      k^2 + k - 2n = 0
      k = -1 +- sqrt(1^2 - 4*1*(-2n)^2)/2
      k = -1 + sqrt(1 + 8*n)/2    (for maximum rows we will take +)..
      
      */
};
