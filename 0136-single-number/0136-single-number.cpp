class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            res=res^nums[i];//a ^ a = 0 and a ^ 0 = a, using this property, the single number will be left alone
        }
        return res;
    }
};