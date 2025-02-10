class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(auto num :nums){
            mpp[num]++;
        }
        for(auto val:mpp){
            if(val.second>1)
            return true;
        }
        return false;
    }
};