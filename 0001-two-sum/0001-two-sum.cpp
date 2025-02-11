class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int diff = target-arr[i];

            if(mpp.find(diff)!=mpp.end()){
                return {i, mpp[diff]};
            }
            mpp[arr[i]] =i;
        }
        return {-1,-1};
    }
};