class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> result(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prevIndex=st.top();
                st.pop();
                result[prevIndex]=i-prevIndex;
            }
            st.push(i);
        }
        return result;
    }
};