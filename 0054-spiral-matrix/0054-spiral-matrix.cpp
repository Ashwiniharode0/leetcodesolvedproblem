class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int row= matrix.size();
        int col = matrix[0].size();

        int left = 0, lastRow=row-1;
        int top = 0, lastCol = col-1;
        int id =0;

        while(top<=lastRow && left <=lastCol){
        if(id == 0){
            for(int i=left;i<=lastCol;i++){
                res.push_back(matrix[top][i]);
            }
            top++; 
        }
        else if(id == 1){
            for(int i=top;i<=lastRow;i++){
                res.push_back(matrix[i][lastCol]);
            }
            lastCol--;
        }

        else if(id == 2){
            for(int i=lastCol;i>=left;i--){
                res.push_back(matrix[lastRow][i]);
            }
            lastRow--;
        }
        
        else if(id == 3){
                for(int i=lastRow;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        
            id = (id+1)%4;
        }
        return res;
    }
};