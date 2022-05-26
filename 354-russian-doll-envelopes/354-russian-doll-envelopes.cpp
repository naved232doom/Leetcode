class Solution {
    
public:
    
    int maxEnvelopes(vector<vector<int>>& e) {
        int n=(int)(e.size());
       // auto custom_comp= 
sort(e.begin(),e.end(),[](vector<int> &e1,vector<int> &e2){
            if(e1[0]!=e2[0]) return e1[0]<e2[0];
            return e1[1]>e2[1];
        });
        vector<int> L;
        // 1,3 3,5 6,8 6,7 8,4 9,5
        // 3 5 8
        for(int i=0;i<n;++i){
            int r_here=e[i][1];
            if(L.empty()){
                L.push_back(r_here);
            }
            else{
                auto it= lower_bound(L.begin(),L.end(),r_here);
                if(it==L.end()) {
                    L.push_back(r_here);
                    continue;
                }
                auto idx=lower_bound(L.begin(),L.end(),r_here)-L.begin();
                L[idx]=r_here;
            }
        }
        
        
        return (int)(L.size());
    }
};