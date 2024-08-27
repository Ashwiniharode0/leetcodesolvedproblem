class Solution {
public:
    int maxElement(vector<vector<int>>& mat,int n,int mid){
        int maxVal=-1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxVal){
                maxVal=mat[i][mid];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(); //row
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxrowidx=maxElement(mat,n,mid);

            int left = mid-1>=0 ? mat[maxrowidx][mid-1] : -1;
            int right= mid+1 < m ? mat[maxrowidx][mid+1] : -1;

            if(mat[maxrowidx][mid]>left && mat[maxrowidx][mid]>right){
                return {maxrowidx,mid};
            }else if(mat[maxrowidx][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};