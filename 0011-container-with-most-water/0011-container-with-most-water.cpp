class Solution {
public:
    int maxArea(vector<int>& height) {
        int L=0;
        int R=height.size()-1;
        int maxArea=0;

        while(L<R){
            int width=R-L;
            int h=min(height[L],height[R]);

            maxArea = max(maxArea, width*h);

            if(height[L]<height[R]){
                L++;
            }
            else{
                R--;
            }
        }
        return maxArea;
    }
};