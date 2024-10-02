class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>vc=arr;
        sort(vc.begin(),vc.end());
        unordered_map<int,int>mp;
        int i=0;
        int rank=1;
        while(i<arr.size()){
            if(i==0){}
            else if(vc[i] == vc[i-1]){}
            else rank++;
            mp[vc[i]]=rank;
            i++;
        }

        for(auto &num:arr){
            num=mp[num];
        }
        return arr;
    }
};