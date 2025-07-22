class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return result;
    }

    void backtrack(vector<int>& nums, int idx){
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            backtrack(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
};