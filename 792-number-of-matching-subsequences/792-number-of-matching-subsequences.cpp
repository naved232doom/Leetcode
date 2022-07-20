class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& W) {
        int nw=(int)(W.size());
        vector<vector<pair<int,int>>> pos(26);
        int n=(int)(s.size());
        for(int i=0;i<nw;++i){
            int c=W[i][0];
            pos[c-'a'].push_back({i,0});
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int c=s[i]-'a';
            auto pos_tmp=pos[c];
            pos[c].clear();
            for(auto it:pos_tmp){
                int pos_idx=it.second;
                int idx=it.first;
                int next_idx= pos_idx+1;
                // cout<<"next_idx: "<<next_idx<<endl;
                // cout<<"W[idx]: "<<W[idx]<<endl;
                // cout<<"W[idx].size(): "<<W[idx].size()<<endl;
                if(pos_idx +1 >=(int)(W[idx].size())){
                    ans++;
                    continue;
                }
                
                assert(next_idx < W[idx].size());
                int c_next= W[idx][next_idx]-'a';
                //cout<<"c_next: "<<c_next<<endl;
                pos[c_next].push_back({idx,next_idx});
            }
        }
       
        return ans;
    }
};