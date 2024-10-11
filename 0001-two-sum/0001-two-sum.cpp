class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;//declare a map
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];//for each element calculate its compliment value
            if(map.find(diff)!=map.end()){//if that compliment is avalaible, return the complimnet and current index
                return {map[diff],i};
            }

            map[nums[i]]=i;//else enter that value and position in the map
        }
        return {};
    }
};