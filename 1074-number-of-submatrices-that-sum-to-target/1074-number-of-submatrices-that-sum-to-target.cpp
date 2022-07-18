class Solution {
public:
    int get_sum(int x1,int y1,int x2,int y2,vector<vector<int>> &pref){
        int sum=0;
        sum=pref[x2+1][y2+1];
        sum-=(pref[x2+1][y1]+pref[x1][y2+1]); 
        sum+=pref[x1][y1];
        // pref[2][2] - (pref[1][1]+pref[0][2]) +pref[0][1]
        // 0 - ()
        return sum;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& mt, int T) {
        int n=(int)(mt.size());
        int m=(int)(mt[0].size());
        vector<vector<int>> pref(n+1,vector<int>(m+1));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int s_here=pref[i][j+1]+pref[i+1][j]-pref[i][j]+mt[i][j];
                pref[i+1][j+1]=s_here;
            }
        }

        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                for(int I=i;I<n;++I){
                    for(int J=j;J<m;++J){
                       
                        if(get_sum(i,j,I,J,pref)==T) {
                            ans++;
                        }
                    }
                }
            }
        }
        
        return ans;
        
    }
};