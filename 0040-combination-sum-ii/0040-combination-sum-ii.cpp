class Solution {
    vector<vector<int>> res; 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;  // Stores the current combination
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, cur, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, vector<int>& cur, int i) {
        // If target is met, store the current combination
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        // If target goes negative or index is out of bounds, stop recursion
        if (target < 0 || i >= candidates.size()) {
            return;
        }

        // Include the current number and continue recursion (can pick the same number again)
        cur.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], cur, i+1);

        while(i+1 < candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        // Backtrack: Remove the last added number and try the next number
        cur.pop_back();

        backtrack(candidates, target, cur, i + 1);
    }
};