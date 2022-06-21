class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        int n = (int)(arr.size());
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;++i){
            int dif_here=arr[i]-arr[i-1];
            if(dif_here>0)
            pq.push(dif_here);
            if(!pq.empty()){
                int size_pq=(int)(pq.size());
                if(size_pq<=ladders) continue;
                int lowest= pq.top();
                pq.pop();
                if(bricks-lowest<0){
                    return i-1;
                }
                bricks-=lowest;
            }
        }
        return n-1;
    }
};