class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();//no. of rows
        int n=matrix[0].size();//no. of columns
        int l=0;
        int r=m*n-1;//total size

        while(l<=r){
            int mid=(l+r)/2;
            int midVal=matrix[mid/n][mid%n];//mid/n gives row index, ,mid%n gives column index
            
            if(midVal<target){
                l=mid+1;
            }
            else if(midVal>target){
               r=mid-1;
            }
            else if(midVal==target){
                return true;
            }
        }
        return false;
    }
};