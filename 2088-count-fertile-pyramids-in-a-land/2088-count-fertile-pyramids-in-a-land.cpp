class Solution {
    private:
    bool valid(int x,int y,int n,int m){
        return x>=0&&y>=0&&x<m&&y<m;
    }
    int go(int x,int y,vector<vector<int>> &g,vector<vector<int>> &pref){
        int ans=0;
        int l=y-1,r=y+1;
        int n=(int)(g.size());
        int m=(int)(g[0].size());
        for(int i=x+1;i<n;++i){
            if(!valid(l,r,n,m)) break;
            int len=r-l+1;
            int here=0;
            if(l-1>=0)
            here=pref[i][r]-pref[i][l-1];
            else here=pref[i][r];
            if(here<len) break;
            ans++;
            l--;r++;
        }
        
        
        return ans;
    }
    int go2(int x,int y,vector<vector<int>> &g,vector<vector<int>> &pref){
        int ans=0;
        int l=y-1,r=y+1;
        int n=(int)(g.size());
        int m=(int)(g[0].size());
        for(int i=x-1;i>=0;--i){
            if(!valid(l,r,n,m)) break;
            int len=r-l+1;
            int here=0;
            if(l-1>=0)
            here=pref[i][r]-pref[i][l-1];
            else here=pref[i][r];
            if(here<len) break;
            ans++;
            l--;r++;
        }
        
        
        return ans;
    }
public:
    int countPyramids(vector<vector<int>>& g) {
        int n=(int)(g.size());
        int m=(int)(g[0].size());
        int ans=0;
        auto pref=g;
        for(int i=0;i<n;++i){
            for(int j=0,it=0;j<m;++j){
                pref[i][j]+=it;
                it=pref[i][j];
            }
//             for(int j=0;j<m;++j){
                
//             }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(g[i][j]==0) continue;
                ans+=go(i,j,g,pref);
                ans+=go2(i,j,g,pref);
            }
        }
        
        return ans;
    }
};