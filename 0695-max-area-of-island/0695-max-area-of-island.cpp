class Solution {
public:

    const int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;

        int R=grid.size();
        int C=grid[0].size();

        int maxArea=0;

        for(int r=0; r<R ;r++){
            for(int c=0; c<C; c++){
                if(grid[r][c]==1){
                    maxArea= max(maxArea, bfs(grid,r,c));
                }
            }
        }

        return maxArea;
    }

    int bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int,int>> q;

        q.push({r,c});
        grid[r][c]=0;
        int area=1;

        while(!q.empty()){
            r=q.front().first;
            c=q.front().second;

            q.pop();

            for(int i=0;i<4; i++){
                int newRow = r + direction[i][0];
                int newCol = c + direction[i][1];

                if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && grid[newRow][newCol]==1){
                    q.push({newRow,newCol});
                    grid[newRow][newCol]=0;
                    ++area;
                }
            }
        }
        return area;
    }
};