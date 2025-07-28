class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        int rob1=nums[0];
        int rob2=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};