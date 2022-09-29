class Solution {
public:
    struct DSU {
    int n;
    // uf[x] = parent of x or negative size of component
    vector<int> uf;
    DSU(int n): n(n) {
        uf.assign(n, -1);
    }
 
    int find(int x) {
        return uf[x] < 0 ? x : (uf[x] = find(uf[x]));
    }
 
    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return 0;
 
        if (uf[yr] < uf[xr]) {
            uf[yr] += uf[xr];
            uf[xr] = yr;
        } else {
            uf[xr] += uf[yr];
            uf[yr] = xr;
        }
 
        return 1;
    }
 
    int get_size(int x) {
        return -uf[find(x)];
    }
 
//     vector<vi> get_comps() {
//         vector<vi> comps;
 
//         vi comp_id(n, -1);
//         for (int i = 0; i < n; ++i) {
//             int root = find(i);
//             if (comp_id[root] == -1) {
//                 comp_id[root] = comps.size();
//                 comps.push_back(vi());
//             }
 
//             comps[comp_id[root]].push_back(i);
//         }
 
//         return comps;
//     }
};
    bool equationsPossible(vector<string>& s) {
        int n=(int)(s.size());
        
        map<char,int> mp;
        int cnt=0;
        sort(s.begin(),s.end(),[](string &a,string &b){
            return a[1]=='='&&b[1]!='=';
            return false;
        });
        for(auto &c:s){
            if(mp.find(c[0])==mp.end()){
                mp[c[0]]=cnt++;
            } 
            if(mp.find(c.back())==mp.end()){
                mp[c.back()]=cnt++;
            }
        }
        int len=(int)(mp.size());
        DSU dsu(len);
        for(auto &c:s){
            if(c[1]=='=')
            dsu.merge(mp[c[0]],mp[c.back()]);
            else
                if(dsu.find(mp[c[0]]) == dsu.find(mp[c.back()])) return false;
        }
        
        return true;
    }
};