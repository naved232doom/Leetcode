class Solution {
public:
     static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]>p2[0];
        else return p1[1]<p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& X) {
        int n=(int)(X.size());
        vector<array<int,3>> P;
        for(int i=0;i<n;++i){
            P.push_back({X[i][0],X[i][1],i});
        }
        sort(P.begin(),P.end(),[](array<int,3> &a,array<int,3> &b){
            if(a[0]!=b[0]) return a[0]>b[0];
            return a[1]<b[1];
        });
        // 7,0 7,1
        vector<vector<int>> ans;
        vector<int> ans_idx;
        for(int i=0;i<n;++i){
            int idx= P[i][1];
            vector<int> pref;
            assert(idx<=(int)(ans_idx.size()));
            for(int j=0;j<idx;++j){
                pref.push_back(ans_idx[j]);
            }
            pref.push_back(P[i][2]);
            for(int j=idx;j<(int)ans_idx.size();++j){
                pref.push_back(ans_idx[j]);
            }
            ans_idx.clear();
            for(auto x:pref) ans_idx.push_back(x);
        }
        for(int i=0;i<n;++i){
            ans.push_back(X[ans_idx[i]]);
        }
        return ans;
        
      
    }
};