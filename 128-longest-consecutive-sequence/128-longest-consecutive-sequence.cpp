class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=(int)(arr.size());
        if(n<=1) return n;
        //sort(arr.begin(),arr.end());
        vector<vector<int>> adj(n);
        map<int,int> mp;
        for(int i=0;i<n;++i) mp[arr[i]]=i;
        vector<int> deg(n);
        for(int i=0;i<n;++i){
            if(mp.find(arr[i]+1)!=mp.end()){
                adj[i].push_back(mp[arr[i]+1]);
                deg[mp[arr[i]+1]]++;
            }
        }
        queue<int> q;
        vector<int> dp(n);
        for(int i=0;i<n;++i){
            if(deg[i]==0) {
                q.push(i);
                dp[i]=1;
            }
        }
        while(!q.empty()){
            auto u=q.front();q.pop();
            
            for(int v:adj[u]){
                deg[v]--;
                if(deg[v]<=1){
                    dp[v]=max(dp[v],dp[u]+1);
                    q.push(v);
                }
            }
        }
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};