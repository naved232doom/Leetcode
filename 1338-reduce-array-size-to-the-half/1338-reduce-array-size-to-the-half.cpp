class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        int n=(int)(arr.size());
        for(auto &a:arr) mp[a]++;
        vector<array<int,2>> pos;
        for(auto &it:mp){
            pos.push_back({it.second,it.first});
        }
        sort(pos.rbegin(),pos.rend());;
        int ans=0;
        int cnt=0;
        for(auto &it:pos){
            cnt+=it[0];
            ans++;
            if(cnt>=n/2) break;
        }
        return ans;
    }
};