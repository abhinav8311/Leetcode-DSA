class Solution {
public:
    vector<vector<int>> result;//stores entire result
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>subset;//stores current subset

        dfs(nums,0,subset);
        return result;
    }

    void dfs(vector<int> &nums, int i, vector<int> &subset){
        if(i>=nums.size()){
            result.push_back(subset);//if i reaches final subset, store it and return
            return;
        }

        subset.push_back(nums[i]);//1stly -> include the element and then recure
        dfs(nums,i+1,subset);

        subset.pop_back();//then -> exlude the element and then recure
        dfs(nums,i+1,subset);
    }
};