class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=(int)(arr.size());
        if(n<=1) return n;
        sort(arr.begin(),arr.end());
        int ans=1;
        int cnt=1;
        for(int i=1;i<n;++i){
            if(arr[i]==arr[i-1]) continue;
            if(arr[i]!=arr[i-1]+1){
                ans=max(ans,cnt);
                cnt=1;
            }
            else cnt++;
        }
        ans=max(ans,cnt);
        return ans;
    }
};