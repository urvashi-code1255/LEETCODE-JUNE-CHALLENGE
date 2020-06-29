class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        int a[n][m];
        
        //initializing bottom row with 1's since we can only go right, thus only one unique path
        for(int i = 0; i < m; i++)      
            a[n-1][i] = 1;
        
        //initializing rightmost row with 1's since we can only go down, thus only one unique path
        for(int i = 0; i < n; i++)
            a[i][m-1] = 1;
        
        //the number of unique paths at a certain cell is equal to the number of unique paths in the cell to the           
		//right of it plus the number in the cell below it. Hence, we loop through each row and do the addition
        for(int i = n - 2; i >= 0; i--) { 
            for(int j = m - 2;j >= 0; j--) {
                a[i][j] = a[i+1][j] + a[i][j+1];
            }
        }
        return a[0][0];
        //dp[0][0] is the starting cell and we have our desired value inside it so we return it
    }
};
