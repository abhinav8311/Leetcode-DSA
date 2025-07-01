class Solution {

    const int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int R=grid.size();
        int C=grid[0].size();

        if(R<=0 || C<=0) return 0;

        int count=0;

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(grid[r][c]=='1'){
                    bfs(grid,r,c);
                    count++;
                }
            }
        }
        return count;
    }

    private:
        void bfs(vector<vector<char>>& grid, int r , int c){
            queue<pair<int,int>> q;

            grid[r][c]='0';
            q.push({r,c});

            while(!q.empty()){
                r=q.front().first;
                c=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr= r + direction[i][0];
                    int nc= c + direction[i][1];

                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1'){
                        grid[nr][nc]='0';
                        q.push({nr,nc});
                    }
                }

            }
        }
};