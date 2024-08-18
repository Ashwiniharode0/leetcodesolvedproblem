class Solution {
public:
    int findMax(vector<int>& weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxi=max(weights[i],maxi);
        }
        return maxi;
    }

    int findSum(vector<int>& weights){
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }

    int findDays(vector<int>& weights, int cap){
        int load=0,day=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                day=day+1;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }    

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=findMax(weights);
        int sumOfWeight = findSum(weights);
        int low=maxi, high=sumOfWeight;

        while(low<=high){
            int mid=(low+high)/2;
            int noOfDays=findDays(weights,mid);
            if(noOfDays<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};