class Solution {
public:
    int getLucky(string s, int k) {
        string strNum;
        for(int i=0;i<s.length();i++){
            strNum+=to_string((s[i]-'a')+1);
        }

        int sum=0;
        while(k--){
            sum=0;
            for(int i=0;i<strNum.length();i++){
                sum+=strNum[i]-'0';
            }
            strNum = to_string(sum);
        }
        return stoi(strNum);
    }
};