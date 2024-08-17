class Solution {
public:
    int MinRes(vector<int>& nums, int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=MinRes(nums,mid);
            if(sum<=threshold){
                high=mid-1;
                
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};