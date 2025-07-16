class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        backtrack(0,0,"",res,n);

        return res;
    }
private:
    void backtrack(int openN, int closeN, string st ,vector <string> &res, int n){
        if(openN == n && closeN == n){
            res.push_back(st);
            return;
        }
        if(openN < n){
            backtrack(openN+1,closeN,st+'(',res,n);
        }
        if(closeN < openN){
            backtrack(openN,closeN+1,st+')',res,n);
        }
    }
};