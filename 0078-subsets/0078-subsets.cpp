class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;

        backtrack(nums, 0 , subset);

        return result;

    }

    void backtrack(vector<int>& nums, int i, vector<int>& subset){
        if(i>=nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums,i+1,subset);

        subset.pop_back();
        backtrack(nums,i+1,subset);
    }
};