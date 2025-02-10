class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = n*(n+1)/2;
        int expectedSum = 0;
        for(auto num: nums){
            expectedSum+=num;
        }

        return actualSum - expectedSum;

    }
};