class Solution {
public:
    bool findtarget(vector<int>& matrix,int m,int target){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid]==target) return true;
            if(matrix[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    } 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool ans;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
             {
            ans = findtarget(matrix[i],m,target);
            }
        }
        return ans;
    }
};