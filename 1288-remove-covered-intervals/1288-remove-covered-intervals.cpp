class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=(int)(intervals.size());
            vector<int> visited(n);
            for(int i=0;i<n;++i){
                            int x_i=intervals[i][0],y_i=intervals[i][1];
                    for(int j=0;j<n;++j){
                            if(i==j) continue;
                            int x_j=intervals[j][0],y_j=intervals[j][1];
                            if(x_j>=x_i&&y_j<=y_i){
                                    visited[j]|=1;
                            }
                    }
            }
            int ans=0;
            for(int i=0;i<n;++i) if(!visited[i]) ans++;
            return ans;
    }
};