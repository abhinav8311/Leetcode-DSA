class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int L=0;
        int R=m*n-1;

        while(L<=R){
            int mid=(L+R)/2;
            int midVal=matrix[mid/n][mid%n];

            if(target < midVal){
                R--;
            }
            else if(target > midVal){
                L++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};