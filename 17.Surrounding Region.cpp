class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c,int row,int col){
        if(r<0 || c<0 || r==row || c==col || board[r][c]!='O'){
            return;
        }
        board[r][c] = 'N';
        dfs(board,r+1,c,row,col);
        dfs(board,r-1,c,row,col);
        dfs(board,r,c+1,row,col);
        dfs(board,r,c-1,row,col);
    }
    
    void solve(vector<vector<char>>& board){
        if(board.size()==0 || board[0].size()==0){
            return;
        }
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            dfs(board,i,0,n,m);
            dfs(board,i,m-1,n,m);
        }
        for(int i=0;i<m;i++){
            dfs(board,0,i,n,m);
            dfs(board,n-1,i,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='N'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
