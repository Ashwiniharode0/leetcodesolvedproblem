class Solution {
public:

    void solve(int currNum, int n ,vector<int> &result){
        if(currNum>n){
            return;
        }
        
        result.push_back(currNum);

        for(int i=0;i<=9;i++){

            int newNum =currNum*10+i;

            if(newNum >n){
                return;
            }
            solve(newNum,n,result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int num=1;num<=9;num++){
            solve(num,n,result);
        }
        return result;
    }
};