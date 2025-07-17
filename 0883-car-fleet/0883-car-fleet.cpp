class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        vector<pair<int,float>> pos_time;

        for(int i=0;i<position.size();i++){
            pos_time.push_back({position[i],float(target-position[i])/speed[i]});
        }

        sort(pos_time.begin(),pos_time.end());

        for(int i=0;i<position.size();i++){
            float fleetIndex=pos_time[i].second;

            while(!st.empty() && (fleetIndex>=st.top())){
                st.pop();
            }
            st.push(fleetIndex);
        }
        return st.size();
    }
};
