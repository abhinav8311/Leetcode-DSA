class Solution {
    int m,n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int r = 0; r<m ;r++){
            for(int c=0 ; c<n ; c++){
                if(board[r][c]==word[0]){
                    if(search(board,word,0,r,c)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word , int i , int r , int c){
        if(word.size() == i) return true;

        if(r<0 || c<0 || r>=m || c>=n || board[r][c] != word[i]) return false;

        board[r][c] = '#';

        bool op1 = search(board,word,i+1,r+1,c);
        bool op2 = search(board,word,i+1,r-1,c);
        bool op3 = search(board,word,i+1,r,c+1);
        bool op4 = search(board,word,i+1,r,c-1);

        board[r][c] = word[i];

        return op1 || op2 || op3 || op4;
    }
};