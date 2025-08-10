class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};

        for(int i=1;i<numRows;i++){
            vector<int> temp;
            vector<int> prev = res.back();
            prev.insert(prev.begin(),0);
            prev.push_back(0);

            for(int j=0;j<=i;j++){
                temp.push_back(prev[j]+prev[j+1]);
            }
            res.push_back(temp);
        }
        return res;
    }
};