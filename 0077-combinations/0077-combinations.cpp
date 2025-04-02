class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;

        backtrack(n,k,1,curr);
        return result;
    }

    void backtrack(int n, int k, int start, vector<int>& curr){
        if(k==curr.size()){
            result.push_back(curr);
            return;
        }

        for(int i=start; i<=n; i++){
            curr.push_back(i);
            backtrack(n,k,i+1,curr);
            curr.pop_back();
        }
    }
};