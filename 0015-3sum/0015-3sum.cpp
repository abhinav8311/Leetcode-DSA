class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;

        sort(nums.begin(), nums.end());

        if(n<3 || nums[0]>0) return result;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int target = -nums[i];

            int L=i+1; int R=n-1;

            while(L<R){
                int sum=nums[L]+nums[R];

                if(sum==target){
                    result.push_back({nums[i],nums[L],nums[R]});

                    while(L<R && nums[L]==nums[L+1]){
                        L++;
                    }
                    L++;
                    R--;
                }
                else if(sum<target){
                    L++;
                }
                else{
                    R--;
                }
            }
        }
        return result;
    }
};