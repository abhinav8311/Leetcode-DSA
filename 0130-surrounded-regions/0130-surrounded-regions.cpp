class Solution {

    const int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

public:
    void solve(vector<vector<char>>& board) {
        int Rows=board.size();
        int Cols=board[0].size();

        bfs(board,Rows,Cols);

        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                else if(board[r][c]=='T'){
                    board[r][c]='O';
                }
            }
        }
    }
private:
    void bfs(vector<vector<char>>& board ,int m , int n){
        queue<pair<int,int>>q;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if((r==0 || c==0 || r==m-1 || c==n-1) && board[r][c]=='O'){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            board[r][c]='T';

            for(int i=0;i<4;i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc]=='O'){
                    q.push({nr,nc});
                }
            }
        }
    }

};