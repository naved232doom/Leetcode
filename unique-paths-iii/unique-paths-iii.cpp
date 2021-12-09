class Solution {
        private:
        int ans=0;
        typedef pair<int,int> pii;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        bool isValid(int x,int y,int n,int m){
                return x>=0&&x<n&&y>=0&&y<m;
                return 0;
        }
void go(vector<vector<int>> &grid,vector<vector<int>> &visited,pii u,pii p,int &nonObstacles,int N){
                if(N>nonObstacles) return;
                for(int i=0;i<4;++i){
                        int nextX=u.first+dx[i],nextY=u.second+dy[i];
                        if(nextX==p.first && nextY==p.second) continue;
                        if(isValid(nextX,nextY,grid.size(),grid[0].size())){
                                if(grid[nextX][nextY]==2){
                                        if(N+1==nonObstacles) ans++;
                                }
                        if(grid[nextX][nextY]==0&&!visited[nextX][nextY]){
                                visited[nextX][nextY]=1;
                                go(grid,visited,{nextX,nextY},u,nonObstacles,N+1);
                                visited[nextX][nextY]=0;
                                }
                        }
                }
        }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
                pii S;
            int n=(int)(grid.size());
            int m=(int)(grid[0].size());
            int nonObstacles=0;
            for(int i=0;i<n;++i){
                    for(int j=0;j<m;++j){
                            if(grid[i][j]==1){
                                    S.first=i,S.second=j;
                            }
                           
                            if(grid[i][j]!=-1) nonObstacles++;
                    }
            }
           vector<vector<int>> visited(n,vector<int>(m));
            visited[S.first][S.second]=1;
            go(grid,visited,S,{-1,-1},nonObstacles,1);
            return ans;
    }
};