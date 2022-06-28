class Solution {
public:
    int minDeletions(string s) {
        int n=(int)(s.length());
        vector<int> arr;
        vector<int> f(26);
        for(int i=0;i<n;++i){
            f[s[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(!f[i]) continue;
            arr.push_back(f[i]);
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        // 1 2 4 6 7 7
        priority_queue<int> pq;
        int mn=0;
        set<int> st;
        for(int i=0;i<(int)(arr.size());++i){
            while(mn<arr[i]){
                pq.push(mn);
                mn++;
            }
            if(!st.count(arr[i])){
                st.insert(arr[i]);
                mn=max(arr[i]+1,mn);
            }
            else{
                //assert(!pq.empty());
                if(pq.empty()){
                    ans+=arr[i];
                    continue;
                }
                ans+=(arr[i]-pq.top());
                st.insert(pq.top());
                pq.pop();
            }
        }
        return ans;
    }
};