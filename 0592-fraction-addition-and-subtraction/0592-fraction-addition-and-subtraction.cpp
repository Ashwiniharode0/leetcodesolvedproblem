class Solution {
public:
    string fractionAddition(string expre) {
        int n=expre.size();
        int nume=0;
        int deno=1;
        int i=0;
        while(i<n){
            int currNume=0;
            int currDeno=0;

            bool isNeg=(expre[i]=='-');

            if(expre[i]=='+' ||expre[i]=='-'){
                i++;
            }

            while(i<n && isdigit(expre[i])){
                int val=expre[i]-'0';
                currNume=(currNume*10)+val;
                i++;
            }
            i++;
            if(isNeg == true){
                currNume*=-1;
            }

            while(i<n && isdigit(expre[i])){
                int val=expre[i]-'0';
                currDeno=(currDeno*10)+val;
                i++;
            }

            nume = nume*currDeno+deno*currNume;
            deno = deno*currDeno;
        }

        int GCD = abs(__gcd(nume,deno));

        nume/=GCD;
        deno/=GCD;
        return to_string(nume) + "/" + to_string(deno);
    }
};