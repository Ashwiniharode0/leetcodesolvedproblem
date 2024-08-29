class Solution {
public:
vector<int> parent;
vector<int>rank;
int n;

    int find(int i){
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }

    void Union(int i,int j){

        int parent_i=find(i);
        int parent_j=find(j);

        if(parent_i!=parent_j){

            if(rank[parent_i]>rank[parent_j]){
                parent[parent_j]=parent_i;
            }else if(rank[parent_i]<rank[parent_j]){
                parent[parent_i]=parent_j;
            }else{
                parent[parent_i]=parent_j;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1] ==stones[j][1]){
                    Union(i,j);
                }
            }
        }

        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
        return n-groups;
    }
};