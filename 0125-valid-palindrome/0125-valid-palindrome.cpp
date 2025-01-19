class Solution {
public:

    bool isAlphanumeric(char ch){
        if((ch >='0' && ch<='9') ||tolower(ch)>='a' && tolower(ch) <='z'){
            return true;
        }
        return false;
    }

    bool isPalindrome(string str) {
        int st=0 , end= str.length()-1;
        while(st<=end){
            if(!isAlphanumeric(str[st]))
            {
                st++;
                continue;
            } 
            if(!isAlphanumeric(str[end])){
                end--;
                continue;
            } 
            if(tolower(str[st]) != tolower(str[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};