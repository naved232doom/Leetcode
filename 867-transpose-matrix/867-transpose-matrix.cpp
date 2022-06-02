class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mt) {
        int n=(int)(mt.size());
        int m=(int)(mt[0].size());
    if(n==m){
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                swap(mt[i][j],mt[j][i]);
            }
        }
        return mt;
    }
        
       vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans[j][i]=mt[i][j];
            }
        }
        return ans;
    }
};