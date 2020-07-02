class Solution {
public:
    
     bool dfs(vector<vector<char>>& board , string words , int i , int j , int index)
    {
        if(index == words.size())
            return true;
        
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1)
            return false;
        
        if(board[i][j] != words[index])
            return false;
        
        board[i][j] = '#' ;
        
        bool x = dfs(board , words , i-1 , j , index + 1)||
                             dfs(board , words , i+1 , j , index + 1)||
                             dfs(board , words , i , j-1 , index + 1)||
                             dfs(board , words , i , j+1 , index + 1);
        
        board[i][j] = words[index] ;
        return x;
            
    }
     
    void exist(vector<vector<char>>& board, string word)
    {
    	 for(int i=0 ;i<board.size() ; i++)
        {
            for(int j=0; j<board[0].size() ; j++)
            {
                if(dfs(board , word , i , j , 0))
				{
				return true;
				}
            }
        }
        return false;
	}
};
