class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=(int)(arr.size());
        const int INF=1e9;
        vector<int> dp(n,-INF);
        vector<array<int,2>> pos;
        for(int i=0;i<n;++i){
            pos.push_back({arr[i],i});
            
        }
        
        sort(pos.begin(),pos.end());
        for(int i=0;i<n;++i){
            auto cur=pos[i];
            auto u=cur[0];
            auto idx=cur[1];
        priority_queue<int,vector<int>,greater<int>> pq;
            pq.push(idx);
            dp[idx]=max(dp[idx],1);
            auto v=idx;
            //cout<<v<<endl;
            for(int j=1;j<=d&&v+j<n;++j){
                    if(arr[v+j]>=arr[v]) break;
                // cout<<"v "<<v<<endl;
                // cout<<"d "<<d<<endl;
                // cout<<"v+d "<<v+d<<endl;
                // cout<<"dp[v+d] "<<dp[v+d]<<endl;
                    dp[v]=max(dp[v],1+dp[v+j]);
            }
            for(int j=1;j<=d&&v-j>=0;++j){
                    if(arr[v-j]>=arr[v]) break;
                    dp[v]=max(dp[v],1+dp[v-j]);
            }
            //cout<<dp[idx]<<endl;
        }       
        
        return *max_element(dp.begin(),dp.end());
    }
};