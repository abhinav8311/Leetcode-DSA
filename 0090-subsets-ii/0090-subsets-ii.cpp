class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curSub;
        sort(nums.begin(), nums.end());
        backtrack(nums, curSub, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int> &curSub, int i){
        if(i==nums.size()){
            result.push_back(curSub);
            return;
        }

        curSub.push_back(nums[i]);
        backtrack(nums,curSub,i+1);

        while(i+1 < nums.size() && nums[i]==nums[i+1]){
            i++;
        }

        curSub.pop_back();
        backtrack(nums,curSub,i+1);
    }
};