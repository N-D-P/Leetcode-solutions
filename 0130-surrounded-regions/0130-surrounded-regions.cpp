class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        if(r<0 or c<0 or r>=board.size() or c>=board[0].size() or board[r][c] != 'O')
            return;
        if(board[r][c] == 'O') board[r][c] = 'Y';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0; i<r; i++) {
            if(board[i][0] == 'O')
                dfs(i,0,board);
             if(board[i][c-1] == 'O')
                dfs(i,c-1,board);
        }
        
        for(int i=0; i<c; i++) {
            if(board[0][i] == 'O')
                dfs(0,i,board);
             if(board[r-1][i] == 'O')
                dfs(r-1,i,board);
        }
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';  
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
  
            }
                
        return;
    }
};