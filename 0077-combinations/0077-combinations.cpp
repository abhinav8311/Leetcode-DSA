class Solution {
public:
    vector<vector<int>> res;  // Stores all valid combinations

    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;  // Stores the current combination
        backtrack(n, k, 1, cur);  // Start from 1
        return res;
    }

    void backtrack(int n, int k, int i, vector<int>& cur) {
        // ✅ Base Case: If we have k elements, store the combination
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        // ❌ Stop recursion if i exceeds n
        if (i > n) {
            return;
        }

        // ✅ Include current number i
        cur.push_back(i);
        backtrack(n, k, i + 1, cur);

        // \U0001f504 Backtrack: Remove last number and try skipping i
        cur.pop_back();
        backtrack(n, k, i + 1, cur);
    }
};
// \U0001f539 Generates all combinations using backtracking
// \U0001f539 Uses two recursive calls: (1) Include i, (2) Skip i
// \U0001f539 Inefficient: O(2ⁿ) complexity due to redundant calls
// \U0001f539 Can be optimized using a loop + pruning to reduce calls
