class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int res=n;//make res=the size, coz the loop will not reach the last element

        for(int i=0;i<n;i++){
            res=res^nums[i]^i;//using the properties a ^ a = 0 and a ^ 0 = a
        }
        return res;//the missing number will be left in res
    }
};