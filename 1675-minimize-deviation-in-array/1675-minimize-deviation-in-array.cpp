class Solution {
public:
    int minimumDeviation(vector<int>& arr) {
        int n=(int)(arr.size());
        priority_queue<int> pq;
        int MN=INT_MAX;
        for(int i=0;i<n;++i){
           arr[i]= arr[i] % 2 ? arr[i]*2:arr[i];
            pq.push(arr[i]);
            MN=min(MN,arr[i]);
        }
        // 2 2 4 6
        // 2 2 3 4
        // 2 2 2 3
        int ans=pq.top()-MN;
        while(pq.top()%2==0){
            int here=pq.top();
            pq.pop();
            ans=min(ans,here-MN);
            MN=min(MN,here/2);
            pq.push(here/2);
        }
        ans=min(ans,pq.top()-MN);
        return ans;
    }
};