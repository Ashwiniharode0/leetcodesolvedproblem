class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid,int r,int c){
        //uniqueness 1 to 9 no duplicate 
        unordered_set<int>st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nums =grid[r+i][c+j];
                if(nums<1 || nums>9 ||st.count(nums)){
                    return false;
                }else{
                    st.insert(nums);
                }
            }
        }

        //check sum
        int rSum = grid[r][c]+grid[r][c+1]+grid[r][c+2];

        for(int i=0;i<3;i++){

            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=rSum){
                return false;
            }

            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=rSum){
                return false;
            }
        }

        //diag sum
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rSum){
            return false;
        }

        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=rSum){
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid.size();

        int count=0;

        for(int i=0;i<=rows-3;i++){
            for(int j=0;j<=cols-3;j++){
                if(isMagicGrid(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};