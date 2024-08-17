class Solution {
public:
    long long FindHrs(vector<int>& piles,long int hrs){
        long long minHrs=0;
        for(int i=0;i<piles.size();i++){
            minHrs+=ceil( (double)piles[i] / (double)hrs);
        }
        return minHrs;
    }

    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEle = findMax(piles);
        long int low=1 , high=maxEle;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long minHrs=FindHrs(piles,mid);
            if(minHrs<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};