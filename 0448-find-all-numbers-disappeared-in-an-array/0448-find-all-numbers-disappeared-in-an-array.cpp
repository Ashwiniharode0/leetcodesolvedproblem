class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set copy(nums.cbegin(),nums.cend());
        int n= nums.size();
        vector<int>res;
        for(int i=1;i<=n;i++){
            if(copy.find(i)!= copy.end()){
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};