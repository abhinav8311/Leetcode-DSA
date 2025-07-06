class Solution {

    const int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int Rows=heights.size();
        int Cols=heights[0].size();

        queue<pair<int,int>> pq,aq;

        vector<vector<bool>> pac(Rows, vector<bool>(Cols,false));
        vector<vector<bool>> atl(Rows, vector<bool>(Cols,false));

        for(int r=0;r<Rows;r++){
            pq.push({r,0});
            aq.push({r,Cols-1});
        }

        for(int c=0;c<Cols;c++){
            pq.push({0,c});
            aq.push({Rows-1,c});
        }

        bfs(pq,heights,pac);
        bfs(aq,heights,atl);

        vector<vector<int>>res;
        for(int r=0;r<Rows;r++){
            for(int c=0;c<Cols;c++){
                if(pac[r][c] && atl[r][c])
                res.push_back({r,c});
            }
        }
        return res;
    }

    private:
        void bfs(queue<pair<int,int>> &q ,vector<vector<int>>& heights ,vector<vector<bool>> &vis){
            while(!q.empty()){
                auto[r,c]=q.front();
                q.pop();
                vis[r][c]=true;

                for(int i=0;i<4;i++){
                    int nr = r + direction[i][0];
                    int nc = c + direction[i][1];

                    if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && heights[nr][nc]>=heights[r][c] && vis[nr][nc]==false){
                        vis[nr][nc]==true;
                        q.push({nr,nc});
                    }
                }
            }
        }
};