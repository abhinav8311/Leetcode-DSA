class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;
        vector<vector<int>> result;

        for(auto point : points){
            int x=point[0]; int y=point[1];
            int dist = x*x + y*y;
            maxHeap.push({dist,x,y});

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        for(int i=0;i<k;i++){
            vector<int> top = maxHeap.top();
            maxHeap.pop();

            result.push_back({top[1],top[2]});
        }
        return result;
    }
};