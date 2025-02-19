class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;

        backtrack(n,k,1,cur);
        return res;
    }

    void backtrack(int n,int k,int i,vector<int> &cur){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }

        if(i>n){
            return;
        }

        cur.push_back(i);
        backtrack(n,k,i+1,cur);
        cur.pop_back();
        backtrack(n,k,i+1,cur);
    }
};