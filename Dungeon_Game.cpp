class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
	    
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        for(int i= m-1 ;i >= 0 ;i--) // starting from destination itself.
        {
            for(int j = n-1 ; j >= 0 ;j--)
            {
                if(i==m-1 && j==n-1) // at princess's cell or bottom right cell.
                {
                    // if princess cell has negative value then night should have 1 more then that absolute of                          
					//negative value otherwise 1.
                    result[i][j] = (dungeon[i][j] <=0)? (abs(dungeon[i][j])+1) : 1 ; 
                    continue;
                }
                
                if(i < m-1)
                    result[i][j] = min(result[i][j] , (result[i+1][j]-dungeon[i][j])); 
                
                if(j < n-1)
                    result[i][j] = min(result[i][j] , (result[i][j+1]-dungeon[i][j]));
                
                if(result[i][j]<=0)
                    result[i][j] = 1;
                
            }
        }
        return result[0][0];
    }
};
