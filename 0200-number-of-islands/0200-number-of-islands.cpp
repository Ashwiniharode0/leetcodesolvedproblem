class Solution {
private:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};

    bool valid_index(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }

    void dfs(int i, int j,vector<vector<char>>&grid){
        
        grid[i][j] = '0';
        for(int k=0; k<4; k++) {
            int ci=DR[k]+i;
            int cj=DC[k]+j;
            if(!valid_index(ci, cj, grid))
                continue;
            if(grid[ci][cj]=='1')
                dfs(ci, cj, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int row = grid.size();
      int col = grid[0].size();
      int islands = 0;

      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == '1'){
                islands++;
                dfs(i,j,grid);
            }
        }
      }
      return islands;
    }
};