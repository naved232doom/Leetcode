class Solution {
public:
    typedef long long ll;
    int minMoves2(vector<int>& nums) {
        int n=(int)(nums.size());
        const ll INF= (int)(1e10);
        ll ans=INF;
        ll S=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            S+=nums[i];
        }
        //-5 -4 -3 0 1 2 3    
        for(int i=0,S2=0;i<n;++i){
            S-=nums[i];
            ll l =i,r=n-i-1;
            ll ans_here= abs(S2-(l*nums[i])) + abs(S-(r*nums[i]));
            ans=min(ans,ans_here);
            S2+=nums[i];
        }
        return ans;
    }
};