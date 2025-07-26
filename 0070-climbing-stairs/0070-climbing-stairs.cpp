class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return n;

        int cur=1;
        int prev=1;

        for(int i=2;i<=n;i++){
            int temp = cur+prev;
            prev = cur;
            cur = temp;
        }

        return cur;
    }
};