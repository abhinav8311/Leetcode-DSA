class Solution {

    const int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();

        int fresh=0;
        int time=0;

        queue<pair<int,int>>q;

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++)
            {
                if(grid[r][c]==1){
                    fresh++;
                }

                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }
        

        while(fresh>0 && !q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [row,col]=q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int newRow = row + direction[k][0];
                    int newCol = col + direction[k][1];

                    if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && grid[newRow][newCol]==1){
                        grid[newRow][newCol]=2;
                        fresh--;
                        q.push({newRow,newCol});
                    }
                }
            }
            time++;
        }
        if(fresh>0) return -1;
        
        return time;
    }
};