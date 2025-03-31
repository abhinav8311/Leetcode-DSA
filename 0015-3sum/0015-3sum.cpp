class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();

        if(n<3) return result;//if less than three elements , no triplets

        sort(nums.begin(), nums.end());//sort it to find duplicates 

        for(int i=0;i<n;i++){
            if(nums[i]>0) //if the 1st element is greater than zero, just break coz array is sorted
                break;

            if(i>0 && nums[i]==nums[i-1]) //from the 2nd element , if the value is same as the previous one
                continue;//skip the iteration

            int l=i+1;//take two pointers
            int r=n-1;

            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];//follow two sum with sorted array

                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{//if sum==0
                    result.push_back({nums[i],nums[l],nums[r]});//push the values in result
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }

                }
            }
        }
        return result;
    }
};