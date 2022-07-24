class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int n=(int)(M.size());
        int m=(int)(M[0].size());
        reverse(M.begin(),M.end());
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(M[i][j],M[j][i]);
            }
        }
    }
};