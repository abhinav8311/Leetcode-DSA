class Solution {
public:
    vector<vector<int>> result;//stores all subsets

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;//stores current subset

        backtrack(nums, 0 , subset);

        return result;

    }

    void backtrack(vector<int>& nums, int i, vector<int>& subset){
        if(i>=nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);//include
        backtrack(nums,i+1,subset);

        subset.pop_back();//exclude
        backtrack(nums,i+1,subset);
    }
};