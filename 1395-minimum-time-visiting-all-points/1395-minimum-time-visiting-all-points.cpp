class Solution {
public:
    int toTime(vector<int> &from, vector<int> &to){

        int res1 = abs(from[0]-to[0]);
        int res2 = abs(from[1]-to[1]);

        return max(res1, res2);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=1;i<points.size();i++){
            time += toTime(points[i-1], points[i]);
        }
        return time;
    }
};