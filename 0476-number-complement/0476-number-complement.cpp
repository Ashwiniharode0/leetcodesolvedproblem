class Solution {
public:
    int findComplement(int num) {
        int numBits=(int)(log2(num))+1;

        for(int i=0;i<numBits;i++){

            num = num^(1<<i);
        }
        return num;
    }
};