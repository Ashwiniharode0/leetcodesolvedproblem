class Solution {
public:
    typedef long long l1;
    const int LARGE_VALUE =2e9;
    typedef pair<int,int> P;

    l1 dijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest){

        unordered_map<l1, vector<pair<l1, l1>>> adj;

        for(vector<int> & edge:edges){
            if(edge[2]!=-1){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];

                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }

        priority_queue<P, vector<P>,greater<P>> pq;

        vector<l1> result(n,INT_MAX);
        vector<bool> visited(n,false);

        result[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            l1 currDist=pq.top().first;
            l1 currNode=pq.top().second;

            pq.pop();

            if(visited[currNode] == true){
                continue;
            }

            visited[currNode] = true;

            for(auto &[nbr,wt]:adj[currNode]){

                if(result[nbr] > currDist + wt){

                    result[nbr] = currDist + wt;

                    pq.push({result[nbr],nbr});
                }
            }
        }

        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        l1 currShortestDist = dijkstraAlgo(edges,n,source,destination);

        if(currShortestDist < target){
            return {};
        }

        bool matchedTarget= (currShortestDist == target);

        for(vector<int>& edge:edges){
            if(edge[2]==-1){
                edge[2] =(matchedTarget == true) ? LARGE_VALUE : 1;

                if(matchedTarget !=true){
                    l1 newShortestDist = dijkstraAlgo(edges,n,source,destination);

                    if(newShortestDist<=target){
                        matchedTarget=true;
                        edge[2]+=(target-newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false){
            return{};
        }

        return edges;
    }
};