class Solution {
    private:
    void dfs(int u,vector<int> &visited,vector<vector<int>> &M){
        visited[u]=1;
        int n=(M.size());
        for(int i=0;i<n;++i){
            if(M[u][i]&&!visited[i]){
                dfs(i,visited,M);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=(int)(M.size());
        
        vector<int> visited(n);
        int ans=0;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ans++;
                dfs(i,visited,M);
            }
        }
        
        return ans;
    }
};