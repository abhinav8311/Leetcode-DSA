//1.open(== close)==n
//2.close can never be > open 

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n,0,0,"",result);
        return result;
    }
    void generateParenthesisHelper(int n, int openN , int closeN , string str ,vector<string>& res){//backtracking used
        if(openN==n && closeN==n){//if open and close parenthesis limit reached
            res.push_back(str);//push the final string in result and return
            return;
        }
        if(openN<n){
            generateParenthesisHelper(n,openN+1,closeN,str+'(',res);
        }
        if(closeN<openN){
            generateParenthesisHelper(n,openN,closeN+1,str+')',res);
        }
    }
};