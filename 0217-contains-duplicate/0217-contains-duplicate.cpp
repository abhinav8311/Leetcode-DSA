class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int i=0; i<=nums.size()-1;i++){
            if(seen.find(nums[i]) != seen.end()){
                return true;//if the element, already in set, return true
            }
            seen.insert(nums[i]);//else insert in set
        }
        return false;//return false if not found
    }
};