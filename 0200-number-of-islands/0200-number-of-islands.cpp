class Solution {
    const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c, rows, cols);
                    ++count;
                }
            }
        }
        return count;
    }

private:
    inline void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        queue<int> q; // Flatten pair into single int for perf
        q.push(r * cols + c);
        grid[r][c] = '0';

        while (!q.empty()) {
            int idx = q.front(); q.pop();
            int row = idx / cols, col = idx % cols;

            for (int i = 0; i < 4; ++i) {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    q.push(nr * cols + nc); // Encode again
                }
            }
        }
    }
};
