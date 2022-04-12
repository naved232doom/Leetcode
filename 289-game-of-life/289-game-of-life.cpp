class Solution {
    private:
    bool is_valid(int x,int y,int n,int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=(int)(board.size());
        int m=(int)(board[0].size());
        vector<int> dx={-1,1,0,0,-1,-1,1,1};
        vector<int> dy={0,0,-1,1,-1,+1,1,-1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int cnt=0;
                for(int k=0;k<8;++k){
                    int x=i+dx[k],y=j+dy[k];
                    if(is_valid(x,y,n,m)){
                        if(board[x][y]>0){
                            cnt++;
                        }
                    }
                }
                if(board[i][j]==1&&cnt<2){
                    board[i][j]=2;
                }
                else if(board[i][j]==1&&cnt>3){
                    board[i][j]=2;
                }
                else if(board[i][j]==0&&cnt==3){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==2) board[i][j]=0;
                if(board[i][j]==-1) board[i][j]=1;
            }
        }
        
        
    }
};