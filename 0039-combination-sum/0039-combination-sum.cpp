class Solution {
public:
    vector<vector<int>> res;  // Stores all valid combinations

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;  // Stores the current combination
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
        backtrack(candidates, target - candidates[i], cur, i);

        // Backtrack: Remove the last added number and try the next number
        cur.pop_back();
        backtrack(candidates, target, cur, i + 1);
    }
};

/* 
 Important Notes:
- **Backtracking** is used to explore all possible combinations.
- **Duplicates are avoided** by always moving to the next index in the second recursive call.
- **Same number can be used multiple times** (first recursive call keeps `i` unchanged).
- **Time Complexity**: Exponential (worst case O(2^N)), as every number is either included or not in each recursive call.
- **Space Complexity**: O(target/min_element) (due to recursion depth).
*/
