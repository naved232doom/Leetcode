class Solution {
        private:
        //  struct P{
        //         int x,int y;
        //         P(int x,int y){
        //                 this->x=x;
        //                 this->y=y;
        //         }
        // }
        vector<int> getState(vector<vector<int>> &mat,int n,int m){
                vector<int> S;
                
                for(int i=0;i<n;++i){
                        for(int j=0;j<m;++j){
                                int cur=((i)*m+j+1)*mat[i][j];
                                S.push_back(cur);
                        }
                }
                return S;
        }
        bool isValid(int x,int y,int n,int m){
                return x>=0&&y>=0&&x<n&&y<m;
        }
        vector<vector<int>> flipBit(vector<vector<int>> M,int i,int j,int n,int m){
                   auto ans=M;
                   vector<int> dx={-1,1,0,0,0};     
                   vector<int> dy={0,0,-1,1,0};
                for(int k=0;k<5;++k){
                        int nxtX=dx[k]+i;
                        int nxtY=dy[k]+j;
                        if(isValid(nxtX,nxtY, n, m)){
                                M[nxtX][nxtY]^=1;
                                
                        }
                }
                return M;
        }
        bool checkZeroState(vector<vector<int>> &mat,int n,int m){
                bool ok=1;
                for(int i=0;i<n;++i){
                        for(int j=0;j<m;++j){
                                 if(mat[i][j]==1) return 0;
                        }
                }
                return 1;
        }
       int bfs(vector<vector<int>> &mat){
                queue<vector<vector<int>>> Q;
                queue<int> QP;
               QP.push(0);
                int n=(int)(mat.size()),m=(int)(mat[0].size());
               if(checkZeroState(mat,n,m)) return 0;
               int ans=INT_MAX;
                map<vector<int>,int> states;
                // 1 2 3  1 0 1  1 0 3 0 5 6 
                // 4 5 6  0 1 1
                auto curState=getState(mat,n,m);
                Q.push(mat);
                states[curState]=1;
                while(!Q.empty()){
                        vector<vector<int>> matNow=Q.front(); Q.pop();
                        int turns=QP.front(); QP.pop();
                        for(int i=0;i<n;++i){
                                for(int j=0;j<m;++j){
                                        // if toggling the bit produces 0 state
                                        auto flippedState=flipBit(matNow,i,j,n,m);
                                        if(checkZeroState(flippedState,n,m)) {
                                                ans=min(ans,turns+1);
                                                continue;
                                        }
                                        auto F=getState(flippedState,n,m);
                                        if(states.find(F)!=states.end()) continue;
                                        states[F]=1;
                                        Q.push(flippedState);
                                        QP.push(turns+1);
                                }
                        }        
                }
                return ans;
                
        }
       
public:
    int minFlips(vector<vector<int>>& mat) {
        // we store the states which have been used 
            // we check if by flipping any element  we can get the desired state
           int ans= bfs(mat);
            
            if(ans==INT_MAX) return -1;
            return ans;
    }
};