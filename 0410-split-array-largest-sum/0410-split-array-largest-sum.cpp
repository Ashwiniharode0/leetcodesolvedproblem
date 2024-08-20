class Solution {
public:
    int findStu(vector<int>& nums, int pages){
        long long int stu=1,pagesStu=0;
        for(int i=0;i<nums.size();i++){
            if(pagesStu+nums[i] <=pages){
                pagesStu+=nums[i];
            }else{
                stu++;
                pagesStu=nums[i];
            }
        }
        return stu;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            int mid = (low+high)/2;
            int cntStu = findStu(nums,mid);
            if(cntStu > k){
               low=mid+1;   
            }else{
                high=mid-1;
            }
        }
        return low;
    }
}; 