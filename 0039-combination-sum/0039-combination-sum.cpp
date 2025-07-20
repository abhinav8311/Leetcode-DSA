class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curComb;
        backtrack(candidates,target,curComb,0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int> &curComb, int i){
        if(target==0){
            result.push_back(curComb);
            return;
        }

        if(i==candidates.size() || target<0){
            return;
        }
        
        curComb.push_back(candidates[i]);
        backtrack(candidates , target-candidates[i], curComb, i);

        curComb.pop_back();
        backtrack(candidates , target, curComb, i+1);
    }
};