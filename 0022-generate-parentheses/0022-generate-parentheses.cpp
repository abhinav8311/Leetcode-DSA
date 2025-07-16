class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        string curr;
        backtrack(0,0,curr,res,n);
        return res;
    }
private:
    void backtrack(int openN, int closeN, string &curr ,vector <string> &res, int n){
        if(openN == n && closeN == n){
            res.push_back(curr);
            return;
        }
        if(openN < n){
            curr.push_back('(');
            backtrack(openN+1,closeN,curr,res,n);
            curr.pop_back();
        }
        if(closeN < openN){
            curr.push_back(')');
            backtrack(openN,closeN+1,curr,res,n);
            curr.pop_back();
        }
    }
};