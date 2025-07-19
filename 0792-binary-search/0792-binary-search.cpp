class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L=0;
        int R=nums.size();

        while(L<R){

            int mid= (L+R)/2;

            if(target > nums[mid]){
                L++;
            }
            else if(target < nums[mid]){
                R--;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};