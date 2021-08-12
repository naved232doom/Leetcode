class TreeAncestor {
public:
        vector<vector<int>> up;
        vector<int> depth;
        const int LOG=21;
    TreeAncestor(int n, vector<int>& parent) {
        up=vector<vector<int>> (n+1,vector<int>(LOG));
        depth=vector<int> (n+1);
        for(int i=0;i<n;++i){
                up[i][0]=parent[i];
        }    
        for(int i=1;i<LOG;++i){
                for(int j=0;j<n;++j){
                        if(up[j][i-1]!=-1){
                                up[j][i]=up[up[j][i-1]][i-1];
                        }
                        else up[j][i]=-1;
                }
        }    
    }   
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;++i){
                if(k&(1<<i)){
                        node=up[node][i];
                        if(node==-1) return -1;
                }
        }
            return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */