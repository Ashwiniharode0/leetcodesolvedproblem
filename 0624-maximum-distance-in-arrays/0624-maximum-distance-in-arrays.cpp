class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN =arrays[0].front();
        int MAX =arrays[0].back();
        int result=0;

        for(int i=1;i<arrays.size();i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result=max({result,abs(currMin-MAX),abs(currMax-MIN)});
            MIN = min(currMin,MIN);
            MAX= max(currMax ,MAX);
        }
        return result;
    }
};