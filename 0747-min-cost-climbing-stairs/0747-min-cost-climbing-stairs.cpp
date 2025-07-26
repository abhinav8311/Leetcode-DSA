class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        

        int curr=0;
        int prev=0;
        
        for (int i = 2; i <= n; i++) {
            int temp = min(cost[i-1]+curr , cost[i-2]+prev);
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
};

//for(int i= cost.size()-3;i>=0;i--){
//    cost[i] += min(cost[i+1],cost[i+2]);
//}
//return min(cost[0],cost[1]);