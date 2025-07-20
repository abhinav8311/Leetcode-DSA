class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L=1;
        int R=0;
        for(int i=0;i<piles.size();i++){
            R=max(R,piles[i]);
        }

        int result=R;

        while(L<=R){
            int k=(L+R)/2;
            double hours=0;

            for(int i=0;i<piles.size();i++){
                hours += ceil(double(piles[i])/k);
            }

            if(hours<=h){
                result= min(result,k);
                R=k-1;
            }
            else{
                L=k+1;
            }
        }
        return result;
    }
};