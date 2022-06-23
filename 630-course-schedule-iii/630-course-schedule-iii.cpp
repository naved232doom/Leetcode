class Solution {
public:
    int scheduleCourse(vector<vector<int>>& C) {
        sort(C.begin(),C.end(),[](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
            int s_here=0;
        priority_queue<int> pq;
        int ans=0;
        for(auto e:C){
            int duration=e[0],deadline=e[1];
            pq.push(duration);
            s_here+=duration;
            if(s_here>deadline){
               // assert(!pq.empty());
                auto r= pq.top();
                pq.pop();
                s_here-=r;
            }
            ans=max(ans,(int)(pq.size()));
            
        }
        return ans;
    }
};