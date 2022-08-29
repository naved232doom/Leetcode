class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=(int)(mat.size());
        int m=(int)(mat[0].size());
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]) continue;
                vector<int> pos;
                int x=i,y=j;
                for(;x>=0&&x<n&&y>=0&&y<m;x++,++y){
                    pos.push_back(mat[x][y]);
                    vis[x][y]=1;
                }
                sort(pos.begin(),pos.end());
                x=i,y=j;
                for(int it=0;x>=0&&x<n&&y>=0&&y<m;x++,++y,++it){
                    mat[x][y]=pos[it];
                }
            }
        }
        return mat;
    }
};