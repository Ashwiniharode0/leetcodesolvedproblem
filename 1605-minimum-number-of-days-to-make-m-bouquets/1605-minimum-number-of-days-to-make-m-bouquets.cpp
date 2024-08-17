class Solution {
public:
    bool possible(vector<int>& bloomDay,int days, int m, int k){
            int cnt=0;
            int nofBouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days) cnt++;
            else{
                nofBouquet+=cnt/k;
                cnt=0;
            }
        }
        nofBouquet+=cnt/k;
        if(nofBouquet>=m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int MIN=INT_MAX;
        int MAX=INT_MIN;

        for(int i=0;i<bloomDay.size(); i++){
            MIN=min(MIN,bloomDay[i]);
            MAX=max(MAX,bloomDay[i]);
        }

        int start=MIN,end=MAX;
        
        long long int val =m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;

        while(start<=end){
            int mid=(start+end)/2;
            if(possible(bloomDay,mid,m,k)==true){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};