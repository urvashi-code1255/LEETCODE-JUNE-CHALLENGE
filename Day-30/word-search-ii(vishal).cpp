class Solution
{
public:
    bool check(vector<vector<char>>& board,int i,int j,int row,int col,int index,string word)
    {
        if(index == word.size())
            return true;

        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] == '#' || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = check(board,i+1,j,row,col,index+1,word) || check(board,i,j+1,row,col,index+1,word) ||
                     check(board,i-1,j,row,col,index+1,word) || check(board,i,j-1,row,col,index+1,word);

        board[i][j] = temp;

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board,vector<string>& words)
    {
        int row = board.size();
        int col = board[0].size();
        int ws = words.size();

        vector<string>ans;

        for(int k=0; k<ws; k++)
        {
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    if(board[i][j] == words[k][0])
                    {
                        if(words[k].size() == 1)
                            ans.push_back(words[k]);
            
                        else if(check(board,i,j,row,col,0,words[k]))
                            ans.push_back(words[k]);
                    }
                }
            }
        }
        auto itr = unique(ans.begin(),ans.end());
        ans.erase(itr,ans.end());
        return ans;
    }
};
